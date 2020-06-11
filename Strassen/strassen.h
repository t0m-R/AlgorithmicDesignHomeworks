#ifndef STRASSEN_STRASSEN_H
#define STRASSEN_STRASSEN_H

#include <stdlib.h>

void strassen(float **C, float **A, float **B, const size_t n);

void strassen_opt(float **C, float **A, float **B, const size_t n);

#endif // STRASSEN_STRASSEN_H
