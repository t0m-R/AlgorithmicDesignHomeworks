#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"
#include "utilities.h"
#include "graph.h"
#include "dijkstra.h"


int main() {

#define TEST

    printf("\n ### init tests ###\n");
    size_t n = 10;
    Graph G;
    Array weights = build_array(n);
    rand_fill_array(weights);

    printf("### Adjacency matrix of the directed graph ###\n\n");
    print_adjacency(weights);
    build_graph(&G, weights);


    printf("\n\n ### array / heap results ###\n\n");

    for(size_t i = 0; i < n; i++) {

    printf("# ARRAY: \t");
    dijkstra_queue(&G, 0);
    shortest_path(&G, i);
    reset_graph(&G);

    printf("#  HEAP:\t");
    dijkstra_heap(&G, 0);
    shortest_path(&G, i);
    reset_graph(&G);
    }

    free_graph(&G);

#ifdef TEST

    struct timespec b_time, e_time;

  printf("\n ###  benchmark ###\n");
  printf("\nsize\tt_array\t\tt_heap\n");

    for (size_t size = 1000; size < 10000; size = size + 1000) {
    weights= build_array(size);
    rand_fill_array(weights);
    build_graph(&G, weights);


    //array
    clock_gettime(CLOCK_REALTIME, &b_time);
      dijkstra_queue(&G, 0);
    clock_gettime(CLOCK_REALTIME, &e_time);
    printf("%ld\t%f\t", size, get_execution_time(b_time, e_time));

    reset_graph(&G);

    //heap
    clock_gettime(CLOCK_REALTIME, &b_time);
      dijkstra_heap(&G, 0);
    clock_gettime(CLOCK_REALTIME, &e_time);
    printf("%f\n", get_execution_time(b_time, e_time));

    free_graph(&G);

  }

#endif

    return 0;
}
