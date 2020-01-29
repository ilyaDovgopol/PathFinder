#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if (!arr || !(*arr) || !(**arr) || !delim || !(*delim)) {
        return;
    }
    mx_printstr(*arr);
    for (int i = 1; arr[i] != NULL; i++) {
        mx_printstr(delim);
        mx_printstr(arr[i]);
    }
    mx_printchar('\n');
}

