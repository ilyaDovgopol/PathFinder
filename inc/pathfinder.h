#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"

typedef struct s_app
{
    char *file_name;
    char *file_to_str;
    int k;
    char **parsed_lines_arr;
    int size;
    char **islands_arr;
    int *a_m;
    unsigned int sum_dist;
    int invalid_line_nbr;
    int *dist_m;
    size_t y;
    size_t x;
}              t_app;

typedef enum e_err
{
    MX_ARGUMENTS_INVALID_NUMBER,
    MX_FILE_DOESNT_EXIST,
    MX_FILE_IS_EMPTY,
    MX_LINE1_ISNT_VALID,
    MX_LINE_IS_EMPTY,
    MX_ISLANDS_INVALID_NUMBER,
    MX_LINE_ISNT_VALID
}            t_err;

typedef struct s_stack
{
    int max_size;
    int *path;
    int size;
}              t_stack;

void mx_initialize(t_app *app, int argc, char *argv[]);
void mx_cast_error_message(t_err err, t_app *app);
void mx_printerr(const char *s);
int mx_atoi(char *s);
void mx_parse_remaining_lines(t_app *app);
bool mx_isalpha(int c);
void mx_island_push_index(t_app *app, int dist, char *island1, char *island2);
void mx_make_cost_matrix(t_app *app);
void mx_restore_all_paths(t_app *app);
void mx_restore_path_helper(t_stack *stack, t_app *app);
void mx_print_path_info(t_stack *stack, t_app *app);
void mx_free_all(t_app *app);

#endif

