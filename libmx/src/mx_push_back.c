#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *node = NULL;
    t_list *i = NULL;

    if (!list) {
        return;
    }
    node = mx_create_node(data);
    if (!node) {
        return;
    }
    if (!(*list)) {
        *list = node;
        return;
    }
    i = *list;
    while (i->next) {
        i = i->next;
    }
    i->next = node;
}

