//
// Created by Chuck Zumbaugh on 12/30/23.
//

#ifndef KALIEDOSCOPE_VARIABLEEXPRAST_H
#define KALIEDOSCOPE_VARIABLEEXPRAST_H
#include <string>
#include "ExprAST.h"

class VariableExprAST: public ExprAST {
std::string name;

public:
    VariableExprAST(const std::string &name);
    llvm::Value* codegen() override;
};


#endif //KALIEDOSCOPE_VARIABLEEXPRAST_H
