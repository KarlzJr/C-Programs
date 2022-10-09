#include "graph.h"
#include "path.h"
#include "stack.h"
#include "vertices.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define OPTIONS "uvho:i:"
#define BLOCK   1024
void dfs(Graph *G, uint32_t v, Path *curr, Path *shortest, char *cities[], FILE *outfile);
void message();
static bool uflag = false, vflag = false, hflag = false;
uint32_t counter = 0;

int main(int argc, char **argv) {
    int opt = 0;

    char buffer[BLOCK];

    FILE *infile = stdin;
    FILE *outfile = stdout;
    uint32_t numvertices;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'u': uflag = true; break;
        case 'v': vflag = true; break;
        case 'i': infile = fopen(optarg, "r"); break;
        case 'o': outfile = fopen(optarg, "w"); break;
        case 'h': hflag = true; break;
        case '?': message(); break;
        }
    }
    fscanf(infile, "%d", &numvertices);
    if (!(hflag)) {
        if (numvertices > VERTICES) {
            fprintf(stderr, "Number of numvertices must be less than %d", numvertices);
            return 0;
        }
        char *c[numvertices];
        for (uint32_t i = 0; i < numvertices + 1; i += 1) {
            fgets(buffer, BLOCK, infile);
            c[i] = strdup(buffer);
            c[i][strlen(c[i]) - 1] = '\0';
        }

        char *cities[numvertices];
        for (uint32_t i = 0; i < numvertices; i += 1) {
            cities[i] = c[i + 1];
        }

        Graph *G = graph_create(numvertices, uflag);
        uint32_t i, j, k;
        while (fscanf(infile, "%d %d %d", &i, &j, &k) == 3) {
            graph_add_edge(G, i, j, k);
        }
        Path *current_path = path_create();
        Path *shortest_path = path_create();

        dfs(G, START_VERTEX, current_path, shortest_path, cities, outfile);
        if (path_length(shortest_path) == 0) {
            printf("Theres no where to go.\n");
        } else {
            path_print(shortest_path, outfile, cities);
            fprintf(outfile, "Total recursive calls: %u\n", counter);
        }
        fclose(infile);
        fclose(outfile);

        graph_delete(&G);
        path_delete(&current_path);
        path_delete(&shortest_path);
        for (uint32_t i = 0; i < numvertices + 1; i += 1) {
            free(c[i]);
        }
    }
}

//cites: took alot from what Dr. Long showed in lecture,I had alot of issues with the psudocode in the doc
void dfs(Graph *G, uint32_t v, Path *curr, Path *shortest, char *cities[], FILE *outfile) {
    if (path_length(curr) >= path_length(shortest) && path_length(shortest) != 0) {
        return;
    }
    if (path_vertices(curr) == graph_vertices(G) && graph_has_edge(G, v, START_VERTEX)) {
        path_push_vertex(curr, START_VERTEX, G);
        if (path_length(curr) < path_length(shortest) || path_length(shortest) == 0) {
            path_copy(shortest, curr);
            if (vflag) {
                path_print(shortest, outfile, cities);
            }
        }
        path_pop_vertex(curr, &v, G);
    }

    if (counter == 0) {
        path_push_vertex(curr, START_VERTEX, G);
    }

    counter += 1;
    graph_mark_visited(G, v);
    for (uint32_t i = 0; i < graph_vertices(G); i += 1) {
        if (graph_has_edge(G, v, i) && !(graph_visited(G, i))) {
            path_push_vertex(curr, i, G);
            dfs(G, i, curr, shortest, cities, outfile);
            path_pop_vertex(curr, &i, G);
        }
    }
    graph_mark_unvisited(G, v);
}

void message() {
    printf("SYNOPSIS\n    A collection of comparison-based sorting algorithms.\n\n");
    printf("USAGE\n    ./sorting [-haeisqn:p:r:] [-n length] [-p elements] [-r seed]\n\n");
    printf("OPTIONS\n    -u   Use and unuflag Graph.\n    -v   Enable Program Verbose "
           "printing.\n    -i   Input Containing Graph. (default: stdin)\n "
           "   -o   output of computed path.(default: stdout)\n     -h   Display program synopsis "
           "and usage.\n");
}
