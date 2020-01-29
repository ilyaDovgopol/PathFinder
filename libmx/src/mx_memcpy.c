#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    char *restrict dest = dst;
    const char *restrict s = src;

    if (!dst && !src) {
        return NULL;
    }
    for (size_t i = 0; i < n; i++) {
        dest[i] = s[i];
    }
    return dst;
}

