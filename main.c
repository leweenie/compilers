#include "lexer.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        puts("Running with *.nv file...");
        const char *filename = argv[1];
        FILE *fptr = fopen(filename, "r");
        int cnt = 0;
        token_t *tokens = tokenize(fptr, filename, &cnt);
        print_tokens(tokens, &cnt);
        fclose(fptr);
    } else {
        puts("No files provided...");
    }
    return 0;
}
