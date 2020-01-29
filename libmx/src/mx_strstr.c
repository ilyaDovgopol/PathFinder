#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    int len = 0;

    if (!(*needle)) {
        return (char *)haystack;
    }
    len = mx_strlen(needle);
    while (*haystack) {
        if (*haystack == *needle) {
            if (mx_strncmp(haystack, needle, len) == 0) {
                return (char *)haystack;
            }
        }
        haystack++;
    }
    return NULL;
}

