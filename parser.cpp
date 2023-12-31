//
// Created by Chuck Zumbaugh on 12/30/23.
//

#include "parser.h"
#include "lexer.h"
#include "./AST Nodes/NumberExprAST.h"
#include "AST Nodes/VariableExprAST.h"
#include "AST Nodes/CallExprAST.h"
#include "AST Nodes/BinaryExprAST.h"
#include "AST Nodes/FunctionAST.h"

int curTok;
std::map<char, int> binopPrecedence;

int getNextTok() {
    return curTok = getTok();
}

std::unique_ptr<ExprAST> logError(const char* str) {
    fprintf(stderr, "Error: %s\n", str);
    return nullptr;
}

std::unique_ptr<PrototypeAST> logErrorP(const char* str) {
    logError(str);
    return nullptr;
}

std::unique_ptr<ExprAST> parseExpression();

std::unique_ptr<ExprAST> parseNumberExpr() {
    auto result = std::make_unique<NumberExprAST>(numVal);
    getNextTok();
    return std::move(result);
}

std::unique_ptr<ExprAST> parseParenExpr() {
    getNextTok();
    auto v = parseExpression();
    if (!v) {
        return nullptr;
    }

    if (curTok != ')') {
        return logError("expected ')'");
    }
    getNextTok();
    return v;
}

std::unique_ptr<ExprAST> parseIdentifierExpr() {
    std::string idName = identifierString;
    getNextTok(); // Eat identifier

    if (curTok != '(') {
        return std::make_unique<VariableExprAST>(idName);
    }

    getNextTok(); // Eat '('
    std::vector<std::unique_ptr<ExprAST>> args;
    if (curTok != ')') {
        while (true) {
            if (auto arg = parseExpression()) {
                args.push_back(std::move(arg));
            }
            else {
                return nullptr;
            }
            if (curTok == ')') {
                break;
            }
            if (curTok != ',') {
                return logError("Expected ')' or ',' in argument list");
            }
            getNextTok();
        }
    }
    getNextTok(); // Eat ')'

    return std::make_unique<CallExprAST>(idName, std::move(args));
}

std::unique_ptr<ExprAST> parsePrimary() {
    switch (curTok) {
        default:
            return logError("unknown token when expecting an expression");
        case tok_identifier:
            return parseIdentifierExpr();
        case tok_number:
            return parseNumberExpr();
        case '(':
            return parseParenExpr();
    }
}

int getTokPrecedence() {
    if (!isascii(curTok)) {
        return -1;
    }
    int tokPrec = binopPrecedence[curTok];
    if (tokPrec < 0) {
        return -1;
    }
    return tokPrec;
}

std::unique_ptr<ExprAST> parseExpression() {
    auto lhs = parsePrimary();
    if (!lhs) {
        return nullptr;
    }
    return parseBinopRHS(0, std::move(lhs));
}

std::unique_ptr<ExprAST> parseBinopRHS(int exprPrec, std::unique_ptr<ExprAST> lhs) {
    while (true) {
        int tokPrec = getTokPrecedence();

        if (tokPrec < exprPrec) {
            // LHS is a higher precedence, we are done
            return lhs;
        }
        int binop = curTok;
        getNextTok(); // eat Binop
        // Parse the primary expression following the binop
        auto rhs = parsePrimary();
        if (!rhs) {
            return nullptr;
        }
        int nextPrec = getTokPrecedence();
        // If the binop binds less tightly with RHS than the operator after RHS,
        // let the pending operator take RHS as it's LHS
        if (tokPrec < nextPrec) {
            rhs = parseBinopRHS(tokPrec + 1, std::move(rhs));
            if (!rhs) {
                return nullptr;
            }
        }
        // Merge LHS/RHS
        lhs = std::make_unique<BinaryExprAST>(binop, std::move(lhs), std::move(rhs));
    }
}

std::unique_ptr<PrototypeAST> parsePrototype() {
    if (curTok != tok_identifier) {
        return logErrorP("Expected function name in prototype");
    }

    std::string fnName = identifierString;
    getNextTok();

    if (curTok != '(') {
        return logErrorP("Expected '(' in prototype");
    }

    std::vector<std::string> argNames;

    while (getNextTok() == tok_identifier) {
        argNames.push_back(identifierString);
    }
    // Have finished parsing args
    if (curTok != ')') {
        return logErrorP("Expected ')' in prototype");
    }
    // Success. Eat the ')'
    getNextTok();
    // Return the AST for a prototype
    return std::make_unique<PrototypeAST>(fnName, std::move(argNames));
}

std::unique_ptr<FunctionAST> parseDefinition() {
    getNextTok(); // Eat def
    auto proto = parsePrototype(); // Parse the prototype
    if (!proto) {
        return nullptr;
    }
    // Parse the resulting expression, if it is there
    if (auto e = parseExpression()) {
        return std::make_unique<FunctionAST>(std::move(proto), std::move(e));
    }
    // No expression, return null pointer
    return nullptr;
}

std::unique_ptr<PrototypeAST> parseExtern() {
    getNextTok(); // Eat extern
    return parsePrototype();
}

std::unique_ptr<FunctionAST> parseTopLevelExpr() {
    if (auto e = parseExpression()) {
        // Make an anononymous prototype
        auto proto = std::make_unique<PrototypeAST>("__anon_expr", std::vector<std::string>());
        // Construct and return a function AST from the proto and the expression
        return std::make_unique<FunctionAST>(std::move(proto), std::move(e));
    }
    return nullptr;
}