#ifndef TYPES_H
#define TYPES_H

#include <stdlib.h>

typedef struct {
    const char *head;
    int length;
} string;

const string *new_string(const char *source, int length);

#endif
