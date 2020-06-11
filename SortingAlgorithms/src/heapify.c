#include <stdlib.h>
#include "utilities.h"


int right_idx(int i, size_t n) {
    if ((2*(i+1)+1) <= n ) {
        return 2*(i+1);
    } else {
        return -1;
    }
}


int left_idx(int i, size_t n) {
    if ( 2*(i+1) <= n ) {
        return 2*(i+1)-1;
    } else {
        return -1;
    }
}


void heapify(int *H, const int i, const size_t n) {
    int m = i;

    int j[2] = {left_idx(i, n), right_idx(i, n)};

    for (int k = 0; k <= 1; ++k) {
        if (j[k] <= n && H[j[k]] >= H[m]) {
            m = j[k];
        }
    }

    if ( i != m ) {
        swap(H, i, m, n);
        heapify(H, m, n);
    }

}


void build_heap(int *A, const size_t n) {
    for (int i = (int)(n / 2 - 1); i >= 0; i--) {
        heapify(A, i, n);
    }
}