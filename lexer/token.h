//
// Created by Chuck Zumbaugh on 1/5/24.
//

#ifndef KALIEDOSCOPE_TOKEN_H
#define KALIEDOSCOPE_TOKEN_H

enum Token {
    tok_eof = -1,
    tok_def = -2,
    tok_extern = -3,
    tok_identifier = -4,
    tok_number = -5
};

#endif //KALIEDOSCOPE_TOKEN_H
