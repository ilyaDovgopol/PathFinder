#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    if (!lst || !cmp) {
        return NULL;
    }
    for (t_list *i = lst; i->next != NULL; i = i->next) {
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
    return lst;
}

