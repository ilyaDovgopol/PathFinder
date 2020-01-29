#include "pathfinder.h"

static void file_does_not_exist(t_app *app);
static void file_is_empty(t_app *app);
static void line_is_not_valid(t_app *app);
static void line_is_empty(t_app *app);

void mx_cast_error_message(e_err err, t_app *app) {
    if (err == MX_ARGUMENTS_INVALID_NUMBER)
        mx_printerr("usage: ./pathfinder [filename]");
    else if (err == MX_FILE_DOESNT_EXIST)
        file_does_not_exist(app);
    else if (err == MX_FILE_IS_EMPTY)
        file_is_empty(app);
    else if (err == MX_LINE1_ISNT_VALID)
        mx_printerr("error: line 1 is not valid");
    else if (err == MX_LINE_ISNT_VALID)
        line_is_not_valid(app);
    else if (err == MX_ISLANDS_INVALID_NUMBER)
        mx_printerr("error: invalid number of islands");
    else if (err == MX_LINE_IS_EMPTY)
        line_is_empty(app);
    mx_printerr("\n");
    exit(1);
}

static void file_does_not_exist(t_app *app) {
    mx_printerr("error: file ");
    mx_printerr(app->file_name);
    mx_printerr(" does not exist");
}

static void file_is_empty(t_app *app) {
    mx_printerr("error: file ");
    mx_printerr(app->file_name);
    mx_printerr(" is empty");
}

static void line_is_not_valid(t_app *app) {
    char *line_nbr = mx_itoa(app->invalid_line_nbr);

    mx_printerr("error: line ");
    mx_printerr(line_nbr);
    mx_printerr(" is not valid");
    free(line_nbr);
    line_nbr = NULL;
}

static void line_is_empty(t_app *app) {
    char *line_nbr = mx_itoa(app->k);

    mx_printerr("error: line ");
    mx_printerr(line_nbr);
    mx_printerr(" is not valid");
    free(line_nbr);
    line_nbr = NULL;
}

