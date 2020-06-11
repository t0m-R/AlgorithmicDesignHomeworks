#ifndef SORTINGALGORITHMS_VECTOR_H_
#define SORTINGALGORITHMS_VECTOR_H_

typedef struct Vector {
    float* data;
    size_t space_used; // check on push_back, if equal size resize
    size_t size;
} Vector;

void build_vector(Vector* v, size_t n);

void del_vector(Vector* v);

void push_back(Vector* v, float value);

void resize(Vector* v, size_t n);

#endif // SORTINGALGORITHMS_VECTOR_H_
