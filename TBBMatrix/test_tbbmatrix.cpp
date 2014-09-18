// Visual Leak Detector, debug build only
#include "vld.h"

// High Resolution Timer
#include "Timer.h"

// TBBMatrix
#include "tbbmatrix.h"
// Sequential matrix addition, sequential matrix multiplication
#include "tbbmatrix_sequential.h"
// TBB construct for parallel matrix addition
#include "tbbmatrix_add_parallel.h"
// TBB construct for parallel matrix multiplication
#include "tbbmatrix_multiply_parallel.h"

// Eigen3
#include <Eigen/Dense>
using namespace Eigen;

// Std headers
#include<iostream>
#include<iomanip>
using namespace std;

// Main
int main(int argc, char* argv[])
{
	// Using Eigen3 in a multi-threaded application
	Eigen::initParallel();

	// Declarations: timer
	Timer t;
	double tick1,tick2;

	// Declarations: TBBMatrix
	TBBMatrix A(1000,700);
	TBBMatrix B(1000,700);
	TBBMatrix C(1000,700);
	TBBMatrix D(1000,700);
	TBBMatrix E(700,1100);
	TBBMatrix F(1000,1100);

	// Declarations: Eigen3 Matrix
	MatrixXd A1=MatrixXd::Random(1000,700);
	MatrixXd B1=MatrixXd::Random(1000,700);
	MatrixXd C1=MatrixXd::Random(1000,700);
	MatrixXd D1=MatrixXd::Random(1000,700);
	MatrixXd E1=MatrixXd::Random(700,1100);
	MatrixXd F1=MatrixXd::Random(1000,1100);

	// Start timer
	t.start();

	// Construct two TBBMatrix for addition
	A.Randomize();
	//A.Print();
	B.Randomize();
	//B.Print();

	// Sequential matrix addition
	tick1=t.getElapsedTimeInMilliSec();
	Add_Sequential(C,A,B);
	tick2=t.getElapsedTimeInMilliSec();
	cout <<"Sequential matrix addition elapsed time: "<< (tick2 - tick1) << " ms." << endl;
	//C.Print();

	// Parallel matrix addition
	tick1=t.getElapsedTimeInMilliSec();
	Add_Parallel(C,A,B);
	tick2=t.getElapsedTimeInMilliSec();
	cout <<"Parallel matrix addition elapsed time: "<< (tick2 - tick1) << " ms." << endl;
	//C.Print();

	// Eigen3 matrix addition
	tick1=t.getElapsedTimeInMilliSec();
	C1=A1+B1;
	tick2=t.getElapsedTimeInMilliSec();
	cout <<"Eigen3 matrix addition elapsed time: "<< (tick2 - tick1) << " ms." << endl;
	//C1.Print();

	// Construct two TBBMatrix for multiplication
	D.Randomize();
	//D.Print();
	E.Randomize();
	//E.Print();

	// Sequential matrix multiplication
	tick1=t.getElapsedTimeInMilliSec();
	Multiply_Sequential(F,D,E);
	tick2=t.getElapsedTimeInMilliSec();
	cout <<"Sequential matrix multiplication elapsed time: "<< (tick2 - tick1) << " ms." << endl;
	//F.Print();

	// Parallel matrix multiplication
	tick1=t.getElapsedTimeInMilliSec();
    Multiply_Parallel(F,D,E);
	tick2=t.getElapsedTimeInMilliSec();
	cout <<"Parallel matrix multiplication elapsed time: "<< (tick2 - tick1) << " ms." << endl;
	//F.Print();

	// Eigen3 matrix multiplication
	tick1=t.getElapsedTimeInMilliSec();
	F1=D1*E1;
	tick2=t.getElapsedTimeInMilliSec();
	cout <<"Eigen3 matrix multiplication elapsed time: "<< (tick2 - tick1) << " ms." << endl;
	//F1.Print();

	return 0;
}