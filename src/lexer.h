#ifndef LEXER_H
#define LEXER_H

#include "types.h"

typedef enum {
    TOKEN_IDENTIFIER,
    TOKEN_RESERVED,
    TOKEN_SYMBOL,
    TOKEN_OPERATOR,
    TOKEN_NUMBER,
    TOKEN_EOF,
} token_kind_t;

typedef struct token_t token_t;
struct token_t {
    token_kind_t kind;
    const string *value;
    token_t *next;
};

void skip();

#endif
