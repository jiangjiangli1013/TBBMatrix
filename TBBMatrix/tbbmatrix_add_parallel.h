#ifndef TBBMATRIX_ADD_PARALLEL_H
#define TBBMATRIX_ADD_PARALLEL_H

// TBBMatrix
#include "tbbmatrix.h"

// TBB
#include <tbb/parallel_for.h>
#include <tbb/blocked_range2d.h>
using namespace tbb;

// TBB construct for parallel matrix addition, parameters pass by reference
class TBBMatrix_Add_Parallel
{
public:
	TBBMatrix_Add_Parallel(TBBMatrix& C,TBBMatrix& A,TBBMatrix& B);
	~TBBMatrix_Add_Parallel();
	// Block operation
	void operator()(const blocked_range2d<size_t> r) const;

private:
	int M;
	int N;
	TBBMatrix& my_A;
	TBBMatrix& my_B;
	TBBMatrix& my_C;
};

// Parallel matrix addition
void Add_Parallel(TBBMatrix& C, TBBMatrix& A,TBBMatrix& B);

#endif // TBBMATRIX_ADD_PARALLEL_H