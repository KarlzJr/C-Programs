#include "path.h"

#include "graph.h"
#include "stack.h"
#include "vertices.h"

#include <stdio.h>
#include <stdlib.h>
struct Path {
    Stack *vertices;
    uint32_t length;
};

Path *path_create(void) {
    Path *p = (Path *) malloc(sizeof(Path));
    if (p) {
        p->length = 0;
        p->vertices = stack_create(VERTICES);
    }
    return p;
}

void path_delete(Path **p) {
    stack_delete(&(*p)->vertices);
    free(*p);
    *p = NULL;
}

bool path_push_vertex(Path *p, uint32_t v, Graph *G) {
    bool status = false;
    uint32_t x;
    if (stack_empty(p->vertices)) {
        x = START_VERTEX;
    } else {
        stack_peek(p->vertices, &x);
    }
    if (stack_push(p->vertices, v)) {
        uint32_t a = graph_edge_weight(G, x, v);
        p->length += a;
        status = true;
    }
    return status;
}

bool path_pop_vertex(Path *p, uint32_t *v, Graph *G) {
    bool status = false;
    uint32_t x;
    if (stack_pop(p->vertices, v)) {
        if (stack_empty(p->vertices)) {
            x = START_VERTEX;
        } else {
            stack_peek(p->vertices, &x);
        }
        p->length -= graph_edge_weight(G, x, *v);
        status = true;
    }
    return status;
}

uint32_t path_vertices(Path *p) {
    return stack_size(p->vertices);
}

uint32_t path_length(Path *p) {
    return p->length;
}

void path_copy(Path *dst, Path *src) {
    dst->length = path_length(src);
    stack_copy(dst->vertices, src->vertices);
}

void path_print(Path *p, FILE *outfile, char *cities[]) {
    fprintf(outfile, "Path length: %u\n", path_length(p));
    printf("Path: ");
    stack_print(p->vertices, outfile, cities);
}
