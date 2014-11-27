#include "compressing_plane.h"
#include "func.h"
#include "zeidely.h"
#include "build_integral_plane.h"
int main()
{
	CompressingPlane T1;
	T1.MatrixCompit(1);
	CompressingPlane T2;
	T2.MatrixCompit(2);
	vector<vector<double> > MatrixTop = T1.InsertMatix(T1.Multiplication(0,2),T1.Multiplication(1,3));

	vector<vector<double> > MatrixBot =T2.InsertMatix(T2.Multiplication(1,2),T2.Multiplication(0,3));


	//freopen("outtext.txt","w+",stdout);

	//Значение л элементов для каждого t1 t2
	MatrixTop.insert(MatrixTop.end(),MatrixBot.begin(),MatrixBot.end()); // Склеивание 2 матриц t1 and t2
	// fclose(stdout);

	Zeidely L_1;
	//L_1.Iterat(Matrix,new_B,Matrix.size(),1e-09);
	// Вывод матрицы 
	vector<vector<double> >::iterator i;
	freopen("outtext.txt","w+",stdout);
	for ( i = MatrixTop.begin(); i != MatrixTop.end(); ++i)
	{
		vector<double>::iterator j;
		for ( j = (*i).begin(); j != (*i).end(); ++j)
		{
			cout << *j << ' ';
		}
		cout <<  '\n';
	} 
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