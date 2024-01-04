//
// Created by Chuck Zumbaugh on 12/30/23.
//

#include "PrototypeAST.h"
#include "../llvm_statics.h"

PrototypeAST::PrototypeAST(const std::string &name, std::vector<std::string> args):
name(name), args(std::move(args)) {};

const std::string &PrototypeAST::getName() const {
    return name;
}

llvm::Function* PrototypeAST::codegen() {
    // Make the function type double(double, double)
    std::vector<llvm::Type*> doubles(args.size(), llvm::Type::getDoubleTy(*theContext));

    llvm::FunctionType* ft = llvm::FunctionType::get(llvm::Type::getDoubleTy(*theContext), doubles, false);
    llvm::Function* f = llvm::Function::Create(ft, llvm::Function::ExternalLinkage, name, theModule.get());

    unsigned idx = 0;
    for (auto &arg : f->args()) {
        arg.setName(args[idx++]);
    }
    return f;
}