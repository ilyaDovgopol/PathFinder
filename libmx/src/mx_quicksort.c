#include "libmx.h"

static void swap(char **s1, char **s2, int *count) {
    char *swap = *s1;

    if (mx_strlen(*s1) - mx_strlen(*s2) == 0) {
        return;
    }
    *s1 = *s2;
    *s2 = swap;
    (*count)++;
}

int mx_quicksort(char **arr, int left, int right) {
    int i = left;
    int j = right;
    int count = 0;

    if (!arr || !(*arr))
        return -1;
    if (left >= right)
        return 0;
    while (i <= j) {
        while (mx_strlen(arr[i]) - mx_strlen(arr[(left + right) / 2]) < 0)
            i++;
        while (mx_strlen(arr[j]) - mx_strlen(arr[(left + right) / 2]) > 0)
            j--;
        if (i <= j) {
            swap(&arr[i], &arr[j], &count);
            i++;
            j--;
        }
    }
    if (left < j)
        count += mx_quicksort(arr, left, j);
    if (right > i)
        count += mx_quicksort(arr, i, right);
    return count;
}
