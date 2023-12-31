//
// Created by Chuck Zumbaugh on 12/30/23.
//

#include "BinaryExprAST.h"

BinaryExprAST::BinaryExprAST(char op, std::unique_ptr<ExprAST> LHS, std::unique_ptr<ExprAST> RHS):
op(op), LHS(std::move(LHS)), RHS(std::move(RHS)) {};