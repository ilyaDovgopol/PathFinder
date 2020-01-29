#include "pathfinder.h"

static int get_from_stack(t_stack *stack);
static bool is_next(t_stack *stack, t_app *app, int next);
static void push_in_stack(t_stack *stack, int elem);
static int pop_from_stack(t_stack *stack);

void mx_restore_path_helper(t_stack *stack, t_app *app) {
    if (get_from_stack(stack) == stack->path[0]) {
        mx_print_path_info(stack, app);
        return;
    }
    else {
        for (int next = 0; next < app->size; next++) {
            if (is_next(stack, app, next)) {
                push_in_stack(stack, next);
                mx_restore_path_helper(stack, app);
                pop_from_stack(stack);
            }
        }
    }
}

static int get_from_stack(t_stack *stack) {
    return stack->path[stack->size];
}

static bool is_next(t_stack *stack, t_app *app, int next) {
    int k = get_from_stack(stack);
    int *d_m = app->dist_m;
    int size = app->size;
    int i = stack->path[0];
    int *a_m = app->a_m;

    if (k != next) {
        if (d_m[k * size + i] - a_m[k * size + next] == d_m[next * size + i]) {
            return true;
        }
    }
    return false;
}

static void push_in_stack(t_stack *stack, int elem) {
    if (stack->size < stack->max_size) {
        stack->size++;
        stack->path[stack->size] = elem;
    }
}

static int pop_from_stack(t_stack *stack) {
    if (stack->size > 1) {
        stack->size--;
        return stack->path[stack->size + 1];
    }
    return stack->path[1];
}

