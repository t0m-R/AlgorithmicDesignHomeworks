#include <stdlib.h>

#define LENGTH(x) (sizeof(x)/sizeof((x)[0]))


void fill_array(int *A, const size_t n) {
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100000;
    }
}


int get_root(const int *H) {
    return H[0];
}


int right_child(const int *H, const int i, const size_t n) {
    if ((2*(i+1)+1) <= n ) {
        return H[2 * (i + 1)];
    } else {
        return (int)(1./0.);
    }
}


int right_idx(const int i, const size_t n) {
    if ((2*(i+1)+1) <= n ) {
        return 2*(i+1);
    } else {
        return -1;
    }
}


int left_child(const int *H, const int i, const size_t n) {
    if ( 2*(i+1) <= n ) {
        return H[2 * (i + 1) - 1];
    } else {
        return (int)(1./0.);
    }
}


int left_idx(const int i, const size_t n) {
    if ( 2*(i+1) <= n ) {
        return 2*(i+1)-1;
    } else {
        return -1;
    }
}


int is_min(const int *A, const size_t n) {
    for (size_t i = 0; i <= (n - 2) / 2; i++) {
        if (left_child(A, i, n) < A[i]) return 0;
        if (right_idx(i, n) != -1 && A[2 * (i + 1)] < A[i] ) return 0;
    }
    return 1;
}


int is_max(const int *A, const size_t n) {
    for (size_t i = 0; i <= (n - 2) / 2; i++) {
        if (left_child(A, i, n) > A[i]) return 0;
        if (right_idx(i, n) != -1 && A[2 * (i + 1)] > A[i] ) return 0;
    }
    return 1;
}


void swap(int *H, const int i, const int m, const size_t n) {
    if (i <= n && m <= n ) {
        int tmp1 = H[i];
        int tmp2 = H[m];
        H[i] = tmp2;
        H[m] = tmp1;
    }
}


void heapify(int *H, const int i, const size_t n) {
    int m = i;

    int j[2] = {left_idx(i, n), right_idx(i, n)};

    for (int k = 0; k <= 1; ++k) {
        if (j[k] <= n && H[j[k]] <= H[m]) {
            m = j[k];
        }
    }

    if ( i != m ) {
        swap(H, i, m, n);
        heapify(H, m, n);
    }

}


void del_min(int *H, int* n) {
    H[0] = H[*n - 1];
    *n = *n - 1;
    heapify(H, 0, *n);
}


void build_heap(int *A, const size_t n) {
    for (int i = (int)(n / 2 - 1); i >= 0; i--) {
        heapify(A, i, n);
    }
}