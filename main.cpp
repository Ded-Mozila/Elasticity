#include "compressing_plane.h"
#include "func.h"
#include "zeidely.h"
int main()
{
	CompressingPlane A;
	// Для внутренних узлов
	map< char ,list< map<int,double> > >T;
	list< map<int,double> > new_list_T;
		map<int,double>  CT1_1; // Первый интеграл
		CT1_1[0] =  2;
		CT1_1[1] = -1;
		CT1_1[2] =  0;
		CT1_1[3] =  0;
		CT1_1[4] = -1;
		CT1_1[5] =  0.5;
		CT1_1[6] =  0;
	new_list_T.push_back(CT1_1);
		map<int,double>  CT2_1; // Первый интеграл
		CT2_1[0] = -1;
		CT2_1[1] =  0.5;
		CT2_1[2] = -0.5;
		CT2_1[3] =  0.5;
		CT2_1[4] =  0.5;
		CT2_1[5] = -0.5;
		CT2_1[6] =  0.5;
	new_list_T.push_back(CT2_1);
		map<int,double>  CT1_2; // Первый интеграл
		CT1_2[0] =  2;
		CT1_2[1] =  0;
		CT1_2[2] =  0;
		CT1_2[3] = -1;
		CT1_2[4] =  0;
		CT1_2[5] =  0;
		CT1_2[6] = -1;
	new_list_T.push_back(CT1_2);
		map<int,double>  CT2_2; // Первый интеграл
		CT2_2[0] = -1;
		CT2_2[1] =  0.5;
		CT2_2[2] = -0.5;
		CT2_2[3] =  0.5;
		CT2_2[4] =  0.5;
		CT2_2[5] = -0.5;
		CT2_2[6] =  0;
	new_list_T.push_back(CT2_2);
  T['C'] = new_list_T; // запись внутренних элементов
  new_list_T.clear(); // Очистка лита
	// Для Левой границы
		map<int,double>  LT1_1; // Первый интеграл
		LT1_1[0] =  1;
		LT1_1[1] = -1;
		LT1_1[2] =  0;
		LT1_1[3] =  0;
		LT1_1[6] =  0;
	new_list_T.push_back(LT1_1);
		map<int,double>  LT2_1; // Первый интеграл
		LT2_1[0] = -0.5;
		LT2_1[1] =  0.5;
		LT2_1[2] = -0.5;
		LT2_1[3] =  0;
		LT2_1[6] =  0.5;
	new_list_T.push_back(LT2_1);
		map<int,double>  LT1_2; // Первый интеграл
		LT1_2[0] =  1;
		LT1_2[1] =  0;
		LT1_2[2] =  0;
		LT1_2[3] = -0.5;
		LT1_2[6] = -0.5;
	new_list_T.push_back(LT1_2);
		map<int,double>  LT2_2; // Первый интеграл
		LT2_2[0] = -0.5;
		LT2_2[1] =  0.5;
		LT2_2[2] = -0.5;
		LT2_2[3] =  0.5;
		LT2_2[6] =  0;
	new_list_T.push_back(LT2_2);
   T['L'] = new_list_T; // запись левая граница элементов
   new_list_T.clear(); // Очистка лита
	// Для Правая границы
		map<int,double>  RT1_1; // Первый интеграл
		RT1_1[0] =  1;
		RT1_1[3] =  0;
		RT1_1[4] = -1;
		RT1_1[5] =  0;
		RT1_1[6] =  0;
	new_list_T.push_back(RT1_1);
		map<int,double>  RT2_1; // Первый интеграл
		RT2_1[0] = -0.5;
		RT2_1[3] =  0.5;
		RT2_1[4] =  0.5;
		RT2_1[5] = -0.5;
		RT2_1[6] =  0;
	new_list_T.push_back(RT2_1);	
		map<int,double>  RT1_2; // Первый интеграл
		RT1_2[0] =  1;
		RT1_2[3] = -0.5;
		RT1_2[4] =  0;
		RT1_2[5] =  0;
		RT1_2[6] = -0.5;
	new_list_T.push_back(RT1_2);	
		map<int,double>  RT2_2; // Первый интеграл
		RT2_2[0] = -0.5;
		RT2_2[3] =  0;
		RT2_2[4] =  0.5;
		RT2_2[5] = -0.5;
		RT2_2[6] =  0.5;
	new_list_T.push_back(RT2_2);
	T['R'] = new_list_T; // запись левая граница элементов
	new_list_T.clear(); // Очистка лита
	
	A.MultiplicationByConstant(T);//  Умножение улементов на числа

	//freopen("outtext.txt","w+",stdout);

	//Значение л элементов для каждого t1 t2
	for (int i = 0; i < 4; ++i)// Создание матрицы со значениями для каждой точки 
	{
		A.matrixMatrix_NxN[i] = BuildMatrix(i,T,21);
	}
	// for (map< char ,list< map<int,double> > >::iterator i = T.begin(); i != T.end(); ++i)
	// {
	// 	for (list< map<int,double> >::iterator j = (*i).second.begin(); j != (*i).second.end(); ++j)
	// 	{ 	
	// 		for (map<int,double> ::iterator b = (*j).begin(); b != (*j).end(); ++b)
	// 			cout << (*b).second << '\n';
	// 		cout << '\n';
	// 	}
	// 	cout << '\n';
	// }

	//Вывод матрицы в файл
	list<list<double> >::iterator i;
	// for (int a = 0; a < 4; ++a)
	// {
	// 	cout << a << '\n';
	// 	for ( i = A.matrixMatrix_NxN[a].begin(); i != A.matrixMatrix_NxN[a].end(); ++i)
	// 	{
	// 		list<double>:: iterator j;
	// 		for ( j = (*i).begin(); j != (*i).end(); ++j)
	// 		{
	// 			cout << *j << ' ';
	// 		}
	// 		cout <<  '\n';
	// 	} 
	// 	cout << "\n\n";
	// }
	list<list<double> >::iterator ii;

	// обьединение матриц
	list<list<double> > Matrix(A.matrixMatrix_NxN[0]);// Матрица значений t1
	vector<double> B;
	for ( i = Matrix.begin(), ii = A.matrixMatrix_NxN[2].begin(); i != Matrix.end(), ii != A.matrixMatrix_NxN[2].end(); ++i , ++ii)
	{
		(*i).splice((*i).end(),(*ii));
		B.push_back(100); // Запонение столбец свободных членов для t1
	} 
	
	list<list<double> > Matrix2(A.matrixMatrix_NxN[1]);// Матрица значений t2
	for ( i = Matrix2.begin(), ii = A.matrixMatrix_NxN[3].begin(); i != Matrix2.end(), ii != A.matrixMatrix_NxN[3].end(); ++i , ++ii)
	{
		(*i).splice((*i).end(),(*ii));
		B.push_back(-100); // Запонение столбец свободных членов для t2
	} 
	Matrix.splice(Matrix.end(),Matrix2); // Склеивание 2 матриц t1 and t2


	Zeidely L_1;
	L_1.Iterat(Matrix,B,Matrix.size(),1e-09);
	// Вывод матрицы 
/*	for ( i = Matrix.begin(); i != Matrix.end(); ++i)
	{
		list<double>::iterator j;
		for ( j = (*i).begin(); j != (*i).end(); ++j)
		{
			cout << *j << ' ';
		}
		cout <<  '\n';
	} */
	return 0;
}
