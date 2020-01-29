#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    const unsigned char *s = s1;
    const unsigned char *str = s2;

    for (size_t i = 0; i < n; i++) {
        if (s[i] != str[i]) {
            return s[i] - str[i];
        }
    }
    return 0;
}

