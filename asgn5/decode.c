#include "header.h"
#include "io.h"
#include "pq.h"
#include "defines.h"
#include "huffman.h"
#include "node.h"
#include "stack.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define OPTIONS "vho:i:"

void message();
static bool vflag = false, hflag = false;
int main(int argc, char **argv) {
    int opt = 0;

    //    char buffer[BLOCK];

    FILE *infile = stdin;
    FILE *outfile = stdout;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'v': vflag = true; break;
        case 'i': infile = fopen(optarg, "r"); break;
        case 'o': outfile = fopen(optarg, "w"); break;
        case 'h': hflag = true; break;
        case '?': message(); break;
        }
    }
}

void message() {
    printf("SYNOPSIS\n    A Huffman Decoder.\n   Decompresses a file using the Huffman coding "
           "algorithm.\n\n");
    printf("USAGE\n    ./decode [-h] [-i infile] [-o outfile]\n\n");
    printf("OPTIONS\n");
    printf("   -v   Print compression statistics.\n");
    printf("   -i   Input File to Decompress.\n ");
    printf("   -o   output of decompressed data.\n");
    printf("   -h   Display program synopsis and usage.\n");
}
