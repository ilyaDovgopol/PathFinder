#include "libmx.h"

static void add_char_in_string(char *s, char c, int *j) {
    s[*j] = c;
    (*j)++;
}

char *mx_del_extra_spaces(const char *str) {
    char *s = NULL;
    char *ss = NULL;
    int j = 0;
    bool flag = false;

    if (!str || !(*str))
        return NULL;
    s = mx_strtrim(str);
    ss = mx_strnew(mx_strlen(s));
    for (int i = 0; s[i] != '\0'; i++) {
        if (!mx_isspace(s[i])) {
            add_char_in_string(ss, s[i], &j);
            flag = true;
        }
        else if (flag) {
            add_char_in_string(ss, ' ', &j);
            flag = false;
        }
    }
    free(s);
    s = mx_strndup(ss, mx_strlen(ss));
    free(ss);
    return s;
}
