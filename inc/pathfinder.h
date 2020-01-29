#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"

typedef struct s_app {
    int size;
    char **city;
    int *a_m;
    int *dist_m;
    char **parsed_lines_arr;
    char *file_to_str;
    int invalid_line_nbr;
    char *file_name;
    int k;
    unsigned int sum_dist;
    size_t x;
    size_t y;
}   t_app;

typedef struct s_stack {
    int *path;
    int size;
    int max_size;
}   t_stack;

typedef enum e_err {
    MX_ARGUMENTS_INVALID_NUMBER,
    MX_FILE_DOESNT_EXIST,
    MX_FILE_IS_EMPTY,
    MX_LINE1_ISNT_VALID,
    MX_LINE_ISNT_VALID,
    MX_ISLANDS_INVALID_NUMBER,
    MX_LINE_IS_EMPTY
}   e_err;

void mx_initialize(t_app *app, int argc, char *argv[]);
void mx_cast_error_message(e_err err, t_app *app);
void mx_printerr(const char *s);
int mx_atoi(char *s);
void mx_parse_remaining_lines(t_app *app, char **parsed_str);
bool mx_isalpha(int c);
void mx_city_push_index(t_app *app, int dist, char *city1, char *city2);
void mx_make_cost_matrix(t_app *app);
void mx_restore_all_paths(t_app *app);
void mx_restore_path_helper(t_stack *stack, t_app *app);
void mx_print_path_info(t_stack *stack, t_app *app);
void mx_free_all(t_app *app);

#endif

