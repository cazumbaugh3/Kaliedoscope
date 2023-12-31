//
// Created by Chuck Zumbaugh on 12/30/23.
//

#ifndef KALIEDOSCOPE_BINARYEXPRAST_H
#define KALIEDOSCOPE_BINARYEXPRAST_H
#include "ExprAST.h"
#include <memory>

class BinaryExprAST: public ExprAST {
char op;
std::unique_ptr<ExprAST> LHS, RHS;

public:
    BinaryExprAST(char op, std::unique_ptr<ExprAST> LHS, std::unique_ptr<ExprAST> RHS);
};


#endif //KALIEDOSCOPE_BINARYEXPRAST_H
