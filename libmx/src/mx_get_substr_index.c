#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    char *indx = NULL;

    if (!str || !sub) {
        return -2;
    }
    if (!(*sub)) {
        return -1;
    }
    indx = mx_strstr(str, sub);
    if (indx) {
        return indx - str;
    }
    return -1;
}

