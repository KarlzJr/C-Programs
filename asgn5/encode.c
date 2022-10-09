#include "header.h"
#include "io.h"
#include "pq.h"
#include "defines.h"
#include "huffman.h"
#include "node.h"
#include "stack.h"

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define OPTIONS "vho:i:"
void post_order(Node *root);
void create_histogram(int infile, uint8_t *buf, uint64_t hist[ALPHABET]);
void message();
int tree[768];
int tree_counter = 0;

int main(int argc, char **argv) {
    int opt = 0;
    bool vflag = false;

    int infile = STDIN_FILENO;
    int outfile = STDOUT_FILENO;

    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'v': vflag = true; break;
        case 'i': infile = open(optarg, O_RDONLY, 0); break;
        case 'o': outfile = open(optarg, O_WRONLY, 1); break;
        case 'h': message(); break;
        case '?': message(); break;
        }
    }
    /*
    uint8_t buffer[BLOCK];
    uint64_t h[ALPHABET];
    create_histogram(infile, buffer, h);

    Node *r = build_tree(h);

    Code table[ALPHABET];
    build_codes(r, table);

    uint16_t tree_size = 0;
    for (uint32_t i = 0; i < ALPHABET; i += 1) {
        if (h[i] > 0) {
            tree_size += 1;
        }
    }
    tree_size *= 3;
    tree_size -= 1;

    Header header;
    header.magic = MAGIC;
    struct stat file_buf;
    fstat(infile, &file_buf);
    fchmod(outfile, file_buf.st_mode);
    header.permissions = file_buf.st_mode;
    header.tree_size = tree_size;
    header.file_size = bytes_read;
    write_bytes(outfile, (uint8_t *) &header, sizeof(Header));

    dump_tree(outfile, r);
    write_bytes(outfile, (uint8_t *) &tree, MAX_TREE_SIZE);

    lseek(infile, 0, SEEK_SET);

    uint32_t wr = read(infile, buffer, BLOCK);
    while (wr > 0) {
        for (uint32_t i = 0; i < wr; i += 1) {
            write_code(outfile, &table[buffer[i]]);
        }
        wr = read(infile, buffer, BLOCK);
    }
    flush_codes(outfile);

    if (vflag) {
        fprintf(stderr, "Uncompressed file size: %lu bytes\n", header.file_size);
        fprintf(stderr, "Compressed file size: %lu bytes\n", bytes_written);
        fprintf(stderr, "Space saving: %lu bytes\n", (bytes_written / header.file_size) * 100);
    }

    delete_tree(&r);
    close(infile);
    close(outfile);
    return 0;
*/
}

void create_histogram(int infile, uint8_t *buf, uint64_t hist[ALPHABET]) {
    uint32_t counter = read_bytes(infile, buf, BLOCK);
    for (int32_t i = 0; i < ALPHABET; i += 1) {
        hist[i] = 0;
    }
    while (counter > 0) {
        for (uint32_t i = 0; i < counter; i += 1) {
            hist[buf[i]] += 1;
        }
        counter = read_bytes(infile, buf, BLOCK);
    }
    hist[0] += 1;
    hist[255] += 1;
}

void message() {
    printf("SYNOPSIS\n    A Huffman Encoder.\n   Compresses a file using the Huffman coding "
           "algorithm.\n\n");
    printf("USAGE\n    ./encode [-h] [-i infile] [-o outfile]\n\n");
    printf("OPTIONS\n");
    printf("   -v   Print compression statistics.\n");
    printf("   -i   Input File to Decompress.\n ");
    printf("   -o   output of decompressed data.\n");
    printf("   -h   Display program synopsis and usage.\n");
}
