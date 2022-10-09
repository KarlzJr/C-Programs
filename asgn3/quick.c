#include "quick.h"

#include <stdio.h>

int partition(Stats *stats, uint32_t *A, int low, int high) {
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (cmp(stats, A[j - 1], A[high - 1]) == -1) {
            i += 1;
            swap(stats, &A[j - 1], &A[i - 1]);
        }
    }
    swap(stats, &A[high - 1], &A[i]);
    return (i + 1);
}

void quick_sorter(Stats *stats, uint32_t *A, int low, int high) {
    if (low < high) {
        int p = partition(stats, A, low, high);
        quick_sorter(stats, A, low, p - 1);
        quick_sorter(stats, A, p + 1, high);
    }
}

void quick_sort(Stats *stats, uint32_t *A, uint32_t n) {
    quick_sorter(stats, A, 1, n);
}
