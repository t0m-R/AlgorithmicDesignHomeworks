#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"
#include "utilities.h"


void build_graph(Graph* G, Array weights) {
    size_t n = weights.size;
    Node* v = (Node*)malloc(sizeof(Node) * n);
    G -> V = v;
    G -> size = n;
    G -> weights = weights;

    for(size_t i = 0; i < n; i++) {
        (G -> V[i]).d = INT_MAX;
        (G -> V[i]).label = i;
        (G -> V[i]).pred = NULL;
    }
}


void reset_graph(Graph* G) {
    size_t n;
    n = G -> size;
    for(size_t i = 0; i < n; i++) {
        (G -> V[i]).d = INT_MAX;
        (G -> V[i]).pred = NULL;
    }
}


void free_graph(Graph* G) {

    free(G -> V);
    free_array(G->weights);

}


void shortest_path(Graph* G, size_t dest) {
    Node v = G -> V[dest];
    int dist = v.d;
    if (dist == INT_MAX || dist == -INT_MAX) {
        printf("Destination: %ld. No paths.\n", dest);
        return;
    }
    printf("Destination: %ld. Distance: %d. Path: \t\t", dest, dist);
    while (v.pred != NULL) {
        printf("%ld <- ", v.label);
        v = *v.pred;
    }
    printf("%ld\n", v.label);
}