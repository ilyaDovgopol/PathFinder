#include "libmx.h"

int mx_list_size(t_list *list) {
    int size = 1;

    if (!list) {
        return 0;
    }
    for (t_list *i = list; i->next != NULL; i = i->next) {
        size++;
    }
    return size;
}

