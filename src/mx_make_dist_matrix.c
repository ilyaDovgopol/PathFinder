#include "pathfinder.h"

static void init_dist_matrix(t_app *app);
static void use_floyd_warshall_algorithm(t_app *app);

void mx_make_cost_matrix(t_app *app) {
    init_dist_matrix(app);
    use_floyd_warshall_algorithm(app);
}

static void init_dist_matrix(t_app *app) {
    app->dist_m = malloc(app->size * app->size * sizeof(int));
    for (int i = 0; i < app->size; i++) {
        for (int j = 0; j < app->size; j++) {
            app->dist_m[i * app->size + j] = app->a_m[i * app->size + j];
        }
    }
}

static void use_floyd_warshall_algorithm(t_app *app) {
    int size = app->size;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                int *d_m = app->dist_m;

                app->y = d_m[j * size + i] + d_m[i * size + k];
                app->x = d_m[j * size + k];
                if (app->y < app->x) {
                    d_m[j * size + k] = d_m[j * size + i] + d_m[i * size + k];
                }
            }
        }
    }
}

