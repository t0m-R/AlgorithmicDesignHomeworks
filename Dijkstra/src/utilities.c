#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

#define MAX_WEIGHT 6

Array build_array(size_t n) {
    int** A = (int** )malloc(sizeof(int* ) * n);
    for (size_t i = 0; i < n; i++) {
        A[i] = (int* )malloc(sizeof(int) * n);
    }
    Array MAT = {A, n};
    return MAT;
}


void free_array(Array A) {
    for (size_t i = 0; i < A.size; i++) {
        free(A.matrix[i]);
    }
    free(A.matrix);
}


void rand_fill_array(Array A)
{
    int k;
    for (size_t i=0; i< A.size; i++) {
        for (size_t j=0; j< A.size; j++) {
            k = rand() % (MAX_WEIGHT);
            if (rand() % 2 == 0){
                A.matrix[i][j] = 0;
            } else {
              A.matrix[i][j] = k;
            }
        }
    }
}


void print_adjacency(const Array A) {

    printf("\t\t");
    for(size_t j =0; j < A.size; j++) {
        printf("%d\t", (int)j);
    }
    printf("\n\n");
    for(size_t i = 0; i < A.size; i++) {

        printf("%d\t\t", (int)i);
        for(size_t j =0; j < A.size; j++) {
            printf("%d\t", A.matrix[i][j]);
        }
        printf("\n");
    }
}


double get_execution_time(const struct timespec b_time,
                          const struct timespec e_time)
{
    return (double)(e_time.tv_sec-b_time.tv_sec) +
           (double)(e_time.tv_nsec-b_time.tv_nsec)/1E9;
}