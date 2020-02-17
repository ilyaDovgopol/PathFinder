#include "pathfinder.h"

static bool is_valid_name(char *s) {
    if (!mx_strlen(s)) {
        return false;
    }
    while (*s) {
        if (!mx_isalpha(*s)) {
            return false;
        }
        s++;
    }
    return true;
}

static bool parse_line(char *line, char **island1, char **island2, int *dist) {
    int dash_index = mx_get_char_index(line, '-');
    int comma_index = mx_get_char_index(line, ',');
    int len = mx_strlen(line);
    char *ascii_digit = NULL;

    if (dash_index == -1 || comma_index == -1 || dash_index > comma_index
        || len == 0) {
        return false;
    }
    *island1 = mx_strndup(line, dash_index);
    *island2 = mx_strndup(line + dash_index + 1, comma_index - dash_index - 1);
    if (!is_valid_name(*island1) || !is_valid_name(*island2)) {
        return false;
    }
    ascii_digit = mx_strndup(line + comma_index + 1, len - comma_index - 1);
    *dist = mx_atoi(ascii_digit);
    if (*dist == -1 || !(*dist))
        return false;
    free(ascii_digit);
    return true;
}

static void init_adjacency_matrix(t_app *app) {
    app->a_m = malloc(app->size * app->size * sizeof(int));
    for (int i = 0; i < app->size; i++) {
        for (int j = 0; j < app->size; j++) {
            if (i == j) {
                app->a_m[i * app->size + j] = 0;
            }
            else {
                app->a_m[i * app->size + j] = 2147483647;
            }
        }
    }
}

static void init_islands_arr(t_app *app) {
    app->islands_arr = malloc((app->size + 1) * sizeof(char*));
    if (!app->islands_arr) {
        exit(1);
    }
    for (int i = 0; i < app->size + 1; i++) {
        app->islands_arr[i] = NULL;
    }
}

void mx_parse_remaining_lines(t_app *app) {
    init_islands_arr(app);
    init_adjacency_matrix(app);
    for (int i = 1; app->parsed_lines_arr[i] != NULL; i++) {
        char *island1 = NULL;
        char *island2 = NULL;
        int dist = -1;

        if (parse_line(app->parsed_lines_arr[i], &island1, &island2, &dist)) {
            mx_island_push_index(app, dist, island1, island2);
        }
        else {
            free(island1);
            free(island2);
            app->invalid_line_nbr = i + 1;
            mx_cast_error_message(MX_LINE_ISNT_VALID, app);
        }
        free(island1);
        free(island2);
    }
}

