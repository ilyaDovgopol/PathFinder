#include "libmx.h"

int mx_bubble_sort(char **arr, int size) {
    int count = 0;

    if (!arr || !(*arr)) {
        return 0;
    }
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < size - i; j++) {
            if (mx_strcmp(arr[j], arr[j + 1]) > 0) {
                char *swap = arr[j];

                count++;
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
        }
    }
    return count;
}

