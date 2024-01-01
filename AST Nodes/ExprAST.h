//
// Created by Chuck Zumbaugh on 12/30/23.
//

#ifndef KALIEDOSCOPE_EXPRAST_H
#define KALIEDOSCOPE_EXPRAST_H
#include "llvm/IR/Verifier.h"

class ExprAST {
public:
    virtual ~ ExprAST();
    virtual llvm::Value* codegen();
};


#endif //KALIEDOSCOPE_EXPRAST_H
