#include "pathfinder.h"

static void push_element_in_island(t_app *app, char *elem);
static int index_in_island(t_app *app, char *elem);

void mx_island_push_index(t_app *app, int dist, char *island1, char *island2) {
    int i = 0;
    int j = 0;

    if (app->sum_dist < 2147483647) {
        app->sum_dist += dist;
    }
    else {
        exit(1);
    }
    push_element_in_island(app, island1);
    push_element_in_island(app, island2);
    i = index_in_island(app, island1);
    j = index_in_island(app, island2);
    app->a_m[i * app->size + j] = dist;
    app->a_m[j * app->size + i] = dist;
}

static void push_element_in_island(t_app *app, char *elem) {
    int i = 0;

    while (i < app->size) {
        if (!app->islands_arr[i]) {
            break;
        }
        if (mx_strcmp(app->islands_arr[i], elem) == 0) {
            return;
        }
        i++;
    }
    if (i < app->size) {
        app->islands_arr[i] = mx_strdup(elem);
    }
    else {
        mx_cast_error_message(MX_ISLANDS_INVALID_NUMBER, app);
    }
}

static int index_in_island(t_app *app, char *elem) {
    for (int i = 0; i < app->size; i++) {
        if (mx_strcmp(app->islands_arr[i], elem) == 0) {
            return i;
        }
    }
    return -1;
}

