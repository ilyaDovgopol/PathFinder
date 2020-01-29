#include "pathfinder.h"

static char *get_name_by_id(t_app *app, int i);
static void print_path(t_app *app, t_stack *stack);
static void print_route(t_stack *stack, t_app *app);
static void print_dist(t_stack *stack, t_app *app);

void mx_print_path_info(t_stack *stack, t_app *app) {
    static bool first_line = true;

    if (first_line) {
        first_line = false;
    }
    else {
        mx_printstr("\n");
    }
    write(1, "========================================", 40);
    mx_printstr("\n");
    print_path(app, stack);
    print_route(stack, app);
    print_dist(stack, app);
    mx_printstr("\n");
    write(1, "========================================", 40);
}

static void print_path(t_app *app, t_stack *stack) {
    mx_printstr("Path: ");
    mx_printstr(get_name_by_id(app, stack->path[1]));
    mx_printstr(" -> ");
    mx_printstr(get_name_by_id(app, stack->path[0]));
    mx_printstr("\n");
}

static char *get_name_by_id(t_app *app, int i) {
    return app->city[i];
}

static void print_route(t_stack *stack, t_app *app) {
    mx_printstr("Route: ");
    for (int i = 1; i < stack->size; i++) {
        mx_printstr(get_name_by_id(app, stack->path[i]));
        mx_printstr(" -> ");
    }
    mx_printstr(get_name_by_id(app, stack->path[stack->size]));
    mx_printstr("\n");
}

static void print_dist(t_stack *stack, t_app *app) {
    mx_printstr("Distance: ");
    if (stack->size == 2) {
        mx_printint(app->dist_m[stack->path[0] * app->size + stack->path[1]]);
    }
    else {
        int total_dist = 0;

        for (int i = 1; i < stack->size; i++) {
            int dist = 0;

            dist = app->a_m[stack->path[i] * app->size + stack->path[i + 1]];
            total_dist += dist;
            mx_printint(dist);
            i + 1 < stack->size ? mx_printstr(" + ") : mx_printstr("");
        }
        mx_printstr(" = ");
        mx_printint(total_dist);
    }
}

