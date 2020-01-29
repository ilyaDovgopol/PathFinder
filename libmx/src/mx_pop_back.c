#include "libmx.h"

void mx_pop_back(t_list **head) {
    t_list *i = NULL;

    if (!head || !(*head)) {
        return;
    }
    if (!(*head)->next) {
        free(*head);
        *head = NULL;
        return;
    }
    i = *head;
    while (i->next->next) {
        i = i->next;
    }
    free(i->next);
    i->next = NULL;
}

