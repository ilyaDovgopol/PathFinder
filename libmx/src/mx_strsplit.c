#include "libmx.h"

static bool is_next_word(int *start, int *end, char *s, char c);

char **mx_strsplit(const char *s, char c) {
    int i = mx_count_words(s, c);
    char **arr = NULL;
    int start = 0;
    int end = -1;

    if (!s || !(*s) || !i)
        return NULL;
    arr = (char **)malloc((i + 1) * sizeof(char *));
    if (!arr)
        return NULL;
    i = 0;
    while (is_next_word(&start, &end, (char *)s, c)) {
        char *str = mx_strnew(end - start + 1);

        mx_strncpy(str, &s[start], end - start + 1);
        arr[i] = str;
        i++;
    }
    arr[i] = NULL;
    return arr;
}

static bool is_next_word(int *start, int *end, char *s, char c) {
    *start = *end + 1;
    while (s[*start] == c && s[*start]) {
        (*start)++;
    }
    if (s[*start] == '\0') {
        return false;
    }
    *end = *start;
    while (s[*end] != c && s[*end]) {
        (*end)++;
    }
    (*end)--;
    return true;
}

