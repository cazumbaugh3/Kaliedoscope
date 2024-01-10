//
// Created by Chuck Zumbaugh on 12/30/23.
//

#include "VariableExprAST.h"
#include "../llvm_statics.h"
#include "../error/error.h"
#include <string>

VariableExprAST::VariableExprAST(const std::string &name): name(name) {};
llvm::Value* VariableExprAST::codegen() {
    llvm::Value* v = namedValues[name];
    if (!v) {
        logErrorV("Unknown variable name");
    }
    return v;
}