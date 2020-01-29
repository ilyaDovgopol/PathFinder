#include "libmx.h"

static void nbr_to_dec_rec(int n, char *s);

char *mx_itoa(int number) {
    char *s = NULL;

    if (number == -2147483648) {
        return mx_strdup("-2147483648");
    }
    s = mx_strnew(11);
    if (!s) {
        return NULL;
    }
    if (number < 0) {
        *s = '-';
        number = -number;
    }
    nbr_to_dec_rec(number, s);
    return s;
}

static void nbr_to_dec_rec(int n, char *s) {
    int last_digit = n % 10;

    if (n >= 10) {
        nbr_to_dec_rec(n / 10, s);
    }
    while (*s) {
        s++;
    }
    *s = last_digit + 48;
}

