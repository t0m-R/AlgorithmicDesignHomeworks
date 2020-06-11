#include <stdio.h>
#include <time.h>
#include "heap.h"

#define LENGTH(x) (sizeof(x)/sizeof((x)[0]))


double get_execution_time(const struct timespec b_time,
                          const struct timespec e_time)
{
    return (double)(e_time.tv_sec-b_time.tv_sec) +
           (double)(e_time.tv_nsec-b_time.tv_nsec)/1E9;
}


int main() {

#define TEST

    printf("\n ### init, root, min/max tests ###\n");
    int heap[6] = {1,2,3,4,5,6};
    int n = LENGTH(heap);
    printf("root: %d\n", get_root(heap));
    printf("size: %d\n", n);
    printf("is_min: %d\n", is_min(heap, n));
    printf("is_max: %d\n", is_max(heap, n));

    printf("\n ### del_min test ###\n");
    del_min(heap, &n);
    printf("root: %d\n", get_root(heap));
    printf("size: %d\n", n);

    printf("\n ### build_heap, childs, ids, min/max test ###\n");
    int H[6] = {6, 5, 4, 3, 2, 1};
    int size = LENGTH(H);
    build_heap(H, size);
    printf("root: %d\n", get_root(H));
    printf("root left_child: %d\n", left_child(H, 0, n));
    printf("root left_idx: %d\n", left_idx(0, n));
    printf("root right_child: %d\n", right_child(H, 0, n));
    printf("root right_idx: %d\n", right_idx(0, n));
    printf("is_min: %d\n", is_min(H, n));
    printf("is_max: %d\n", is_max(H, n));


#ifdef TEST

    printf("\n ### benchmark  ###\n");
    printf("size\ttime\tis_min\n");
    for (int i = 50000; i < 1000000; i = i + 50000) {
        int test[i];

        struct timespec b_time, e_time;
        int len = LENGTH(test);
        fill_array(test, len);

        clock_gettime(CLOCK_REALTIME, &b_time);
            build_heap(test, len);
        clock_gettime(CLOCK_REALTIME, &e_time);

        printf("%d\t%f\t%d\n", i, get_execution_time(b_time, e_time), is_min(test, len));
      }

#endif

    return 0;
}