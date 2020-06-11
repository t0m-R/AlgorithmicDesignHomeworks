#ifndef DIJKSTRA_DIJKSTRA_H
#define DIJKSTRA_DIJKSTRA_H

#include "stack.h"

// array version
Queue build_queue(Graph* G);
void free_queue(Queue* Q);
Node get_min_queue(Queue* Q);
void update_distance(Node* q_vertex, Node* v, int dist);
void relax(Queue* Q, Node* u, Graph* G, int w, size_t i);
void dijkstra_queue(Graph* G, size_t start);

//heap version
void swap(Heap* H, size_t i, size_t m);
size_t get_parent(size_t i);
size_t right_idx(size_t i);
size_t left_idx(size_t i);
void heapify(Heap* H, size_t i);
void build_heap(Graph* G, Heap* H, int *dist);
HeapData get_min_heap(Heap* H);
void dijkstra_heap(Graph* G, size_t start);

#endif // DIJKSTRA_DIJKSTRA_H
