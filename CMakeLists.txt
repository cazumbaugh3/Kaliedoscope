cmake_minimum_required(VERSION 3.26)
project(kaliedoscope)

set(CMAKE_CXX_STANDARD 17)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

# Set your project compile flags.
# E.g. if using the C++ header files
# you will need to enable C++11 support
# for your compiler.

include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs support core irreader orcjit analysis executionengine instcombine object
        runtimedyld scalaropts support native)
# execute_process(COMMAND llvm-config --libs all
#        OUTPUT_VARIABLE llvm_libs)
# Link against LLVM libraries

add_executable(kaliedoscope main.cpp
        lexer/lexer.cpp
        lexer/lexer.h
        parser/parser.cpp
        parser/parser.h
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
        error/error.cpp
        error/error.h
        llvm_statics.h
        lexer/token.h
        JIT/KaliedoscopeJIT.cpp
        JIT/KaliedoscopeJIT.h
        error/ExitOnError.h
        LLVMPasses/passAndAnalysisManagers.h
)

target_link_libraries(kaliedoscope ${llvm_libs})
