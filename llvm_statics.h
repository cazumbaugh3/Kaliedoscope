//
// Created by Chuck Zumbaugh on 1/2/24.
//

#ifndef KALIEDOSCOPE_LLVM_STATICS_H
#define KALIEDOSCOPE_LLVM_STATICS_H

#include <string>
#include <memory>
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"

extern std::unique_ptr<llvm::LLVMContext> theContext;
extern std::unique_ptr<llvm::IRBuilder<>> builder;
extern std::unique_ptr<llvm::Module> theModule;
extern std::map<std::string, llvm::Value*> namedValues;

#endif //KALIEDOSCOPE_LLVM_STATICS_H
