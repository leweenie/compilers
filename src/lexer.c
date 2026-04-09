#include "lexer.h"
#include "types.h"
#include <ctype.h>

token_t *new_token(token_kind_t kind, token_t *current, const char *string,
                   int length) {
    token_t *token = calloc(1, sizeof(token_t));
    token->kind = kind;
    token->value = new_string(string, length);
    current->next = token;
    return token;
}

token_t *tokenize(const char *f) { token_t head; }
