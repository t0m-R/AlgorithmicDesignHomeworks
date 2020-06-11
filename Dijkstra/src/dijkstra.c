#include <stdlib.h>
#include <limits.h>
#include "stack.h"


//ARRAY IMPLEMENTATION


Queue build_queue(Graph* G) {

    Node* v = (Node*)malloc(sizeof(Node) * G -> size);
    size_t* visited = (size_t*)malloc(sizeof(size_t) * G -> size);

    for(size_t i = 0; i < G -> size; i++) {
        v[i] = G -> V[i];
        visited[i] = 0;
    }
    Queue q = {v, visited, G -> size};
    return q;
}


void free_queue(Queue* Q) {
    free(Q -> V);
    free(Q -> visited);
}


Node get_min_queue(Queue* Q) {
    int min = INT_MAX; // initialize as infinity
    int idx = 0;
    for(size_t i = 0; i < Q -> size; i++) {
        if (((Q -> V[i]).d <= min) && (Q -> visited[i] == 0) )  {
            min = (Q -> V[i]).d;
            idx = i;
        }
    }
    Q -> visited[idx] = 1; // skip already visited
    return Q -> V[idx];
}



void update_distance(Node* q_vertex, Node* v, int dist) {
    v -> d = dist;
    q_vertex -> d = dist;
}


void relax(Queue* Q, Node* u, Graph* G, int w, size_t i) {
    if ( (u -> d + w) < ((G -> V[i]).d) ) {
        update_distance(&(Q->V[i]), &(G->V[i]), u->d + w);
        int pred_label = u -> label;
        (G -> V[i]).pred = &(G -> V[pred_label]);
    }
}


void dijkstra_queue(Graph* G, size_t start) {
    ( (G -> V)[start] ).d = 0;
    Queue Q = build_queue(G);
    Node min;
    size_t steps = 0;
    while(steps < G -> size) {
        min = get_min_queue(&Q);
        if(min.d != INT_MAX) { //if true path doesn't exist
            for (size_t i = 0; i < G -> size; i++) {
                if ((G -> weights).matrix[min.label][i] != 0 && min.label != i) { //skip empty edges
                    int w = (G -> weights).matrix[min.label][i];
                    relax(&Q, &min, G, w, i);
                }
            }
        }
        steps += 1;
    }
    free_queue(&Q);
}



// HEAP IMPLEMENTATION


void swap(Heap* H, const size_t i, const size_t m) {
    const size_t size = H -> size;
    if (i <= size - 1 && m <= size - 1) {
        HeapData tmp1 = H -> H[i];
        HeapData tmp2 = H -> H[m];

        H -> H[i] = tmp2;
        H -> H[m] = tmp1;
    }
}


size_t get_parent(const size_t i) {
    return (i+1)/2 - 1;
}


size_t right_idx(const size_t i) {
    return 2*(i+1);
}


size_t left_idx(const size_t i) {
    return 2*(i+1)-1;
}


void heapify(Heap* H, const size_t i) {
    size_t size = H -> size;

    size_t l = left_idx(i);
    size_t r = right_idx(i);
    size_t max;

    if ( l <= size-1 && *((H -> H[l]).key) <= *((H -> H[i]).key) ) {
        max = l;
    } else {
        max = i;
    }

    if ( r <= size-1 && *((H -> H[r]).key) <= *((H -> H[max]).key) ) {
        max = r;
    }

    if (max != i ) {
        swap(H, i, max);
        heapify(H, max);
    }

}


void build_heap(Graph* G, Heap* H, int *dist) {
    size_t size = G -> size;

    for (size_t i = 0; i < size; i++) {
        (H -> H[i]).idx = i;
        (H -> H[i]).key = &dist[i];
    }

    for (size_t i = 0; i <= (size/2 - 1); i++) {
        heapify(H, (size / 2 - 1) - i);
    }
}


HeapData get_min_heap(Heap* H) {
    HeapData min = H -> H[0];
    H -> H[0] = H -> H[H -> size - 1];
    H -> size -= 1;
    if (H -> size > 0) heapify(H, 0);
    return min;
}


void dijkstra_heap(Graph* G, size_t start) {

    ( (G -> V)[start] ).d = 0;
    size_t size = G -> size;
    int distance[size];

    for (size_t i = 0; i < size; i++ ) {
        distance[i] = INT_MAX;
    }

    HeapData h[size];
    distance[start] = 0;
    Heap q = {h, size};
    build_heap(G, &q, distance);
    HeapData min;

    while (q.size > 0) {
        min = get_min_heap(&q);
        if (*(min.key) != INT_MAX) { //if true path doesn't exist
            for (size_t i = 0; i < G -> size; i++) {
                if ((G -> weights).matrix[min.idx][i] != 0 ) { //skip empty edges
                    int w = (G -> weights).matrix[min.idx][i];
                    int new_dist = *(min.key) + w;
                    if ((new_dist) < ((G -> V[i]).d) ) { //if true update distance and predecessor
                        distance[i] = new_dist;
                        size_t pred_label = min.idx;
                        (G -> V[i]).pred = &(G -> V[pred_label]);
                        (G -> V[i]).d = new_dist;
                        size_t j = 0;
                        while(j < q.size) { //search updated index
                            if ((q.H[j]).idx == i) {break;}
                            j++;
                        }
                        while ( (j != 0) && (*((q.H[j]).key) < *((q.H[get_parent(j)]).key) )) { //restore heap after update
                            swap(&q, j, get_parent(j));
                            j = get_parent(j);
                        }

                    }
                }
            }
        }
    }
}