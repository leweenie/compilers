#include "types.h"

const string *new_string(const char *source, int length) {
    string *str = calloc(1, sizeof(string));
    str->head = source;
    str->length = length;
    return str;
}
