#include "pathfinder.h"

static void del_matrix(int *m);

void mx_free_all(t_app *app) {
    mx_del_strarr(&(app->city));
    del_matrix(app->a_m);
    del_matrix(app->dist_m);
    mx_del_strarr(&(app->parsed_lines_arr));
    mx_strdel(&(app->file_to_str));
}

static void del_matrix(int *m) {
    if (m) {
        free(m);
    }
}

