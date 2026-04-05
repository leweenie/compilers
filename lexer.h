#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>

typedef enum { IDENT, ADD, MUL, DIV, SUB } token_e;
typedef struct {
    token_e type;
    int value;
} token_t;

token_t *tokenize(FILE *fptr, const char *filename, int *cnt);
void print_original(FILE *fptr);
void print_tokens(token_t *tokens, int *cnt);

#endif
