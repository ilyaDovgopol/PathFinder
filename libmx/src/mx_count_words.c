#include "libmx.h"

int mx_count_words(const char *str, char c) {
    bool flag = true;
    int count = 0;

    if (!str) {
        return -1;
    }
    while (*str) {
        if (*str == c) {
            flag = true;
        }
        else if (flag) {
            count++;
            flag = false;
        }
        str++;
    }
    return count;
}

