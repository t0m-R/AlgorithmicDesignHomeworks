#include <stdio.h>
#include <time.h>
#include "utilities.h"
#include "sort.h"
#include "macro.h"


int main() {

#define TEST

    printf("\n ### init tests ###\n");
    int test[10];
    int n = LENGTH(test);

    printf("\n\n ### insertion sort ###");
    rand_fill_array(test, n);
    print_array(test, n);
    insertion_sort(test, n);
    print_array(test, n);

    printf("\n\n ### quicksort ###");
    rand_fill_array(test, n);
    print_array(test, n);
    quicksort(test, 0, n - 1, n);
    print_array(test, n);

    printf("\n\n ### heapsort ###");
    rand_fill_array(test, n);
    print_array(test, n);
    heapsort(test, n);
    print_array(test, n);

    printf("\n\n ### radix sort ###");
    int digits = 4;
    rand_fill_array_digits(test, n, digits);
    print_array(test, n);
    radix_sort(test, n, digits);
    print_array(test, n);

    printf("\n\n ### bucket sort ###");
    float bucket[10];
    int size = LENGTH(bucket);
    rand_fill_array_unif(bucket, size);
    print_array_float(bucket, size);
    bucket_sort(bucket, size);
    print_array_float(bucket, size);

    printf("\n\n ### counting sort ###");
    rand_fill_array(test, n);
    print_array(test, n);
    int V[n];
    counting_sort(test, V, MAX_VALUE, n);
    print_array(V, n);

    printf("\n\n ### selection ###");
    rand_fill_array(test, n);
    print_array(test, n);
    int idx = 5;
    int idy = selection(test, idx, 0, n - 1, n);
    heapsort(test, n);
    printf("\nindex %d: %d == %d\n", idx, idy, test[idx]);


#ifdef TEST

  printf("\n ### benchmark  ###\n");
  struct timespec b_time, e_time;
  for (int i = 1000; i < 10000; i = i + 1000) {

    printf("\n *** [ %d ] *** \n", i);
    int A[i];
    int len = LENGTH(A);


    printf("### worst cases ###\n");

    rand_fill_array(A, len);
    insertion_sort(A, len);
    reverse_array(A, len);
    clock_gettime(CLOCK_REALTIME, &b_time);
      insertion_sort(A, len);
    clock_gettime(CLOCK_REALTIME, &e_time);
    printf("insertion: %f\n", get_execution_time(b_time, e_time));

    reverse_array(A, len);
    clock_gettime(CLOCK_REALTIME, &b_time);
      quicksort(A, 0, len - 1, len);
    clock_gettime(CLOCK_REALTIME, &e_time);
    printf("quicksort: %f\n", get_execution_time(b_time, e_time));


    printf("### best cases ###\n");

    rand_fill_array(A, len);
    insertion_sort(A, len);
    clock_gettime(CLOCK_REALTIME, &b_time);
      insertion_sort(A, len);
    clock_gettime(CLOCK_REALTIME, &e_time);
    printf("ïnsertion: %f\n", get_execution_time(b_time, e_time));

      quicksort_best_case(A, len);
    clock_gettime(CLOCK_REALTIME, &b_time);
      quicksort(A, 0, len - 1, len);
    clock_gettime(CLOCK_REALTIME, &e_time);
    printf("quicksort: %f\n", get_execution_time(b_time, e_time));

  }

#endif

  return 0;
}