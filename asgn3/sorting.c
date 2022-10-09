#include "heap.h"
#include "insert.h"
#include "quick.h"
#include "set.h"
#include "shell.h"
#include "stats.h"

#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define OPTIONS    "haeisqn:p:r:"
#define DEFAULT    100;
#define SEEDEFAULT 13371453;
uint32_t length = 100;
int seed = 13371453;
int printnum = 100;
void message();
Stats stats;
typedef enum { HEAP, INSERT, SHELL, QUICK, HELP, SEED, LENGTH, PRINTNUM, NUM_SORTS } Choices;
const char *names[] = { "Heap", "Insert", "Shell", "Quick", "Help", "Seed", "Len", "Print" };
uint32_t *arraymaker(int length) {
    srand(seed);
    uint32_t *mixed = malloc(length * (sizeof(int)));
    for (int i = 0; i < length; i++) {
        mixed[i] = random() & 0x3FFFFFFF;
    }
    return mixed;
}

int main(int argc, char **argv) {
    Set flags = empty_set();
    int opt = 0;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a':
            flags = insert_set(HEAP, flags);
            flags = insert_set(INSERT, flags);
            flags = insert_set(SHELL, flags);
            flags = insert_set(QUICK, flags);
            break;
        case 'e': flags = insert_set(HEAP, flags); break;
        case 'i': flags = insert_set(INSERT, flags); break;
        case 's': flags = insert_set(SHELL, flags); break;
        case 'q': flags = insert_set(QUICK, flags); break;
        case 'h': flags = insert_set(HELP, flags); break;
        case 'r':
            flags = insert_set(SEED, flags);
            seed = atoi(optarg);
            break;
        case 'n':
            flags = insert_set(LENGTH, flags);
            length = atoi(optarg);
            break;
        case 'p':
            flags = insert_set(PRINTNUM, flags);
            printnum = atoi(optarg);
            break;
        case '?': message(); break;
        }
    }
    if (argc <= 1) {
        message();
    }
    if (!(member_set(HELP, flags))) {
        if (member_set(HEAP, flags)) {
            reset(&stats);
            uint32_t *mixed = arraymaker(length);
            heap_sort(&stats, mixed, length);
            printf("Heap Sort, %d elements, %lu moves, %lu compares\n", length, stats.moves,
                stats.compares);
            int j = 1;
            for (int i = 0; i < printnum; i++) {
                printf("%13" PRIu32, mixed[i]);
                if (j % 5 == 0) {
                    printf("\n");
                }
                j += 1;
            }
            free(mixed);
        }
        if (member_set(INSERT, flags)) {
            reset(&stats);
            uint32_t *mixed = arraymaker(length);
            insertion_sort(&stats, mixed, length);
            printf("Insertion Sort, %d elements, %lu moves, %lu compares\n", length, stats.moves,
                stats.compares);
            int j = 1;
            for (int i = 0; i < printnum; i++) {
                printf("%13" PRIu32, mixed[i]);
                if (j % 5 == 0) {
                    printf("\n");
                }
                j += 1;
            }
            free(mixed);
        }
        if (member_set(SHELL, flags)) {
            reset(&stats);
            uint32_t *mixed = arraymaker(length);
            shell_sort(&stats, mixed, length);
            printf("Shell Sort, %d elements, %lu moves, %lu compares\n", length, stats.moves,
                stats.compares);
            int j = 1;
            for (int i = 0; i < printnum; i++) {
                printf("%13" PRIu32, mixed[i]);
                if (j % 5 == 0) {
                    printf("\n");
                }
                j += 1;
            }
            free(mixed);
        }
        if (member_set(QUICK, flags)) {
            reset(&stats);
            uint32_t *mixed = arraymaker(length);
            quick_sort(&stats, mixed, length);
            printf("Quick Sort, %d elements, %lu moves, %lu compares\n", length, stats.moves,
                stats.compares);
            int j = 1;
            for (int i = 0; i < printnum; i++) {
                printf("%13" PRIu32, mixed[i]);
                if (j % 5 == 0) {
                    printf("\n");
                }
                j += 1;
            }
            free(mixed);
        }
    } else {
        message();
    }
    return 0;
}

/***********************************
  *Description:
     Prints the help message and shows
     users how to interact with the
     program
  ***********************************/
void message() {
    printf("SYNOPSIS\n    A collection of comparison-based sorting algorithms.\n\n");
    printf("USAGE\n    ./sorting [-haeisqn:p:r:] [-n length] [-p elements] [-r seed]\n\n");
    printf("OPTIONS\n    -a   enable all sorts.\n    -e   enable Heap Sort.\n    -i   enable "
           "Insertion Sort.\n "
           "   -s   enable Shell Sort.\n    -q   enable Quick Sort.\n    -n length   specify "
           "number of array elements (defult: 100).\n    -p elements   specify number of elements "
           "to print (default: 100).\n    -r seed   specify random seed (default: 13371453).\n   "
           " -h   Display program synopsis and usage.\n");
}
