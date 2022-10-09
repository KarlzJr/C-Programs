#include "shell.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static uint32_t MAX_GAP;
uint32_t *gaps(uint32_t n) {
    MAX_GAP = (log(3 + 2 * n) / log(3));
    uint32_t *arrgap = malloc(MAX_GAP * (sizeof(int)));
    for (uint32_t i = MAX_GAP; i > 0; i -= 1) {
        arrgap[i] = (pow(3, i) - 1) / 2;
    }
    return arrgap;
}

void shell_sort(Stats *stats, uint32_t *A, uint32_t n) {
    uint32_t *arrgap = gaps(n);
    for (uint32_t gap = MAX_GAP; gap >= 1; gap--) {
        uint32_t currgap = arrgap[gap];
        for (uint32_t i = arrgap[gap]; i < n; i++) {
            uint32_t j = i;
            uint32_t temp = move(stats, A[i]);
            while (j >= currgap && (cmp(stats, temp, A[j - currgap]) == -1)) {
                A[j] = move(stats, A[j - currgap]);
                j -= currgap;
            }
            A[j] = move(stats, temp);
        }
    }
    free(arrgap);
}
