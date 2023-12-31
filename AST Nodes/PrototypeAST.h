//
// Created by Chuck Zumbaugh on 12/30/23.
//

#ifndef KALIEDOSCOPE_PROTOTYPEAST_H
#define KALIEDOSCOPE_PROTOTYPEAST_H
#include <string>
#include <vector>
#include "ExprAST.h"

class PrototypeAST: public ExprAST {
std::string name;
std::vector<std::string> args;

public:
    PrototypeAST(const std::string &name, std::vector<std::string> args);
    const std::string &getName() const;
};


#endif //KALIEDOSCOPE_PROTOTYPEAST_H
