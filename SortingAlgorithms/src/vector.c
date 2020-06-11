#include <stdio.h>
#include <stdlib.h>
#include "vector.h"


void build_vector(Vector* v, size_t n) {
    v -> data = malloc(n * sizeof *(v->data) );
    if (!v -> data) {
        perror("malloc");
        exit(EXIT_FAILURE);
    } else {
        v->size = 0;
        v->space_used = n;
    }
}


void del_vector(Vector* v) {
    free(v->data);
    v -> size = 0;
    v -> space_used = 0;
}


void push_back(Vector* v, float value) {
    if (v -> size == v-> space_used) {
        resize(v, 2 * (v->space_used));
    }
    v -> data[v -> size] = value;
    v -> size += 1;
}


void resize(Vector* v, size_t n) {
    float* tmp;
    tmp = realloc(v -> data, n * sizeof *(v->data) );
    if (!tmp) {
        perror("realloc");
        exit(EXIT_FAILURE);
    } else {
        v -> data = tmp;
        v -> space_used = n;
    }

}