#include <iostream>
#include "parser.h"

void handleDefinition() {
    if (parseDefinition()) {
        fprintf(stderr, "Parsed a function definition\n");
    } else {
        getNextTok();
    }
}

void handleExtern() {
    if (parseExtern()) {
        fprintf(stderr, "Parsed an extern\n");
    } else {
        // Skip
        getNextTok();
    }
}

void handleTopLevelExpression() {
    if (parseTopLevelExpr()) {
        fprintf(stderr, "Parsed a top-level expression\n");
    } else {
        getNextTok();
        fprintf(stderr, "Error occured: current token %s\n", identifierString.c_str());
    }
}

void mainLoop() {
    while (true) {
        fprintf(stderr, "ready> ");
        switch (curTok) {
            case tok_eof:
                return;
            case ';':
                getNextTok();
                break;
            case tok_def:
                handleDefinition();
                break;
            case tok_extern:
                handleExtern();
                break;
            default:
                handleTopLevelExpression();
                break;
        }
    }
}

int main() {
    binopPrecedence['<'] = 10;
    binopPrecedence['+'] = 20;
    binopPrecedence['-'] = 30;
    binopPrecedence['*'] = 40;

    fprintf(stderr, "ready> ");
    getNextTok();

    mainLoop();
    return 0;
}
