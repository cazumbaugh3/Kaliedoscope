//
// Created by Chuck Zumbaugh on 12/30/23.
//

#ifndef KALIEDOSCOPE_LEXER_H
#define KALIEDOSCOPE_LEXER_H
#include <string>
#include "token.h"

extern std::string identifierString;
extern double numVal;

extern int curTok;
int getTok();
int getNextTok();

#endif //KALIEDOSCOPE_LEXER_H
