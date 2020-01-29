#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    char *s = NULL;

    if (!s1 && !s2) {
        return NULL;
    }
    if (!s1 || !(*s1)) {
        return mx_strdup(s2);
    }
    if (!s2 || !(*s2)) {
        return mx_strdup(s1);
    }
    s = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    if (!s) {
        return NULL;
    }
    mx_strcpy(s, s1);
    mx_strcat(s, s2);
    return s;
}

