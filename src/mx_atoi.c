#include "pathfinder.h"

static bool is_digit(int c) {
    return c >= '0' && c <= '9';
}

int mx_atoi(char *s) {
    int res = 0;

    while (*s) {
        if (!is_digit(*s)) {
            return -1;
        }
        res = 10 * res + *s - 48;
        s++;
    }
    return res;
}
