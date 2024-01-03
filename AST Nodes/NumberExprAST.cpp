//
// Created by Chuck Zumbaugh on 12/30/23.
//

#include "NumberExprAST.h"
#include "../llvm_statics.h"

NumberExprAST::NumberExprAST(double val): val(val) {}

llvm::Value *NumberExprAST::codegen() {
    // Numeric constants are represented by the ConstantFP class.
    // APFloat holds a floating point constant of arbitrary precision.
    return llvm::ConstantFP::get(*theContext, llvm::APFloat(val));
};