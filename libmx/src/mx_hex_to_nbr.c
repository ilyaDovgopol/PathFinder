static int get_dec_digit(char c);

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long n = 0;

    if (!hex) {
        return 0;
    }
    while (*hex) {
        n = 16 * n + get_dec_digit(*hex);
        hex++;
    }
    return n;
}

static int get_dec_digit(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    return 0;
}

