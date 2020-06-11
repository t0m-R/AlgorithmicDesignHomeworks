#include <stdlib.h>
#include "heapify.h"
#include "utilities.h"
#include "vector.h"


void insertion_sort(int *A, const size_t n) {

    size_t j;

    for (size_t i = 1; i < n; i++) {
        j = i;
        while (j > 0 && A[j] < A[j - 1]) {
            swap(A, (int)j - 1, j, n);
            j -= 1;
        }
    }
}


int partition(int *A, int l, int h, int p, const size_t n) {

    swap(A, l, p, n);
    p = l;
    l = l + 1;

    while (l <= h) {
        if (A[l] > A[p]) {
            swap(A, l, h, n);
            h -= 1;
        } else {
            l += 1;
        }
    }
    swap(A, p, h, n);
    return h;
}


void quicksort(int *A, int l, int h, const size_t n) {
    int p;
    if (l < h) {
        p = partition(A, l, h, l, n);

        quicksort(A, l, p - 1, n);
        quicksort(A, p + 1, h, n);
    }
}


void quicksort_best_case_aux(int *A, size_t start, size_t end, size_t n) {
    int count = (int)(end - start);
    if(count<3) return;
    int mid = (int)start + (count - 1) / 2;
    quicksort_best_case_aux(A, start, mid, n);
    swap(A, start, mid, n);
    quicksort_best_case_aux(A, mid + 1, end, n);
}


void quicksort_best_case(int *A, size_t n) {
    seq_fill_array(A, n);
    quicksort_best_case_aux(A, 0, n - 1, n);
}


void heapsort(int *A, const size_t s) {
    size_t n = s;

    build_heap(A, n);

    for (size_t i = n - 1; i >= 1; i--) {
        swap(A, 0, i, n);
        n -= 1;
        heapify(A, 0, n);
    }
}


void counting_sort(const int *A, int *B, int bound, const size_t n) {
    int C[bound];
    zeros_fill_array(C, bound);

    for (size_t i = 0; i < n; i++) {
        C[A[i]-1] ++;
    }

    for (size_t j = 1; j < bound; j++) {
        C[j] += C[j-1];
    }

    for (int i = (int)n - 1; i >= 0; i--) {
        B[C[A[i]-1]-1] = A[i];
        C[A[i]-1] --;
    }
}


void radix_sort_aux (int *A, const size_t n, const int div) {

    int B[n];
    int C[10] = {0};

    for (size_t i = 0; i < n; i++) {
        C[(A[i] / div) % 10 ] += 1;
    }

    for (size_t j = 1; j < 10; j++) {
        C[j] += C[j-1];
    }

    for (int i = (int) n - 1; i >= 0; i--) {
        B[C[(A[i] / div) % 10 ] - 1] = A[i];
        C[(A[i] / div) % 10 ] -= 1;
    }

    for (size_t i = 0; i < n; i++) {
        A[i] = B[i];
    }
}


void radix_sort (int *A, const size_t n, const int digits) {

    int div = 1;

    for (int exp = 1; exp <= digits; exp++) {
        radix_sort_aux(A, n, div);
        div *= 10;
    }
}


void bucket_sort_aux(float *A, const size_t n) {

    size_t j;

    for (size_t i = 1; i < n; i++) {
        j = i;
        while (j > 0 && A[j] < A[j - 1]) {
            swap_float(A, (int)j - 1, j, n);
            j -= 1;
        }
    }
}


void bucket_sort (float *A, const size_t n) {
    Vector B[n];
    for (size_t i = 0; i < n; i++) {
        build_vector(&B[i], 2);
    }

    for (size_t i = 0; i < n; i++) {
        push_back(&(B[(int) (A[i] * n)]), A[i]);
    }

    int i = 0;

    for (size_t j = 0; j < n; j++) {
        bucket_sort_aux(B[j].data, B[j].size);
        for (size_t s = 0; s < B[j].size; s++) {
            A[i] = B[j].data[s];
            i += 1;
        }
        del_vector(&B[j]);
    }

}


int select_pivot(int l, int r) {

    if (l == r) return l;
    int mid[3] = { l + rand()%(r - l), l + rand()%(r - l), l + rand()%(r - l) };
    int max = get_max(mid, 3);
    int min = get_min(mid, 3);

    return mid[0] + mid[1] + mid[2] - max - min;
}


int selection(int *A, int i, int l, int r, const size_t n) {

    int j = select_pivot(l, r);

    int k = partition(A, l, r, j, n);

    if (i == k) {
        return A[k];
    } else {
        if (i < k) {
            return selection(A, i, l, k - 1, n);
        } else {
            return selection(A, i, k + 1, r, n);
        }
    }
}