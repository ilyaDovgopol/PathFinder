#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    void *p = NULL;

    if (!ptr && size) {
        return malloc(size);
    }
    if (ptr && !size) {
        free(ptr);
        ptr = NULL;
        return NULL;
    }
    size = size >= malloc_size(ptr) ? size : malloc_size(ptr);
    p = malloc(size);
    if (!p) {
        return NULL;
    }
    mx_memmove(p, ptr, size);
    free(ptr);
    ptr = NULL;
    return p;
}

