#include "lexer.h"
#include <stdio.h>

token_t *tokenize(FILE *fptr, const char *filename, int *cnt) {
    printf("Contents of '%s' file...\n", filename);
    token_t token;
    static token_t tokens[1024];
    *cnt = 0;
    int c;
    while ((c = fgetc(fptr)) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t')
            continue;
        switch (c) {
        case '+':
            token.type = ADD;
            break;
        case '-':
            token.type = SUB;
            break;
        case '*':
            token.type = MUL;
            break;
        case '/':
            token.type = DIV;
            break;
        default:
            token.type = IDENT;
            break;
        }
        token.value = c;
        tokens[(*cnt)++] = token;
    }
    return tokens;
}

void print_tokens(token_t *tokens, int *cnt) {
    for (int i = 0; i < *cnt; i++) {
        printf("Token %d: type=%d, value=%c\n", i, tokens[i].type,
               tokens[i].value);
    }
}

void print_original(FILE *fptr) {
    int c;
    while ((c = fgetc(fptr)) != EOF) {
        putchar(c);
    }
}
