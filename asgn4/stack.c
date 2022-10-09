#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

struct Stack {
    uint32_t top;
    uint32_t capacity;
    uint32_t *items;
};

Stack *stack_create(uint32_t capacity) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    if (s) {
        s->top = 0;
        s->capacity = capacity;
        s->items = (uint32_t *) calloc(capacity, sizeof(uint32_t));
        if (!s->items) {
            free(s);
            s = NULL;
        }
    }
    return s;
}

void stack_delete(Stack **s) {
    if (*s && (*s)->items) {
        free((*s)->items);
        free(*s);
        *s = NULL;
    }
}

uint32_t stack_size(Stack *s) {
    return s->top;
}

bool stack_empty(Stack *s) {
    //  bool status = false;
    //if (s->top <= 0) {
    //    status = true;
    //}
    return (s->top == 0);
}

bool stack_full(Stack *s) {
    bool status = false;
    if (s->top == s->capacity) {
        status = true;
    }
    return status;
}

bool stack_push(Stack *s, uint32_t x) {
    bool status = false;
    if (!(stack_full(s))) {
        s->items[s->top] = x;
        s->top += 1;
        status = true;
    }
    return status;
}

bool stack_pop(Stack *s, uint32_t *x) {
    bool status = false;
    if (stack_empty(s)) {
        status = false;
    } else {
        s->top -= 1;
        *x = s->items[s->top];
        status = true;
    }
    return status;
}

bool stack_peek(Stack *s, uint32_t *x) {
    bool status = false;
    if (stack_empty(s)) {
        status = false;
    } else {
        s->top -= 1;
        *x = s->items[s->top];
        s->top += 1;
        status = true;
    }
    return status;
}

void stack_copy(Stack *dst, Stack *src) {
    dst->top = src->top;
    for (uint32_t i = 0; i < src->top; i++) {
        dst->items[i] = src->items[i];
    }
}

void stack_print(Stack *s, FILE *outfile, char *cities[]) {
    for (uint32_t i = 0; i < s->top; i++) {
        fprintf(outfile, "%s", cities[s->items[i]]);
        if (i + 1 != s->top) {
            fprintf(outfile, " -> ");
        }
    }
    fprintf(outfile, "\n");
}
