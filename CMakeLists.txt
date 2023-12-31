cmake_minimum_required(VERSION 3.26)
project(kaliedoscope)

set(CMAKE_CXX_STANDARD 17)

add_executable(kaliedoscope main.cpp
        lexer.cpp
        lexer.h
        parser.cpp
        parser.h
        "AST Nodes/ExprAST.cpp"
        "AST Nodes/ExprAST.h"
        "AST Nodes/NumberExprAST.cpp"
        "AST Nodes/NumberExprAST.h"
        "AST Nodes/VariableExprAST.cpp"
        "AST Nodes/VariableExprAST.h"
        "AST Nodes/BinaryExprAST.cpp"
        "AST Nodes/BinaryExprAST.h"
        "AST Nodes/CallExprAST.cpp"
        "AST Nodes/CallExprAST.h"
        "AST Nodes/PrototypeAST.cpp"
        "AST Nodes/PrototypeAST.h"
        "AST Nodes/FunctionAST.cpp"
        "AST Nodes/FunctionAST.h"
)
