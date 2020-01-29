#include "libmx.h"

void mx_pop_front(t_list **head) {
    if (!head || !(*head)) {
        return;
    }
    free(*head);
    *head = (*head)->next;
}

