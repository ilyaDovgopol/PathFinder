#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    const unsigned char *str = s;
    unsigned char chr = c;

    while (n > 0) {
        if (str[n] == chr) {
            return (void *)&str[n];
        }
        n--;
    }
    return NULL;
}

