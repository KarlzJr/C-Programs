#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "node.h"

Node *node_create(uint8_t symbol, uint64_t frequency) {
    Node *n = (Node *) malloc(sizeof(Node));
    if (n) {
        n->symbol = symbol;
        n->frequency = frequency;
        n->left = NULL;
        n->right = NULL;
    }
    return n;
}

void node_delete(Node **n) {
    if (*n) {
        free(*n);
        *n = NULL;
    }
}

Node *node_join(Node *left, Node *right) {
    uint64_t x = left->frequency + right->frequency;
    Node *n = node_create('$', x);
    n->left = left;
    n->right = right;
    return n;
}
/*
void node_print(Node *n) {
    if (n->left == NULL && n->right == NULL) {
        printf("Leaf Symbol and Frequency: '%c' %lu\n", n->symbol, n->frequency);
    }

    if (n->left != NULL) {
        node_print(n->left);
    }
    if (n->right != NULL) {
        node_print(n->right);
    }
}*/
