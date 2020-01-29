#include "libmx.h"

void mx_del_strarr(char ***arr) {
    char **p = NULL;

    if (!arr || !(*arr)) {
        return;
    }
    p = *arr;
    while (*p) {
        mx_strdel(p);
        p++;
    }
    free(*arr);
    *arr = NULL;
}

