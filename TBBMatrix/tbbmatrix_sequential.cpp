// Sequential matrix addition, sequential matrix multiplication
#include "tbbmatrix_sequential.h"

// Sequential matrix addition
void Add_Sequential(TBBMatrix& C, TBBMatrix& A, TBBMatrix& B)
{
	int max_row_num=A.GetRowNum();
	int max_col_num=A.GetColNum();

	for(int i=0;i<max_row_num;++i)
	{
		for(int j=0;j<max_col_num;++j)
		{
			C.Set(A.Get(i,j)+B.Get(i,j),i,j);
		}
	}
}

// Sequential matrix multiplication
void Multiply_Sequential(TBBMatrix& C, TBBMatrix& A, TBBMatrix& B)
{
	int M=A.GetRowNum();
	int K=A.GetColNum();
	int N=B.GetColNum();

	for(int i=0;i<M;++i)
	{
		for(int j=0;j<N;++j)
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