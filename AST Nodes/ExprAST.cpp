//
// Created by Chuck Zumbaugh on 12/30/23.
//

#include "ExprAST.h"

ExprAST::~ExprAST() = default;

llvm::Value *ExprAST::codegen() {
    return nullptr;
};