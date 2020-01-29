#include "libmx.h"

void *mx_memmem(
const void *big, size_t big_len, const void *little, size_t little_len) {
    const char *haystack = big;
    const char *last = haystack + big_len - little_len;
    const char *needle = little;

    if (!little_len) {
        return NULL;
    }
    while (haystack <= last) {
        if (*haystack == *needle) {
            if (mx_memcmp(haystack, needle, little_len) == 0) {
                return (void *)haystack;
            }
        }
        haystack++;
    }
    return NULL;
}

