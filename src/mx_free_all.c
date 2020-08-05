#include "pathfinder.h"

static void del_matrix(int *m) {
    if (m) {
        free(m);
    }
}

void mx_free_all(t_app *app) {
    mx_strdel(&(app->file_to_str));
    mx_del_strarr(&(app->parsed_lines_arr));
    mx_del_strarr(&(app->islands_arr));
    del_matrix(app->a_m);
    del_matrix(app->dist_m);
}
