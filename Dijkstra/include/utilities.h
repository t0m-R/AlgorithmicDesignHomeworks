#ifndef DIJKSTRA_UTILITIES_H
#define DIJKSTRA_UTILITIES_H

Array build_array(size_t n);
void free_array(Array A);
void rand_fill_array(Array A);
void print_adjacency(Array A);
double get_execution_time(struct timespec b_time, struct timespec e_time);

#endif // DIJKSTRA_UTILITIES_H
