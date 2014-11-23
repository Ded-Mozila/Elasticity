#include "compressing_plane.h"
#include "func.h"
#include "zeidely.h"
#include "build_integral_plane.h"
int main()
{
	CompressingPlane A;
	
	//freopen("outtext.txt","w+",stdout);

	//Значение л элементов для каждого t1 t2
	A.matrixMatrix_NxN[0] = A.MatrixNxN(make_pair(1,1));
	A.matrixMatrix_NxN[1] = A.MatrixNxN(make_pair(2,1));
	A.matrixMatrix_NxN[2] = A.MatrixNxN(make_pair(2,2));
	A.matrixMatrix_NxN[3] = A.MatrixNxN(make_pair(1,2));

	vector<vector<double> >::iterator i;
	vector<vector<double> >::iterator ii;
	//обьединение матриц
	vector<vector<double> > Matrix(A.matrixMatrix_NxN[0]);// Матрица значений t1
	for ( i = Matrix.begin(), ii = A.matrixMatrix_NxN[2].begin(); i != Matrix.end(), ii != A.matrixMatrix_NxN[2].end(); ++i , ++ii)
		(*i).insert((*i).end(),(*ii).begin(),(*ii).end());

	vector<vector<double> > Matrix2(A.matrixMatrix_NxN[1]);// Матрица значений t2
	for ( i = Matrix2.begin(), ii = A.matrixMatrix_NxN[3].begin(); i != Matrix2.end(), ii != A.matrixMatrix_NxN[3].end(); ++i , ++ii)
		(*i).insert((*i).end(),(*ii).begin(),(*ii).end());
	Matrix.insert(Matrix.end(),Matrix2.begin(),Matrix2.end()); // Склеивание 2 матриц t1 and t2
	// fclose(stdout);
	vector<double> new_B;
	int N = 21;
	for (int i = 0; i < (N-2)*(N-1); ++i)
	{
		if (i%(N-1) == 0 ||i%(N-1) == 0 )
		{
			new_B.push_back(100);
			if(i !=  0 || i != (N-2)*(N-1)-1 )
				new_B.push_back(100);
		}
		else new_B.push_back(0);
	}
	for (int i = 0; i < (N-2)*(N-1); ++i)
	{
		if (i%(N-1) == 0)
		{
			new_B.push_back(-100);
			if(i !=  0 || i != (N-2)*(N-1)-1 )
				new_B.push_back(100);
		}
		else new_B.push_back(0);
	}
	cout << new_B.size()<< endl;
	Zeidely L_1;
	L_1.Iterat(Matrix,new_B,Matrix.size(),1e-09);
	//Вывод матрицы 
	// freopen("outtext.txt","w",stdout);
	// for ( i = Matrix.begin(); i != Matrix.end(); ++i)
	// {
	// 	vector<double>::iterator j;
	// 	for ( j = (*i).begin(); j != (*i).end(); ++j)
	// 	{
	// 		cout << *j << ' ';
	// 	}
	// 	cout <<  '\n';
	// } 
	fclose(stdout);
	// vector<vector<double> >::iterator i;
	// vector<double>::iterator j;
	// integral TT(0.05 , 0.05 , 5 , 1e-09 ,0.3);
	// vector<vector<double> >RR(TT.MakePlane(make_pair(1,1)));
	// for ( i = RR.begin(); i != RR.end(); ++i)
	// {
		
	// 	for ( j = (*i).begin(); j != (*i).end(); ++j)
	// 	{
	// 		cout << *j << ' ';
	// 	}
	// 	cout <<  '\n';
	// } 
	// vector<double> RRR(TT.CalcElememt(1,1,1,1));
	// cout << endl;
	// for ( j = RRR.begin(); j != RRR.end(); ++j)
	// {
	// 	cout << *j << ' ';
	// }
	
	return 0;
}
