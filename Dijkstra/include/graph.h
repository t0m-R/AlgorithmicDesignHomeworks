#ifndef DIJKSTRA_GRAPH_H
#define DIJKSTRA_GRAPH_H

#include "stack.h"

void build_graph(Graph* G, Array weights);
void reset_graph(Graph* G);
void free_graph(Graph* G);
void shortest_path(Graph* G, size_t dest);

#endif // DIJKSTRA_GRAPH_H
