//
// Created by Chuck Zumbaugh on 12/30/23.
//

#ifndef KALIEDOSCOPE_BINARYEXPRAST_H
#define KALIEDOSCOPE_BINARYEXPRAST_H
#include "ExprAST.h"
#include <memory>
#include "llvm/IR/Verifier.h"

class BinaryExprAST: public ExprAST {
char op;
std::unique_ptr<ExprAST> LHS, RHS;

public:
    BinaryExprAST(char op, std::unique_ptr<ExprAST> LHS, std::unique_ptr<ExprAST> RHS);
    llvm::Value* codegen() override;
};


#endif //KALIEDOSCOPE_BINARYEXPRAST_H
