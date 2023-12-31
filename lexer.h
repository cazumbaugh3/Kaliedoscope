//
// Created by Chuck Zumbaugh on 12/30/23.
//

#ifndef KALIEDOSCOPE_LEXER_H
#define KALIEDOSCOPE_LEXER_H
#include <string>

enum Token {
    tok_eof = -1,
    tok_def = -2,
    tok_extern = -3,
    tok_identifier = -4,
    tok_number = -5
};

extern std::string identifierString;
extern double numVal;
int getTok();

#endif //KALIEDOSCOPE_LEXER_H
