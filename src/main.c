#include "pathfinder.h"

int main(int argc, char *argv[]) {
    t_app *app = malloc(sizeof(t_app));

    app->file_name = NULL;
    app->file_to_str = NULL;
    app->parsed_lines_arr = NULL;
    app->islands_arr = NULL;
    app->a_m = NULL;
    app->dist_m = NULL;
    if (argc != 2) {
        mx_cast_error_message(MX_ARGUMENTS_INVALID_NUMBER, app);
    }
    mx_initialize(app, argv);
    mx_make_cost_matrix(app);
    mx_restore_all_paths(app);
    mx_free_all(app);
    mx_printchar('\n');
    return 0;
}

