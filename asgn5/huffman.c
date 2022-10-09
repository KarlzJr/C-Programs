#include "huffman.h"

#include <unistd.h>
#include "code.h"
#include "defines.h"
#include "node.h"
#include "pq.h"
#include "stack.h"
#include "io.h"
Node *build_tree(uint64_t hist[static ALPHABET]) {
    PriorityQueue *q = pq_create(ALPHABET);
    Node *n;
    for (int i = 0; i < ALPHABET; i += 1) {
        if (hist[i] > 0) {
            n = node_create(i, hist[i]);
            enqueue(q, n);
        }
    }

    Node *j;
    Node *r;
    Node *l;

    while ((pq_size(q)) >= 1) {
        dequeue(q, &l);
        dequeue(q, &r);
        j = node_join(l, r);
        enqueue(q, j);
    }
    Node *root;
    dequeue(q, &root);
    pq_delete(&q);
    return root;
}

void build_codes(Node *root, Code table[static ALPHABET]) {
    Code c = code_init();
    uint8_t a;
    if (root) {
        if (root->left == NULL && root->right == NULL) {
            table[root->symbol] = c;
        } else {
            code_push_bit(&c, 0);
            build_codes(root->left, table);
            code_pop_bit(&c, &a);

            code_push_bit(&c, 1);
            build_codes(root->right, table);
            code_pop_bit(&c, &a);
        }
    }
}
void dump_tree(int outfile, Node *root) {
    if (root) {
        //post order traversal.
        dump_tree(outfile, root->left);
        dump_tree(outfile, root->right);
        if (!(root->left) && !(root->right)) {
            uint8_t var = 'L';
            write_bytes(outfile, &var, 1);
            write_bytes(outfile, &root->symbol, 1);
        } else {
            uint8_t var = 'I';
            write_bytes(outfile, &var, 1);
        }
    }
}

Node *rebuild_tree(uint16_t nbytes, uint8_t tree[static nbytes]) {
    Stack *s = stack_create(nbytes);
    Node *r;
    Node *l;
    for (uint32_t i = 0; i < nbytes; i += 1) {
        if (tree[i] == 'L') {
            Node *n = node_create(0, tree[i]);
            stack_push(s, n);
        } else if (tree[i] == 'I') {
            stack_pop(s, &r);
            stack_pop(s, &l);
            stack_push(s, node_join(l, r));
        }
    }
    Node *root;
    stack_pop(s, &root);
    stack_delete(&s);
    return root;
}

void delete_tree(Node **root) {
    if ((*root)->left != NULL) {
        delete_tree(&(*root)->left);
    }
    if ((*root)->right != NULL) {
        delete_tree(&(*root)->right);
    }
    node_delete(&(*root));
}
