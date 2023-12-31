//
// Created by Chuck Zumbaugh on 12/30/23.
//

#include "CallExprAST.h"

CallExprAST::CallExprAST(const std::string &callee, std::vector<std::unique_ptr<ExprAST>> args):
callee(callee), args(std::move(args)) {};