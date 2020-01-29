#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    unsigned char *s = b;
    unsigned char chr = c;

    for (size_t i = 0; i < len; i++) {
        s[i] = chr;
    }
    return b;
}

