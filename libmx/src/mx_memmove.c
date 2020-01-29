#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    void *s = NULL;

    if (!dst && !src) {
        return NULL;
    }
    s = malloc(len);
    if (!s) {
        return NULL;
    }
    mx_memcpy(s, src, len);
    mx_memcpy(dst, s, len);
    free(s);
    return dst;
}

