#include "pathfinder.h"

static char *read_file(char *argv[], t_app *app);
static void check_empty_lines(char *s, t_app *app);
static void check_file(t_app *app);

void mx_initialize(t_app *app, int argc, char *argv[]) {
    char *s = NULL;

    app->city = NULL;
    app->a_m = NULL;
    app->dist_m = NULL;
    app->parsed_lines_arr = NULL;
    app->file_to_str = NULL;
    if (argc != 2) {
        mx_cast_error_message(MX_ARGUMENTS_INVALID_NUMBER, app);
    }
    s = read_file(argv, app);
    check_empty_lines(s, app);
    app->parsed_lines_arr = mx_strsplit(s, '\n');
    check_file(app);
    mx_parse_remaining_lines(app, app->parsed_lines_arr);
    if (!app->city[app->size - 1]) {
        mx_cast_error_message(MX_ISLANDS_INVALID_NUMBER, app);
    }
}

static char *read_file(char *argv[], t_app *app) {
    int fd = open(argv[1], O_RDONLY);
    char *s = NULL;

    app->file_name = argv[1];
    if (fd < 0) {
        close(fd);
        mx_cast_error_message(MX_FILE_DOESNT_EXIST, app);
    }
    close(fd);
    app->file_to_str = mx_file_to_str(argv[1]);
    s = app->file_to_str;
    if (!s || mx_strlen(s) == 0) {
        mx_cast_error_message(MX_FILE_IS_EMPTY, app);
    }
    return s;
}

static void check_empty_lines(char *s, t_app *app) {
    int count = 0;

    if (*s == '\n') {
        mx_cast_error_message(MX_LINE1_ISNT_VALID, app);
    }
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '\n') {
            count++;
        }
        if (s[i] == '\n' && s[i + 1] == '\n') {
            app->k = count + 1;
            mx_cast_error_message(MX_LINE_IS_EMPTY, app);
        }
    }
}

static void check_file(t_app *app) {
    char **line = app->parsed_lines_arr;

    if (mx_strlen(*line) > 4) {
        mx_cast_error_message(MX_ISLANDS_INVALID_NUMBER, app);
    }
    app->size = mx_atoi(*line);
    if (!app->size && !line[1]) {
        exit(0);
    }
    if (app->size == -1) {
        mx_cast_error_message(MX_LINE1_ISNT_VALID, app);
    }
    if (!app->size && line[1]) {
        mx_cast_error_message(MX_ISLANDS_INVALID_NUMBER, app);
    }
}

