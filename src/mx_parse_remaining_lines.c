#include "pathfinder.h"

static void init_city(t_app *app);
static void init_adjacency_matrix(t_app *app);
static bool parse_line(char *line, char **city1, char **city2, int *dist);
static bool is_valid_name(char *s);

void mx_parse_remaining_lines(t_app *app, char **parsed_str) {
    init_city(app);
    init_adjacency_matrix(app);
    for (int i = 1; parsed_str[i] != NULL; i++) {
        char *city1 = NULL;
        char *city2 = NULL;
        int dist = -1;

        if (parse_line(parsed_str[i], &city1, &city2, &dist)) {
            mx_city_push_index(app, dist, city1, city2);
        }
        else {
            free(city1);
            free(city2);
            app->invalid_line_nbr = i + 1;
            mx_cast_error_message(MX_LINE_ISNT_VALID, app);
        }
        free(city1);
        free(city2);
    }
}

static void init_city(t_app *app) {
    app->city = malloc((app->size + 1) * sizeof(char *));
    if (!app->city) {
        exit(1);
    }
    for (int i = 0; i < app->size + 1; i++) {
        app->city[i] = NULL;
    }
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

static bool parse_line(char *line, char **city1, char **city2, int *dist) {
    int dash_index = mx_get_char_index(line, '-');
    int comma_index = mx_get_char_index(line, ',');
    int len = mx_strlen(line);
    char *ascii_digit = NULL;

    if (dash_index == -1 || comma_index == -1 || len == 0
        || dash_index > comma_index) {
        return false;
    }
    *city1 = mx_strndup(line, dash_index);
    *city2 = mx_strndup(line + dash_index + 1, comma_index - dash_index - 1);
    if (!is_valid_name(*city1) || !is_valid_name(*city2)) {
        return false;
    }
    ascii_digit = mx_strndup(line + comma_index + 1, len - comma_index - 1);
    *dist = mx_atoi(ascii_digit);
    if (*dist == -1 || *dist == -2 || !(*dist))
        return false;
    free(ascii_digit);
    return true;
}

static bool is_valid_name(char *s) {
    if (mx_strlen(s) == 0) {
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

