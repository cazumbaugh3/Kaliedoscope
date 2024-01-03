//
// Created by Chuck Zumbaugh on 12/30/23.
//

#ifndef KALIEDOSCOPE_CALLEXPRAST_H
#define KALIEDOSCOPE_CALLEXPRAST_H
#include <string>
#include <vector>
#include "ExprAST.h"

class CallExprAST: public ExprAST {
std::string callee;
std::vector<std::unique_ptr<ExprAST>> args;

public:
    CallExprAST(const std::string &callee, std::vector<std::unique_ptr<ExprAST>> args);
    llvm::Value* codegen() override;
};


#endif //KALIEDOSCOPE_CALLEXPRAST_H
