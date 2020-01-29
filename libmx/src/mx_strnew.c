#include "libmx.h"

char *mx_strnew(const int size) {
    char *s = NULL;

    if (size < 0) {
        return NULL;
    }
    s = (char *)malloc((size + 1) * sizeof(char));
    if (!s) {
        return NULL;
    }
    for (int i = 0; i < size + 1; i++) {
        s[i] = '\0';
    }
    return s;
}

