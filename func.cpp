//func.cpp
#include "func.h"

MatrixElement::MatrixElement(void)
	{
	}

MatrixElement::~MatrixElement(void)
	{
	}

list<MatrixElement> stringMatrix(const long int str , const long int post, const long int n )//функция заполнения матрицы
{
	list<MatrixElement> strMatrix;//строка значений
	
	return strMatrix;
} 

list<list<double> > BuildMatrix(int number,const map< char ,list< map<int,double> > >T , int N)
{
	list<list<double> > new_Matrix;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			list<double> mx = FillingMatrix( number ,T,i,j,N);
			if(mx.size() != 0)
			new_Matrix.push_back(mx);
		}
 	}
	return new_Matrix;
}
list<double> FillingMatrix( int number, map< char ,list< map<int,double> > >T,const int row,const int column, int N) // Заполние матрицы в зависимости от положения конечного элемента
{
	list<double> new_Matrix;

	char key ='C';
	if (column ==  0  )key = 'L'; //Левая граница
	if (column == N-1 )key = 'R'; //Парвая граница
	list< map<int,double> > T_p = T[key];
	vector< map<int,double> > T_vector;
	//T_vector.reserve(T_p.size());
	T_vector.insert(T_vector.end(),T_p.begin(), T_p.end());
	map<int,double>  XT = (T_vector.at(number));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (row == 0 || row == N-1 )
			{
				//new_Matrix.push_back(0);
			}
			else
			{
				// Проверка по строкам
				if(i == row)//element 4 0 1
				{
					//Поиск по столбку
					if(j == column-1)// k = 4
					{
						new_Matrix.push_back(XT[4]);
					}
					else if(j == column)// k = 0
					{
						new_Matrix.push_back(XT[0]);
					}
					else if(j == column+1) // k = 1
					{
						new_Matrix.push_back(XT[1]);
					}
					else
					{
						new_Matrix.push_back(0);
					}
				}
				else if(i == row+1)// 5 6
				{
					//Поиск по столбку
					if(j == column-1)// k = 5
					{
						new_Matrix.push_back(XT[5]);
					}
					else if(j == column)// k = 6
					{
						new_Matrix.push_back(XT[6]);
					}
					else
					{
						new_Matrix.push_back(0);
					}
				}
				else if(i == row-1)// 2 3 
				{
					//Поиск по столбку
					if(j == column)// k = 3
					{
						new_Matrix.push_back(XT[3]);
					}
					else if(j == column+1) // k = 2
					{
						new_Matrix.push_back(XT[2]);
					}
					else
					{
						new_Matrix.push_back(0);
					}
				}else	new_Matrix.push_back(0);
			}
		}
	}
	return new_Matrix;
}