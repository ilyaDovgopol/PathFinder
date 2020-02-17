#include "pathfinder.h"

static void check_file(t_app *app) {
    if (mx_strlen(*app->parsed_lines_arr) > 4) {
        mx_cast_error_message(MX_ISLANDS_INVALID_NUMBER, app);
    }
    app->size = mx_atoi(*app->parsed_lines_arr);
    if (!app->size && !app->parsed_lines_arr[1]) {
        exit(0);
    }
    if (!app->size && app->parsed_lines_arr[1]) {
        mx_cast_error_message(MX_ISLANDS_INVALID_NUMBER, app);
    }
    if (app->size == -1) {
        mx_cast_error_message(MX_LINE1_ISNT_VALID, app);
    }
}

static void check_empty_lines(t_app *app) {
    int count = 0;

    if (*app->file_to_str == '\n') {
        mx_cast_error_message(MX_LINE1_ISNT_VALID, app);
    }
    for (int i = 0; app->file_to_str[i] != '\0'; i++) {
        if (app->file_to_str[i] == '\n') {
            count++;
            if (app->file_to_str[i + 1] == '\n') {
                app->k = count + 1;
                mx_cast_error_message(MX_LINE_IS_EMPTY, app);
            }
        }
    }
}

static void read_file(char *argv[], t_app *app) {
    int fd = open(argv[1], O_RDONLY);

    app->file_name = argv[1];
    if (fd < 0) {
        close(fd);
        mx_cast_error_message(MX_FILE_DOESNT_EXIST, app);
    }
    close(fd);
    app->file_to_str = mx_file_to_str(argv[1]);
    if (!app->file_to_str || !mx_strlen(app->file_to_str)) {
        mx_cast_error_message(MX_FILE_IS_EMPTY, app);
    }
}

void mx_initialize(t_app *app, int argc, char *argv[]) {
    app->file_name = NULL;
    app->file_to_str = NULL;
    app->parsed_lines_arr = NULL;
    app->islands_arr = NULL;
    app->a_m = NULL;
    app->dist_m = NULL;
    if (argc != 2) {
        mx_cast_error_message(MX_ARGUMENTS_INVALID_NUMBER, app);
    }
    read_file(argv, app);
    check_empty_lines(app);
    app->parsed_lines_arr = mx_strsplit(app->file_to_str, '\n');
    check_file(app);
    mx_parse_remaining_lines(app);
    if (!app->islands_arr[app->size - 1]) {
        mx_cast_error_message(MX_ISLANDS_INVALID_NUMBER, app);
    }
}

