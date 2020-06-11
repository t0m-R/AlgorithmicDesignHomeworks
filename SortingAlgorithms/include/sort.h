#ifndef SORTINGALGORITHMS_SORT_H_
#define SORTINGALGORITHMS_SORT_H_

#include "vector.h"

void insertion_sort(int *A, size_t n);
int partition(int *A, int l, int h, int p, size_t n);
void quicksort(int *A, int l, int h, size_t n);
void quicksort_best_case(int *A, size_t n);
void quicksort_best_case_aux(int *A, size_t start, size_t end, size_t n);
void heapsort(int *A, size_t s);
void counting_sort(const int *A, int *B, int bound, size_t n);
void radix_sort (int *A, size_t n, int digits);
void radix_sort_aux (int *A, size_t n, int div);
void bucket_sort (float *A, size_t n);
void bucket_sort_aux(float *A, size_t n);
int select_pivot(int l, int r);
int selection(int *A, int i, int l, int r, size_t n);


#endif // SORTINGALGORITHMS_SORT_H_
