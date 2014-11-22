#include "compressing_plane.h"

CompressingPlane::CompressingPlane()
{
		//Начальные настройки для задачи
		M = 0.3;
		E = 1e-9;
		H = 0.05;
		F.push_back(2);
		F.push_back(3);
		G = E/(2*(1-M));
		N = 21;
		f = 0;
		P.push_back(100.0);
		P.push_back(-100.0);
}
CompressingPlane::~CompressingPlane()
{

}

void CompressingPlane::MultiplicationByConstant( map< char ,list< map<int,double> > >& T )// Домножение на числа
{
	for (map< char ,list< map<int,double> > >::iterator i = T.begin(); i != T.end(); ++i)
	{
		int k = 0;
		for (list< map<int,double> >::iterator j = (*i).second.begin(); j != (*i).second.end(); ++j)
		{
			map<int,double> ::iterator b;
			switch(k)
			{
				case 0:
				{
					for ( b = (*j).begin(); b != (*j).end(); ++b)
						(*b).second *=E/(1-M*M);
					break;
				};
				case 1:
				{
					for ( b = (*j).begin(); b != (*j).end(); ++b)
						(*b).second *=E*M/(1-M*M);
					break;
				};
				case 2:
				{
					for ( b = (*j).begin(); b != (*j).end(); ++b)
						(*b).second  = (G*(*b).second)/2;
					break;
				};
				case 3:
				{
					for ( b = (*j).begin(); b != (*j).end(); ++b)
						(*b).second = (G*(*b).second)/2;
					break;
				};
			}
			k++;
		}
	}
}


vector<vector<double> > CompressingPlane::MatrixNxN(int row, int column, int xi, int xj)
{
	vector<double> NxN;
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
	return NxN;
}