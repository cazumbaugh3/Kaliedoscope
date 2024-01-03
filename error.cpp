//
// Created by Chuck Zumbaugh on 1/2/24.
//

#include "error.h"

std::unique_ptr<ExprAST> logError(const char* str) {
    fprintf(stderr, "Error: %s\n", str);
    return nullptr;
}

std::unique_ptr<PrototypeAST> logErrorP(const char* str) {
    logError(str);
    return nullptr;
}

llvm::Value* logErrorV(const char* str) {
    logError(str);
    return nullptr;
}