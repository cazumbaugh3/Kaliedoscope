//
// Created by Chuck Zumbaugh on 1/2/24.
//

#ifndef KALIEDOSCOPE_ERROR_H
#define KALIEDOSCOPE_ERROR_H
#include "llvm/IR/Verifier.h"
#include "./AST Nodes/ExprAST.h"
#include "./AST Nodes//PrototypeAST.h"

std::unique_ptr<ExprAST> logError(const char* str);
std::unique_ptr<PrototypeAST> logErrorP(const char* str);
llvm::Value* logErrorV(const char* str);

#endif //KALIEDOSCOPE_ERROR_H
