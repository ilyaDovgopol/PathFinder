#include "libmx.h"

void *mx_memccpy(
void *restrict dst, const void *restrict src, int c, size_t n) {
    unsigned char *restrict dest = dst;
    const unsigned char *restrict s = src;
    unsigned char chr = c;

    for (size_t i = 0; i < n; i++) {
        dest[i] = s[i];
        if (s[i] == chr) {
            return &dest[i + 1];
        }
    }
    return NULL;
}

