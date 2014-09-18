// TBB construct for parallel matrix multiplication
#include "tbbmatrix_multiply_parallel.h"

// TBBMatrix
#include "tbbmatrix.h"

// TBB
#include <tbb/parallel_for.h>
#include <tbb/blocked_range2d.h>
using namespace tbb;

// TBB construct for parallel matrix multiplication, parameters pass by reference
TBBMatrix_Multiply_Parallel::TBBMatrix_Multiply_Parallel(TBBMatrix& C,TBBMatrix& A,TBBMatrix& B): my_A(A), my_B(B), my_C(C)
{
	M=A.GetRowNum();
	N=B.GetColNum();
	K=A.GetColNum();
}

// TBB construct for parallel matrix multiplication, parameters pass by reference
TBBMatrix_Multiply_Parallel::~TBBMatrix_Multiply_Parallel()
{
}

// Block operation
void TBBMatrix_Multiply_Parallel::operator()(const blocked_range2d<size_t> r) const
{
	TBBMatrix& A=my_A;
	TBBMatrix& B=my_B;
	TBBMatrix& C=my_C;
	for (size_t i = r.rows().begin(); i != r.rows().end(); ++i) 
	{
		for (size_t j = r.cols().begin(); j != r.cols().end(); ++j) 
		{
			double sum=0;
			for(int k=0;k<K;++k)
			{
				sum+=A.Get(i,k)*B.Get(k,j);
			}
			C.Set(sum,i,j);
		}
	}
}

// Parallel matrix multiplication, 2d grain size: 10,10, or auto grain size
void Multiply_Parallel(TBBMatrix& C, TBBMatrix& A,TBBMatrix& B)
{
	int M=A.GetRowNum();
	int N=B.GetColNum();

	static affinity_partitioner ap;
	parallel_for( blocked_range2d<size_t>(0, M, 0, N), 
	//parallel_for( blocked_range2d<size_t>(0, M, 10, 0, N, 10),     
		          TBBMatrix_Multiply_Parallel(C,A,B), ap);
}