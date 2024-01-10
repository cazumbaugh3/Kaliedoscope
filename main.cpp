#include <iostream>
#include <map>
#include "parser/parser.h"
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "JIT/KaliedoscopeJIT.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/StandardInstrumentations.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Scalar/GVN.h"
#include "llvm/Transforms/Scalar/Reassociate.h"
#include "llvm/Transforms/Scalar/SimplifyCFG.h"
#include "error/ExitOnError.h"
#include "LLVMPasses/passAndAnalysisManagers.h"

std::unique_ptr<llvm::LLVMContext> theContext;
std::unique_ptr<llvm::Module> theModule;
std::unique_ptr<llvm::IRBuilder<>> builder;
std::map<std::string, llvm::Value*> namedValues;

// Pass and analysis managers

std::unique_ptr<llvm::FunctionPassManager>  theFPM;
std::unique_ptr<llvm::LoopAnalysisManager> theLAM;
std::unique_ptr<llvm::FunctionAnalysisManager> theFAM;
std::unique_ptr<llvm::CGSCCAnalysisManager> theCGAM;
std::unique_ptr<llvm::ModuleAnalysisManager> theMAM;
std::unique_ptr<llvm::PassInstrumentationCallbacks> thePIC;
std::unique_ptr<llvm::StandardInstrumentations> theSI;
std::map<std::string, std::unique_ptr<PrototypeAST>> functionProtos;
llvm::ExitOnError exitOnError;
std::unique_ptr<llvm::orc::KaleidoscopeJIT> theJIT;

static void initializeModuleAndManagers() {
    theContext = std::make_unique<llvm::LLVMContext>();
    theModule = std::make_unique<llvm::Module>("my cool jit", *theContext);
    theModule->setDataLayout(theJIT->getDataLayout());
    builder = std::make_unique<llvm::IRBuilder<>>(*theContext);

    // Create new pass and analysis managers
    theFPM = std::make_unique<llvm::FunctionPassManager>();
    theLAM = std::make_unique<llvm::LoopAnalysisManager>();
    theFAM = std::make_unique<llvm::FunctionAnalysisManager>();
    theCGAM = std::make_unique<llvm::CGSCCAnalysisManager>();
    theMAM = std::make_unique<llvm::ModuleAnalysisManager>();
    thePIC = std::make_unique<llvm::PassInstrumentationCallbacks>();
    theSI = std::make_unique<llvm::StandardInstrumentations>(*theContext, true);
    theSI->registerCallbacks(*thePIC, theMAM.get());

    // Add LLVM transform passes
    // Do simple "peephole" optimizations and bit-twiddling optimizations.
    theFPM->addPass(llvm::InstCombinePass());
    // Reassociate expressions
    theFPM->addPass(llvm::ReassociatePass());
    // Eliminate common subexpressions
    theFPM->addPass(llvm::GVNPass());
    // Simplify the control flow graph (deletes unreachable nodes, etc.)
    theFPM->addPass(llvm::SimplifyCFGPass());

    // Register analysis passes used in these transform passes
    llvm::PassBuilder PB;
    PB.registerModuleAnalyses(*theMAM);
    PB.registerFunctionAnalyses(*theFAM);
    PB.crossRegisterProxies(*theLAM, *theFAM, *theCGAM, *theMAM);
}

void handleDefinition() {
    if (auto fnAST = parseDefinition()) {
        if (auto* fnIR = fnAST->codegen()) {
            fprintf(stderr, "Read function definition:");
            fnIR->print(llvm::errs());
            fprintf(stderr, "\n");
        }
        fprintf(stderr, "Parsed a function definition\n");
    } else {
        getNextTok();
    }
}

void handleExtern() {
    if (auto protoAST = parseExtern()) {
        if (auto* protoIR = protoAST->codegen()) {
            fprintf(stderr, "Read Extern:");
            protoIR->print(llvm::errs());
            fprintf(stderr, "\n");
        }
        fprintf(stderr, "Parsed an extern\n");
    } else {
        // Skip
        getNextTok();
    }
}

void handleTopLevelExpression() {
    if (auto fnAST = parseTopLevelExpr()) {
        if (auto* fnIR = fnAST->codegen()) {
            fprintf(stderr, "Read top-level expression:");
            fnIR->print(llvm::errs());
            fprintf(stderr, "\n");

            // Remove anonymous expression
            fnIR->removeFromParent();
        }
        fprintf(stderr, "Parsed a top-level expression\n");
    } else {
        getNextTok();
    }
}

void mainLoop() {
    while (true) {
        fprintf(stderr, "ready> ");
        switch (curTok) {
            case tok_eof:
                return;
            case ';':
                getNextTok();
                break;
            case tok_def:
                handleDefinition();
                break;
            case tok_extern:
                handleExtern();
                break;
            default:
                handleTopLevelExpression();
                break;
        }
    }
}

int main() {
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmParser();
    llvm::InitializeNativeTargetAsmPrinter();
    binopPrecedence['<'] = 10;
    binopPrecedence['+'] = 20;
    binopPrecedence['-'] = 30;
    binopPrecedence['*'] = 40;

    fprintf(stderr, "ready> ");
    getNextTok();

    theJIT = exitOnError(llvm::orc::KaleidoscopeJIT::Create());
    initializeModuleAndManagers();

    mainLoop();

    theModule->print(llvm::errs(), nullptr);
    return 0;
}
