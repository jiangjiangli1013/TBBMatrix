#include "tbbmatrix.h"

// Boost
#include <boost/random/random_device.hpp>
#include <boost/random/uniform_int_distribution.hpp>

// Eigen3
#include <Eigen/Dense>
using namespace Eigen;

// Std headers
#include<iostream>
#include<iomanip>
using namespace std;


// Constructor, empty matrix
TBBMatrix::TBBMatrix()
{
	row_num=0;
	col_num=0;
	matrix=NULL;
}

// Constructor, tbbmatrix of size new_row_num*new_col_num, all '0's
TBBMatrix::TBBMatrix(int new_row_num, int new_col_num)
{
	row_num=new_row_num;
	col_num=new_col_num;
	matrix=new double[new_row_num*new_col_num];
	//matrix=(double* ) malloc((new_row_num*new_col_num)*sizeof(double));
	//matrix.resize(new_row_num, new_col_num);
	//for(int i=0; i<row_num; ++i)
	//{
	//	for(int j=0; j<col_num; ++j)
	//	{
	//		Set(0,i,j);
	//	}
	//}
}

// Destructor
TBBMatrix::~TBBMatrix()
{
	delete(matrix);
	//free(matrix);
}

// Resize
//void TBBMatrix::Resize(int new_row_num, int new_col_num)
//{
//	row_num=new_row_num;
//	col_num=new_col_num;
//	matrix.resize(new_row_num, new_col_num);
//}

// Get size
int TBBMatrix::GetSzie()
{
	return row_num*col_num;
}

// Get number of rows
int TBBMatrix::GetRowNum()
{
	return row_num;
}

// Get number of columns
int TBBMatrix::GetColNum()
{
	return col_num;
}

// Get value at (i,j)
double TBBMatrix::Get(int row, int col)
{
	//if(in_range(row,0,row_num-1)&&in_range(col,0,col_num-1))
	//{
	//	return matrix[row*col_num+col];
	//}
	//else
	//{
	//	return 0;
	//}
	return matrix[row*col_num+col];
}

// Set value qt (i,j)
void TBBMatrix::Set(double value, int row, int col)
{
	//if(in_range(row,0,row_num-1)&&in_range(col,0,col_num-1))
	//{
	//	matrix[row*col_num+col]=value;
	//}
	matrix[row*col_num+col]=value;
}

// Randomize every element
void TBBMatrix::Randomize()
{
	boost::random::random_device rng;
	boost::random::uniform_int_distribution<> int_dist(0, 100);

	for(int i=0; i<row_num; ++i)
	{
		for(int j=0; j<col_num; ++j)
		{
			Set(int_dist(rng),i,j);
		}
	}

}

// Print
void TBBMatrix::Print()
{
	for(int i=0; i<row_num; ++i)
	{
		for(int j=0; j<col_num; ++j)
		{
			cout<<setw(5)<<Get(i,j)<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
