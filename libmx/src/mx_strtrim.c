#include "libmx.h"

char *mx_strtrim(const char *str) {
    int start = 0;
    int end = 0;

    if (!str || !(*str)) {
        return NULL;
    }
    while (mx_isspace(str[start])) {
        start++;
    }
    end = mx_strlen(str) - 1;
    while (mx_isspace(str[end])) {
        end--;
    }
    if (end == -1) {
        return mx_strnew(0);
    }
    return mx_strndup(&str[start], end - start + 1);
}

