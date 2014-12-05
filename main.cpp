#include "compressing_plane.h"
#include "zeidely.h"
#include "build_integral_plane.h"
#include "write.h"


int main(int argc, char const *argv[])
{
	CompressingPlane T1(atoi(argv[1]),atoi(argv[2]));
	T1.MatrixCompit(1);
	CompressingPlane T2(atoi(argv[1]),atoi(argv[2]));
	T2.MatrixCompit(2);
	vector<vector<double> > MatrixTop = T1.InsertMatix(T1.Multiplication(0,2),T1.Multiplication(1,3));

	vector<vector<double> > MatrixBot = T2.InsertMatix(T2.Multiplication(1,2),T2.Multiplication(0,3));

	//Значение л элементов для каждого t1 t2
	MatrixTop.insert(MatrixTop.end(),MatrixBot.begin(),MatrixBot.end()); // Склеивание 2 матриц t1 and t2
	vector<double> B_R =  T1.B_l(MatrixTop.size()/2, atoi(argv[3]));
	vector<double> B = T2.B_r(MatrixTop.size()/2,0);
	B.insert(B.end(),B_R.begin(),B_R.end()); 
	Zeidely L_1;
	vector<double> x = L_1.Iterat1(MatrixTop,B,MatrixTop.size(),1e-09);
	string nameFile(argv[4]);
	WriteVector(x);
	WriteMatrix_vector(MatrixTop);
	genMatrix_plot(x,T1.N, T1.H , nameFile, atoi(argv[2]));
	return 0;
}