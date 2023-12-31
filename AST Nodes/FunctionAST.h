//
// Created by Chuck Zumbaugh on 12/30/23.
//

#ifndef KALIEDOSCOPE_FUNCTIONAST_H
#define KALIEDOSCOPE_FUNCTIONAST_H
#include <memory>
#include "PrototypeAST.h"
#include "ExprAST.h"

class FunctionAST: public ExprAST {
std::unique_ptr<PrototypeAST> proto;
std::unique_ptr<ExprAST> body;

public:
    FunctionAST(std::unique_ptr<PrototypeAST> proto, std::unique_ptr<ExprAST> body);
};


#endif //KALIEDOSCOPE_FUNCTIONAST_H
