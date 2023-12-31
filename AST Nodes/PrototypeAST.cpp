//
// Created by Chuck Zumbaugh on 12/30/23.
//

#include "PrototypeAST.h"

PrototypeAST::PrototypeAST(const std::string &name, std::vector<std::string> args):
name(name), args(std::move(args)) {};

const std::string &PrototypeAST::getName() const {
    return name;
}