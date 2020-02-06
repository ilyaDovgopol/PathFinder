#include "pathfinder.h"

int main(int argc, char *argv[]) {
    t_app *app = malloc(sizeof(t_app));

    mx_initialize(app, argc, argv);
    mx_make_cost_matrix(app);
    mx_restore_all_paths(app);
    mx_free_all(app);
    mx_printchar('\n');
    return 0;
}

