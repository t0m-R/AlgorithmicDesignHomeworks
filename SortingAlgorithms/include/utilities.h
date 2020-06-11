#ifndef SORTINGALGORITHMS_UTILITIES_H_
#define SORTINGALGORITHMS_UTILITIES_H_


int get_min(const int *A, size_t n);
int get_max(const int *A, size_t n);
int int_pow(int base, int exp);
void swap(int *H, int i, int m, size_t n);
void swap_float(float *A, int i, int m, size_t n);
void reverse_array(int *A, size_t n);
void seq_fill_array(int *A, size_t n);
void zeros_fill_array(int *A, size_t n);
void rand_fill_array(int *A, size_t n);
void rand_fill_array_unif(float *A, size_t n);
void rand_fill_array_digits(int *A, size_t n, int d);
void print_array(const int *A, size_t n);
void print_array_float(const float *A, size_t n);
double get_execution_time(struct timespec b_time, struct timespec e_time);

#endif // SORTINGALGORITHMS_UTILITES_H_
