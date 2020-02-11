#include "libmx.h"

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *, void *)) {
    if (!list || !cmp) {
        return NULL;
    }
    for (t_list *i = list; i->next != NULL; i = i->next) {
        t_list *min = i;
        void *swap = i->data;

        for (t_list *j = i->next; j != NULL; j = j->next) {
            if (cmp(min->data, j->data)) {
                min = j;
            }
        }
        i->data = min->data;
        min->data = swap;
    }
    return list;
}

