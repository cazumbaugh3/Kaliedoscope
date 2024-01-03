//
// Created by Chuck Zumbaugh on 12/30/23.
//

#include "BinaryExprAST.h"
#include "../llvm_statics.h"
#include "../error.h"

BinaryExprAST::BinaryExprAST(char op, std::unique_ptr<ExprAST> LHS, std::unique_ptr<ExprAST> RHS):
op(op), LHS(std::move(LHS)), RHS(std::move(RHS)) {};

llvm::Value* BinaryExprAST::codegen() {
    llvm::Value* L = LHS->codegen();
    llvm::Value* R = RHS->codegen();

    if (!L || !R) {
        return nullptr;
    }

    switch (op) {
        case '+':
            return builder->CreateFAdd(L, R, "addtmp");
        case '-':
            return builder->CreateFSub(L, R, "subtmp");
        case '*':
            return builder->CreateFMul(L, R, "multmp");
        case '<':
            L = builder->CreateFCmpULT(L, R, "cmptmp");
            return builder->CreateUIToFP(L, llvm::Type::getDoubleTy(*theContext), "booltmp");
        default:
            return logErrorV("invalid binary operator");
    }
}