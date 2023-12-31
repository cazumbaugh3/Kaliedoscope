//
// Created by Chuck Zumbaugh on 12/30/23.
//

#include "FunctionAST.h"

FunctionAST::FunctionAST(std::unique_ptr<PrototypeAST> proto, std::unique_ptr<ExprAST> body):
proto(std::move(proto)), body(std::move(body)) {};