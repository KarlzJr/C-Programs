#include "io.h"
#include "code.h"
#include "defines.h"

#include <fcntl.h>
#include <unistd.h>
uint8_t buf[BLOCK];
static int32_t ind = 0;
uint64_t bytes_read = 0;
uint64_t bytes_written = 0;

//struggling to get my code.c to work
void set_bit(uint8_t *b, uint32_t i) {
    uint8_t byte = b[i / 8];
    b[i / 8] = byte | 1 << (i % 8);
}

void clr_bit(uint8_t *b, uint32_t i) {
    uint8_t byte = b[i / 8];
    b[i / 8] = (byte & ~(1 << i % 8));
}

uint8_t get_bit(uint8_t *b, uint32_t i) {

    uint8_t bit = i % 8;
    uint8_t byte = b[i / 8];
    return (byte & (1 << bit)) >> (bit);
}
int read_bytes(int infile, uint8_t *buf, int nbytes) {
    int total = 0, bytes = 1;
    while (bytes > 0 && total != nbytes) {
        bytes = read(infile, buf, nbytes - total);
        total += bytes;
    }
    bytes_read += total;
    return total;
}

int write_bytes(int outfile, uint8_t *buf, int nbytes) {
    int total = 0, bytes = 1;
    while (bytes > 0 && total != nbytes) {
        bytes = write(outfile, buf, nbytes - total);
        total += bytes;
    }
    bytes_written += total;
    return total;
}

bool read_bit(int infile, uint8_t *bit) {
    int32_t bytes = read_bytes(infile, buf, BLOCK);
    int32_t end = 0;
    if (bytes != BLOCK) {
        end = bytes * 8;
    }
    *bit = get_bit(buf, ind);
    ind = (ind + 1) % BLOCK * 8;
    if (ind > end) {
        return false;
    } else {
        return true;
    }
}

void write_code(int outfile, Code *c) {
    for (uint32_t i = 0; i < code_size(c); i += 1) {
        int bit = get_bit(c->bits, i);
        if (bit == 1) {
            set_bit(buf, ind);
        } else if (bit == 0) {
            clr_bit(buf, ind);
        }
        ind += 1;
        if (ind == 8 * BLOCK) {
            write_bytes(outfile, buf, BLOCK);
            ind = 0;
        }
    }
}

void flush_codes(int outfile) {
    int nbytes;
    if (ind > 0) {
        if (ind % 8 == 0) {
            nbytes = ind / 8;
        } else {
            nbytes = (ind / 8) + 1;
        }
        write_bytes(outfile, buf, nbytes);
    }
}
