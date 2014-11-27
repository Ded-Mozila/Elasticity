#include "build_integral_plane.h"

integral::integral()
{
}
integral::~integral()
{
}

integral::integral(double h, double l , int n, double e, double m)
{
	N = n;
	M = m;
	E = e;
	G = (E/(2*(1-M)));
	ds = h*l/2;
	Fi[1] = make_pair(-1/h,0.0);
	Fi[2] = make_pair(0.0,-1/h);
	Fi[3] = make_pair(1/h,-1/h);
	Fi[4] = make_pair(1/h,0.0);
	Fi[5] = make_pair(0.0,1/h); 
	Fi[6] = make_pair(-1/h,1/h);
}

vector<vector<double> > integral::MakePlane(pair<int,int> x, int number)
{
	vector<vector<double> > Matrix;
	for (int i = 1; i < N-1; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			Matrix.push_back(CalcElememt(i,j,x.first,x.second,number));
		}
	}
	return Matrix;
}

vector<double> integral::CalcElememt(int row, int column ,int xi , int xj , int number)// xi- первая константа для dFik/dxi , xj  - вторая константа для dFi/dxj 
{
	map<int, bool> K(BuildAreaElm_K(N,row,column));
	map<int, bool> triangl_K;
	//Проверка на существование треугольников
	for( int i = 1; i < 6; ++i)
		if( K[i] == true && K[i+1] == true )
			triangl_K[i] = true;
		else triangl_K[i] = false;
	if( K[6] == true && K[1] == true )
		triangl_K[6] = true;
	else triangl_K[6] = false;
	map<int,double> T;//площади треугольников
	//Зануление всех переменных площадей К
	for(int j = 0 ; j < 7 ; ++j)
		T[j] = 0.0;
	// k == 0
	for(int i = 1; i < 7 ; ++i)
		if( triangl_K[i] == true)
			T[0] += Area(i,i,xi,xj,number);//0 - узел начальный i - номер треугольника
	// k=1
	if(triangl_K[1] == true)
		T[1] += Area(3,1,xi,xj,number);
	if(triangl_K[6] == true)
		T[1] += Area(4,6,xi,xj,number);
	// k=2
	if(triangl_K[1] == true)
		T[2] += Area(5,1,xi,xj,number);
	if(triangl_K[2] == true)
		T[2] += Area(4,2,xi,xj,number);
	// k=3
	if(triangl_K[2] == true)
		T[3] += Area(6,2,xi,xj,number);
	if(triangl_K[3] == true)
		T[3] += Area(5,3,xi,xj,number);
	// k=4
	if(triangl_K[3] == true)
		T[4] += Area(1,3,xi,xj,number);
	if(triangl_K[4] == true)
		T[4] += Area(6,4,xi,xj,number);
	// k=5
	if(triangl_K[4] == true)
		T[5] += Area(2,4,xi,xj,number);
	if(triangl_K[5] == true)
		T[5] += Area(1,5,xi,xj,number);
	// k=6
	if(triangl_K[5] == true)
		T[6] += Area(3,5,xi,xj,number);
	if(triangl_K[6] == true)
		T[6] += Area(2,6,xi,xj,number);
	vector<double> new_Matrix;
	for(int i =1; i < N-1; ++i)
	{
		for(int j = 0; j < N ; ++j)
		{
			// Проверка по строкам
			if(i == row)//element 4 0 1
			{
				//Поиск по столбку
				if(j == column-1 && K[4] == true)// k = 4
				{
					new_Matrix.push_back(T[4]);
				}
				else if(j == column)// k = 0
				{
					new_Matrix.push_back(T[0]);
				}
				else if(j == column+1 && K[1] == true) // k = 1
				{
					new_Matrix.push_back(T[1]);
				}
				else
				{
					new_Matrix.push_back(0);
				}
			}
			else if(i == row+1)// 5 6
			{
				//Поиск по столбку
				if(j == column-1 && K[5] == true)// k = 5
				{
					new_Matrix.push_back(T[5]);
				}
				else if(j == column && K[6] == true)// k = 6
				{
					new_Matrix.push_back(T[6]);
				}
				else
				{
					new_Matrix.push_back(0);
				}
			}
			else if(i == row-1)// 2 3 
			{
				//Поиск по столбку
				if(j == column && K[3] == true)// k = 3
				{
					new_Matrix.push_back(T[3]);
				}
				else if(j == column+1 && K[2] == true) // k = 2
				{
					new_Matrix.push_back(T[2]);
				}
				else
				{
					new_Matrix.push_back(0);
				}
			}else	new_Matrix.push_back(0);
		}
	}
	return new_Matrix;
}



double integral::Area( int i, int j, int xi, int xj , int number)
{
	double area = 0.0;
	if(xi == 1 && xj == 1)
	{
		if (number == 1)
		{
			area += (E/(1-M*M))*Fi[i].first * Fi[j].first * ds;
		}else if(number == 2)
		{
			area += (G/2)*Fi[i].first * Fi[j].first * ds;
		}
	}
	else if(xi == 1 && xj == 2)
	{
		if (number == 1)
		{
			area += (G/2)*Fi[i].first * Fi[j].second * ds;
		}else if(number == 2)
		{
			area += (E*M/(1-M*M))*Fi[i].first * Fi[j].second * ds;	
		}
	}
	else if(xi == 2 && xj == 1)
	{
		if (number == 1)
		{
			area += (E*M/(1-M*M))*Fi[i].second * Fi[j].first * ds;
		}else if(number == 2)
		{
			area += (G/2)*Fi[i].second * Fi[j].first * ds;
		}
	}	
	else if(xi == 2 && xj == 2)
	{
		if (number == 1)
		{
			area += (G/2)*Fi[i].second * Fi[j].second * ds;
		}else if(number == 2)
		{
			area += (E/(1-M*M))*Fi[i].second * Fi[j].second * ds;
		}
	}
	else area = -1;//неверный вариант
	return area;
}

map<int,bool> integral::BuildAreaElm_K( int n, int row, int column)
{
	map<int,bool> K;
	for(int i = 1 ; i < 7 ; ++i)
	switch(i)
	{
		case 1:
		{
			if(( 0 <= row && row < n ) && ( 0 <= column && column < n-1 ))
				K[1] = true;
			else K[1] = false;	
			break;
		}
		case 2:
		{
			if(( 1 < row && row < n ) && ( 0 <= column && column < n-1))
				K[2] = true;
			else K[2] = false;
			break;
		}
		case 3:
		{
			if(( 1 < row && row < n ) && ( 0 <= column && column < n ))
				K[3] = true;
			else K[3] = false; 
			break;
		}
		case 4:
		{
			if(( 0 <= row && row < n ) && ( 1 <= column && column < n ))
				K[4] = true;
			else K[4] = false;	
			break;
		}
		case 5:
		{
			if(( 0 <= row && row < n-2 ) && ( 1 <= column && column < n))
				K[5] = true;
			else K[5] = false;
			break;
		}
		case 6:
		{	
			if(( 0 <= row && row < n-2 ) && ( 0 <= column && column < n))
				K[6] = true;
			else K[6] = false;
			break;
		}
	
	}
	return K;
}