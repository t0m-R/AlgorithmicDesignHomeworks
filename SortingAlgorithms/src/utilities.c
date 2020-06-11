#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "macro.h"


int get_min(const int *A, const size_t n) {
    int min = A[0];
    for(size_t i = 0; i < n; i++) {
        if (A[i] < min) min = A[i];
    }
    return min;
}


int get_max(const int *A, const size_t n) {
    int max = A[0];
    for(size_t i = 0; i < n; i++) {
        if (A[i] > max) max = A[i];
    }
    return max;
}


int int_pow(int base, int exp) {
    int result = 1;
    while (exp) {
        if (exp % 2) result *= base;
        exp /= 2;
        base *= base;
    }
    return result;
}


void swap(int *H, const int i, const int m, const size_t n) {
    if (i <= n && m <= n) {
        int tmp1 = H[i];
        int tmp2 = H[m];
        H[i] = tmp2;
        H[m] = tmp1;
    }
}


void swap_float(float *A, const int i, const int m, const size_t n) {
    if (i <= n && m <= n) {
        float tmp1 = A[i];
        float tmp2 = A[m];
        A[i] = tmp2;
        A[m] = tmp1;
    }
}


void reverse_array(int *A, const size_t n) {
    int i = (int)n - 1;
    int j = 0;

    while(i > j) {
        swap(A, i, j, n);
        i--;
        j++;
    }
}


void seq_fill_array(int *A, const size_t n) {
    for(size_t i = 0; i < n; i++) {
        A[i] = (int)i + 1;
    }
}


void zeros_fill_array(int *A, size_t n) {
    for (int i = 0; i < n; i++) {
        A[i] = 0;
    }
}


void rand_fill_array(int *A, const size_t n) {
    for (int i = 0; i < n; i++) {
        A[i] = rand() % MAX_VALUE;
    }
}


void rand_fill_array_unif(float *A, const size_t n) {
    for (int i = 0; i < n; i++) {
        A[i] = (float)rand() / (float)(RAND_MAX / 1.);
    }
}


void rand_fill_array_digits(int *A, const size_t n, const int d) {
    for (int i = 0; i < n; i++) {
        A[i] = rand() % (int_pow(10, d) - int_pow(10, d - 1) ) + int_pow(10, d - 1);
    }
}


void print_array(const int *A, const size_t n) {
    printf("\n[ ");
    for (size_t i = 0; i < n-1; i++) {
        printf("%d, ", A[i]);
    }
    printf("%d ]", A[n-1]);
}


void print_array_float(const float *A, const size_t n) {
    printf("\n[ ");
    for (size_t i = 0; i < n-1; i++) {
        printf("%.3f, ", A[i]);
    }
    printf("%.3f ]", A[n-1]);
}


double get_execution_time(const struct timespec b_time,
                          const struct timespec e_time)
{
    return (double)(e_time.tv_sec-b_time.tv_sec) +
            (double)(e_time.tv_nsec-b_time.tv_nsec)/1E9;
}



