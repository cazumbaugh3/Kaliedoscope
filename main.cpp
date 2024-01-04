#include <iostream>
#include "parser.h"
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

std::unique_ptr<llvm::LLVMContext> theContext;
std::unique_ptr<llvm::Module> theModule;
std::unique_ptr<llvm::IRBuilder<>> builder;
std::map<std::string, llvm::Value*> namedValues;

static void initializeModule() {
    theContext = std::make_unique<llvm::LLVMContext>();
    theModule = std::make_unique<llvm::Module>("my cool jit", *theContext);
    builder = std::make_unique<llvm::IRBuilder<>>(*theContext);
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
        fprintf(stderr, "Error occured: current token %s\n", identifierString.c_str());
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
    binopPrecedence['<'] = 10;
    binopPrecedence['+'] = 20;
    binopPrecedence['-'] = 30;
    binopPrecedence['*'] = 40;

    fprintf(stderr, "ready> ");
    getNextTok();

    initializeModule();

    mainLoop();

    theModule->print(llvm::errs(), nullptr);
    return 0;
}
