#ifndef TBBMATRIX_MULTIPLY_PARALLEL_H
#define TBBMATRIX_MULTIPLY_PARALLEL_H

// TBBMatrix
#include "tbbmatrix.h"

// TBB
#include <tbb/parallel_for.h>
#include <tbb/blocked_range2d.h>
using namespace tbb;

// TBB construct for parallel matrix multiplication, parameters pass by reference
class TBBMatrix_Multiply_Parallel
{
public:
	TBBMatrix_Multiply_Parallel(TBBMatrix& C,TBBMatrix& A,TBBMatrix& B);
	~TBBMatrix_Multiply_Parallel();
	// Block operation
	void operator()(const blocked_range2d<size_t> r) const;

private:
	int M;
	int N;
	int K;
	TBBMatrix& my_A;
	TBBMatrix& my_B;
	TBBMatrix& my_C;
};

// Parallel matrix multiplication
void Multiply_Parallel(TBBMatrix& C, TBBMatrix& A,TBBMatrix& B);

#endif // TBBMATRIX_MULTIPLY_PARALLEL_H