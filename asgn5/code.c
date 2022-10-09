#include "code.h"
#include <unistd.h>

bool status = false;
Code code_init(void) {
    Code c;
    c.top = 0;
    return c;
}

uint32_t code_size(Code *c) {
    return c->top;
}

bool code_empty(Code *c) {
    return (c->top == 0);
}

bool code_full(Code *c) {
    return ((code_size(c)) > 32);
}

bool code_set_bit(Code *c, uint32_t i) {
    status = false;
    if (i < MAX_CODE_SIZE) {
        c->bits[i] = 1;
        status = true;
    }
    return status;
}

bool code_clr_bit(Code *c, uint32_t i) {
    status = false;
    if (i < MAX_CODE_SIZE) {
        c->bits[i] = 0;
        status = true;
    }
    return status;
}

bool code_get_bit(Code *c, uint32_t i) {
    status = false;
    if (i < MAX_CODE_SIZE && c->bits[i] == 1) {
        status = true;
    }
    return status;
}
bool code_push_bit(Code *c, uint8_t bit) {
    status = false;
    if (code_full(c)) {
        status = false;
    } else {
        //was told to do bitwise arithmtic. going to try
        c->bits[c->top / 8] |= (bit << (c->top % 8));
        c->top += 1;
        status = true;
    }
    return status;
}
bool code_pop_bit(Code *c, uint8_t *bit) {
    if (!(code_empty(c))) {
        status = false;
        c->top -= 1;
        *bit = (c->bits[c->top / 8] >> (c->top % 8) & 0x1);
        c->bits[c->top / 8] &= ~(0x1 << (c->top % 8));
        return true;
    } else {
        return false;
    }
}
