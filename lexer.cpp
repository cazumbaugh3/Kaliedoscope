#include <string>
#include "lexer.h"

std::string identifierString;
double numVal;

int getTok() {
    static int lastChar = ' ';

    while (isspace(lastChar)) {
        lastChar = getchar();
    }

    if (isalpha(lastChar)) {
        identifierString = lastChar;
        while (isalnum((lastChar = getchar()))) {
            identifierString += lastChar;
        }
        if (identifierString == "def") {
            return tok_def;
        }
        if (identifierString == "extern") {
            return tok_extern;
        }
        return tok_identifier;
    }

    if (isdigit(lastChar) || lastChar == '.') {
        std::string numStr;
        do {
            numStr += std::to_string(lastChar);
            lastChar = getchar();
        } while (isdigit(lastChar) || lastChar == '.');

        numVal = strtod(numStr.c_str(), nullptr);
        return tok_number;
    }

    if (lastChar == '#') {
        // Skip over comments
        do {
            lastChar = getchar();
        } while (lastChar != EOF && lastChar != '\n' && lastChar != '\r');

        if (lastChar != EOF) {
            return getTok();
        }
    }

    if (lastChar == EOF) {
        return tok_eof;
    }

    int thisChar = lastChar;
    lastChar = getchar();
    return thisChar;
}
