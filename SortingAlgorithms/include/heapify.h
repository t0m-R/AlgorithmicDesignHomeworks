#ifndef SORTINGALGORITHMS_HEAPIFY_H
#define SORTINGALGORITHMS_HEAPIFY_H

int right_idx(int i, size_t n);
int left_idx(int i, size_t n);
void heapify(int *H, int i, size_t n);
void build_heap(int *A, size_t n);

#endif // SORTINGALGORITHMS_HEAPIFY_H
