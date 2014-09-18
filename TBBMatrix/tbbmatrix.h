#ifndef TBBMATRIX_H
#define TBBMATRIX_H


inline bool in_range(int val, int begin, int end)
{
	return (val-begin)*(val-end)<=0?1:0;
}

class TBBMatrix
{
public:
	// Constructor, empty matrix
	TBBMatrix();
	// Constructor, tbbmatrix of size new_row_num*new_col_num, all '0's
	TBBMatrix(int new_row_num, int new_col_num);
	// Destructor
	~TBBMatrix();

	// Resize
	//void Resize(int new_row_num, int new_col_num);
	// Get size
	int GetSzie();
	// Get number of rows
	int GetRowNum();
	// Get number of columns
	int GetColNum();
	// Get value at (i,j)
	double Get(int row, int col);
	// Set value qt (i,j)
	void Set(double value, int row, int col);
	// Randomize every element
	void Randomize();
	// Print
	void Print();

private:
	// number of rows, number of columns
	int row_num;
	int col_num;
	// Internal representation of matrix
	//Matrix<double, Dynamic, Dynamic> matrix;
	double* matrix;
};

#endif // TBBMATRIX_H
