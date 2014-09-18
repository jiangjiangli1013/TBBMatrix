#ifndef TBBMATRIX_SEQUENTIAL_H
#define TBBMATRIX_SEQUENTIAL_H

// TBBMatrix
#include "tbbmatrix.h"

// Sequential matrix addition
void Add_Sequential(TBBMatrix& C, TBBMatrix& A, TBBMatrix& B);
// Sequential matrix multiplication
void Multiply_Sequential(TBBMatrix& C, TBBMatrix& A, TBBMatrix& B);

#endif // TBBMATRIX_SEQUENTIAL_H