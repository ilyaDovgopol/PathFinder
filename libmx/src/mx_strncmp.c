#include "libmx.h"

int mx_strncmp(const char *s1, const char *s2, size_t n) {
    size_t i = 0;

    if ((!s1 || !s2) && !n) {
        return 0;
    }
    while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1) {
        i++;
    }
    return (unsigned char) s1[i] - (unsigned char) s2[i];
}

