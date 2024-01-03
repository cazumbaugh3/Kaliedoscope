//
// Created by Chuck Zumbaugh on 12/30/23.
//

#ifndef KALIEDOSCOPE_NUMBEREXPRAST_H
#define KALIEDOSCOPE_NUMBEREXPRAST_H
#include "ExprAST.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/Constants.h"

class NumberExprAST: public ExprAST {
    double val;
public:
    NumberExprAST(double val);
    llvm::Value* codegen() override;
};


#endif //KALIEDOSCOPE_NUMBEREXPRAST_H
