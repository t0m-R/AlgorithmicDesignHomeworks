//
// Created by brobr on 6/10/2020.
//

#ifndef DIJKSTRA_STACK_H
#define DIJKSTRA_STACK_H

//GRAPH
typedef struct Array {
    int** matrix;
    size_t size;
} Array;


typedef struct Node {
    int d;
    struct Node* pred;
    size_t label;
} Node;


typedef struct Graph {
    Array weights;
    Node* V;
    size_t size;
} Graph;

//ARRAY IMPLEMENTATION
typedef struct Queue {
    Node* V;
    size_t* visited;
    size_t size;
} Queue;

//HEAP IMPLEMENTATION
typedef struct HeapData {
    size_t idx;
    int* key;
} HeapData;


typedef struct Heap {
    HeapData* H;
    size_t size;
} Heap;

#endif // DIJKSTRA_STACK_H
