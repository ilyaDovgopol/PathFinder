#include "pathfinder.h"

static void restore_allpaths_from_to(t_app *app, int j, int i);
static void init_stack(t_stack **stack, t_app *app, int j, int i);

void mx_restore_all_paths(t_app *app) {
    for (int i = 0; i < app->size - 1; i++) {
        for (int j = i + 1; j < app->size; j++) {
            restore_allpaths_from_to(app, j, i);
        }
    }
}

static void restore_allpaths_from_to(t_app *app, int j, int i) {
    t_stack *stack = NULL;

    init_stack(&stack, app, j, i);
    mx_restore_path_helper(stack, app);
    free(stack->path);
    free(stack);
}

static void init_stack(t_stack **stack, t_app *app, int j, int i) {
    *stack = malloc(sizeof(t_stack));
    if (!(*stack)) {
        exit(1);
    }
    (*stack)->max_size = app->size;
    (*stack)->path = malloc(((*stack)->max_size + 1) * sizeof(int));
    (*stack)->path[0] = j;
    (*stack)->path[1] = i;
    (*stack)->size = 1;
}

