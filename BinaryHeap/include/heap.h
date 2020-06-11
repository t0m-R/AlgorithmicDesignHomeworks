#ifndef BINARYHEAP_HEAP_H
#define BINARYHEAP_HEAP_H

void fill_array(int *A, size_t n);
int get_root(const int *H);
int right_child(const int *H, int i, size_t n);
int right_idx(int i, size_t n);
int left_child(const int *H, int i, size_t n);
int left_idx(int i, size_t n);
int is_min(const int *A, size_t n) ;
int is_max(const int *A, size_t n) ;
void swap(int *H, int i, int m, size_t n);
void heapify(int *H, int i, size_t n);
void del_min(int *H, int* n);
void build_heap(int *A, size_t n);

#endif // BINARYHEAP_HEAP_H