#include "graph.h"

#include "vertices.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Graph {
    uint32_t vertices;
    bool undirected;
    bool visited[VERTICES];
    uint32_t matrix[VERTICES][VERTICES];
};

Graph *graph_create(uint32_t vertices, bool undirected) {
    Graph *G = (Graph *) calloc(1, sizeof(Graph));
    G->vertices = vertices;
    G->undirected = undirected;
    return G;
}

void graph_delete(Graph **G) {
    free(*G);
    *G = NULL;
    return;
}

uint32_t graph_vertices(Graph *G) {
    return G->vertices;
}

bool graph_add_edge(Graph *G, uint32_t i, uint32_t j, uint32_t k) {
    static bool status = false;
    if (i < (G->vertices) && j < (G->vertices)) {
        G->matrix[i][j] = k;
        status = true;
        if (G->undirected) {
            G->matrix[j][i] = k;
            status = true;
        }
    } else {
        status = false;
    }
    return status;
}

bool graph_has_edge(Graph *G, uint32_t i, uint32_t j) {
    static bool status = false;
    if (i < VERTICES && j < VERTICES) {
        uint32_t k = G->matrix[i][j];
        if (k > 0) {
            status = true;
        } else {
            status = false;
        }
    } else {
        status = false;
    }
    return status;
}

uint32_t graph_edge_weight(Graph *G, uint32_t i, uint32_t j) {
    uint32_t e = 0;
    if (graph_has_edge(G, i, j) == true) {
        e = G->matrix[i][j];
    } else {
        e = 0;
    }
    return e;
}

bool graph_visited(Graph *G, uint32_t v) {
    return G->visited[v];
}

void graph_mark_visited(Graph *G, uint32_t v) {
    if (v < VERTICES) {
        G->visited[v] = true;
    }
}

void graph_mark_unvisited(Graph *G, uint32_t v) {
    if (v < VERTICES) {
        G->visited[v] = false;
    }
}
