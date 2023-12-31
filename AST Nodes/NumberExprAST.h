//
// Created by Chuck Zumbaugh on 12/30/23.
//

#ifndef KALIEDOSCOPE_NUMBEREXPRAST_H
#define KALIEDOSCOPE_NUMBEREXPRAST_H
#include "ExprAST.h"

class NumberExprAST: public ExprAST {
    double val;
public:
    NumberExprAST(double val);
};


#endif //KALIEDOSCOPE_NUMBEREXPRAST_H
