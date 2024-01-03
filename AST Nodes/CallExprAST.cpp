//
// Created by Chuck Zumbaugh on 12/30/23.
//

#include "CallExprAST.h"
#include "../llvm_statics.h"
#include "../error.h"

CallExprAST::CallExprAST(const std::string &callee, std::vector<std::unique_ptr<ExprAST>> args):
callee(callee), args(std::move(args)) {};

llvm::Value* CallExprAST::codegen() {
    // Look up the name in the global module table.
    llvm::Function* calleeF = theModule->getFunction(callee);
    if (!calleeF) {
        return logErrorV("Unknown function reference");
    }

    // If argument mismatch error
    if (calleeF->arg_size() != args.size()) {
        return logErrorV("Incorrect number of arguments passed");
    }

    std::vector<llvm::Value*> argsV;

    for (unsigned i = 0, e = args.size(); i != e; ++i) {
        argsV.push_back(args[i]->codegen());
        if (!argsV.back()) {
            return nullptr;
        }
    }
    return builder->CreateCall(calleeF, argsV, "calltmp");
}