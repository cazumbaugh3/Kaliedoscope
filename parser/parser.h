//
// Created by Chuck Zumbaugh on 12/30/23.
//

#ifndef KALIEDOSCOPE_PARSER_H
#define KALIEDOSCOPE_PARSER_H
#include <memory>
#include <map>
#include "../AST Nodes/ExprAST.h"
#include "../AST Nodes/PrototypeAST.h"
#include "../lexer/lexer.h"
#include "../AST Nodes/FunctionAST.h"

extern std::map<char, int> binopPrecedence;

int getTokPrecedence();

// Parsing
std::unique_ptr<ExprAST> parseNumberExpr();
std::unique_ptr<ExprAST> parseParenExpr();
std::unique_ptr<ExprAST> parseIdentifierExpr();
std::unique_ptr<ExprAST> parsePrimary();
std::unique_ptr<ExprAST> parseExpression();
std::unique_ptr<ExprAST> parseBinopRHS(int exprPrec, std::unique_ptr<ExprAST> lhs);
std::unique_ptr<PrototypeAST> parsePrototype();
std::unique_ptr<FunctionAST> parseDefinition();
std::unique_ptr<PrototypeAST> parseExtern();
std::unique_ptr<FunctionAST> parseTopLevelExpr();


#endif //KALIEDOSCOPE_PARSER_H
