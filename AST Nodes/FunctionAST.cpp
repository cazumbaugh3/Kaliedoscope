//
// Created by Chuck Zumbaugh on 12/30/23.
//

#include "FunctionAST.h"
#include "../llvm_statics.h"
#include "../error/error.h"
#include "../LLVMPasses/passAndAnalysisManagers.h"

FunctionAST::FunctionAST(std::unique_ptr<PrototypeAST> proto, std::unique_ptr<ExprAST> body):
proto(std::move(proto)), body(std::move(body)) {};
llvm::Function* FunctionAST::codegen() {
    // First, check for an existing function from a previous extern declaration. Search theModule's symbol
    // table for an existing version.

    // TODO: Need to validate the existing functions signature against the definition's own prototype
    llvm::Function* theFunction = theModule->getFunction(proto->getName());

    // If an existing version is not found, codegen one from the prototype
    if (!theFunction) {
        theFunction = proto->codegen();
    }
    if (!theFunction) {
        return nullptr;
    }
    // Assert that the function is empty (has no body) before starting
    if (!theFunction->empty()) {
        return (llvm::Function*)logErrorV("Function cannot be redefined");
    }

    // Create a basic block to start insertion into
    llvm::BasicBlock* basicBlock = llvm::BasicBlock::Create(*theContext, "entry", theFunction);
    // Insert new instructions at the end of the basic block
    builder->SetInsertPoint(basicBlock);

    // Record the function's arguments in the namedValues map so they are accessible to VariableExprAST nodes
    namedValues.clear();
    for (auto& arg : theFunction->args()) {
        namedValues[std::string(arg.getName())] = &arg;
    }
    // Once insertion point is set and namedValues map has been populated, call the codegen() method for the root
    // expression of the function.
    if (llvm::Value* retVal = body->codegen()) {
        // Finish the function by creating a RetVal, which completes the function by returning control to the caller.
        builder->CreateRet(retVal);
        // Validate the generated code, checking for consistency
        llvm::verifyFunction(*theFunction);

        theFPM->run(*theFunction, *theFAM);
        // Return the completed, verified function
        return theFunction;
    }

    // Error when rendering the body, remove the function. This deletes it from the symbol table and lets the
    // user redefine it. If not deleted, it will live in the symbol table with a body, preventing future redefinition.
    theFunction->eraseFromParent();
    return nullptr;
}