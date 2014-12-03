#include "build_integral_plane.h"

integral::integral()
{
}
integral::~integral()
{
}

integral::integral(double h, int n, double e, double m, int a)
{
	if(a > 90){
		cout<< "Ошибка ввода угла!\n";
	}
	if(n < 2){
		cout<< "Ошибка ввода количества  узлов!\n";
	}
	N = n;
	M = m;
	E = e;
	G = (E/(2.0*(1.0+m)));
	ds[0] = h*h/2.0;					// Значение площади для первой области 
	double	h2 = h/tan(a/(180*M_PI));
	ds[1] = h * h2 / 2.0; // Значение площади для второй области
	//значение базисных функций для квадратной области
	Fi[0][1] = make_pair(-1.0/h,0.0);
	Fi[0][2] = make_pair(0.0,-1.0/h);
	Fi[0][3] = make_pair(1.0/h,-1.0/h);
	Fi[0][4] = make_pair(1.0/h,0.0);
	Fi[0][5] = make_pair(0.0,1.0/h); 
	Fi[0][6] = make_pair(-1.0/h,1.0/h);
	//значение базисных функций для треугольной области области

	/// изменить значения для каждого треугольника !!!!!!!!!!!!!!
	Fi[1][1] = make_pair(-1.0/h,0.0);
	Fi[1][2] = make_pair(0.0,-1.0/h);
	Fi[1][3] = make_pair(1.0/h,-1.0/h2);
	Fi[1][4] = make_pair(1.0/h,0.0);
	Fi[1][5] = make_pair(0.0,1.0/h2); 
	Fi[1][6] = make_pair(-1.0/h,1.0/h2);
}

vector<vector<double> > integral::MakePlane(pair<int,int> x, int number)
{
	vector<vector<double> > Matrix;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N*2-i; ++j)//2N - так как область 30 градусов
		{
			Matrix.push_back(CalcElememt(j,i,x,number));
		}
	}
	return Matrix;
}

vector<double> integral::CalcElememt(int row, int column ,pair<int,int> x, int number)// xi- первая константа для dFik/dxi , xj  - вторая константа для dFi/dxj 
{
	if(row <= 0 || row >= N*2-column)
	{
		vector<double> Matrixx((N*2-column)*N,0.0);// Создание пустой таблицы
		return Matrixx;
	}
	map<int,pair<bool,int> > K(BuildAreaElm_K(N*2-column,row,column));//Данные у узлах
	map<int,pair<bool,int> > triangl_K(BuildAreaTriangl_K(K));//Данные о треугольниках
	map<int,double> T(TriangleArea(triangl_K,x,number));//площади треугольников

	vector<double> new_Matrix;
	for(int j = 0; j < N; ++j)
	{
		for(int i = 0; i < N*2-j ; ++i)
		{
			// Проверка по строкам
			if(i == row)//element 4 0 1
			{
				//Поиск по столбку
				if(j == column-1 && K[4].first == true)// k = 4
				{
					new_Matrix.push_back(T[4]);
				}
				else if(j == column)// k = 0
				{
					new_Matrix.push_back(T[0]);
				}
				else if(j == column+1 && K[1].first == true) // k = 1
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
				if(j == column-1 && K[5].first == true)// k = 5
				{
					new_Matrix.push_back(T[5]);
				}
				else if(j == column && K[6].first == true)// k = 6
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
				if(j == column && K[3].first == true)// k = 3
				{
					new_Matrix.push_back(T[3]);
				}
				else if(j == column+1 && K[2].first == true) // k = 2
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



double integral::Area( int i, int j, pair<int,int> x , int number, int roomArea)
{
	double area = 0.0;
	double Ei = (E/(1-M*M));

	if(x.first == 1 && x.second == 1)
	{
		if (number == 1)
		{
			area = Ei*Fi[roomArea][i].first * Fi[roomArea][j].first * ds[roomArea];
		}
		if(number == 2)
		{
			area = (G/2.0)*Fi[roomArea][i].first * Fi[roomArea][j].first * ds[roomArea];
		}
	}
	else if(x.first == 1 && x.second == 2)
	{
		if (number == 1)
		{
			area = (G/2.0)*Fi[roomArea][i].first * Fi[roomArea][j].second * ds[roomArea];
		}
		if(number == 2.0)
		{
			area = Ei*M*Fi[roomArea][i].first * Fi[roomArea][j].second * ds[roomArea];	
		}
	}
	else if(x.first == 2 && x.second == 1)
	{
		if (number == 1)
		{
			area = Ei*M*Fi[roomArea][i].second * Fi[roomArea][j].first * ds[roomArea];
		}
		if(number == 2)
		{
			area = (G/2.0)*Fi[roomArea][i].second * Fi[roomArea][j].first * ds[roomArea];
		}
	}	
	else if(x.first == 2 && x.second == 2)
	{
		if (number == 1)
		{
			area = (G/2.0)*Fi[roomArea][i].second * Fi[roomArea][j].second * ds[roomArea];
		}
		if(number == 2)
		{
			area = Ei*Fi[roomArea][i].second * Fi[roomArea][j].second * ds[roomArea];
		}
	}
	return area;
}

map<int,pair<bool,int> > integral::BuildAreaElm_K( int n, int row, int column)
{
	map<int,pair<bool,int> > K;
	for(int i = 1 ; i < 7 ; ++i)
	switch(i)
	{
		case 1:
		{
			if(( 0 <= row && row < n ) && ( 0 <= column && column <= n-2 ))
			{	
				K[1].first = true;
				// if(row-1 < N-1)
				// 	K[1].second = 0;
				// else K[1].second = 1;
			}
			else K[1].first = false;	
			break;
		}
		case 2:
		{
			if(( 0 <= row && row < n ) && ( 0 <= column && column <= n-2))
			{
				K[2].first = true;
				if(row-1 < N-1)
					K[2].second = 0;
				else K[2].second = 1;
			}	
			else K[2].first = false;
			break;
		}
		case 3:
		{
			if(( 0 <= row && row <= n ) && ( 0 <= column && column <= n ))
			{
				K[3].first = true;
				if(row-1 < N-1)
					K[3].second = 0;
				else K[3].second = 1;
			}
			else K[3].first = false; 
			break;
		}
		case 4:
		{
			if(( 0 <= row && row <= n ) && ( 1 <= column && column <= n ))
			{
				K[4].first = true;
				//лежат на границе изменения конечного элемента
				// if(row < N)
				// 	K[4].second = 0;
				// else K[4].second = 1;
			}
			else K[4].first = false;	
			break;
		}
		case 5:
		{
			if(( 0 <= row && row <= n ) && ( 1 <= column && column <= n))
			{
				K[5].first = true;
				if(row+1 < N)
					K[5].second = 0;
				else K[5].second = 1;
			}
			else K[5].first = false;
			break;
		}
		case 6:
		{	
			if(( 0 <= row && row <= n ) && ( 0 <= column && column <= n))
			{
				K[6].first = true;
				if(row+1 < N)
					K[6].second = 0;
				else K[6].second = 1;
			}
			else K[6].first = false;
			break;
		}
	
	}
	return K;
}

map<int,pair<bool,int> > integral::BuildAreaTriangl_K(map<int,pair<bool,int> > K)
{
	map<int,pair<bool,int> > triangl_K;//Данные о треугольниках
	//Проверка на существование треугольников
	if( K[1].first == true && K[2].first == true )
	{
		triangl_K[1].first = true;
		triangl_K[1].second = K[2].second;
	}
	else triangl_K[1].first = false;
	if( K[2].first == true && K[3].first == true )
	{
		triangl_K[2].first = true;
		triangl_K[2].second = K[2].second;
	}
	else triangl_K[2].first = false;
	if( K[3].first == true && K[4].first == true )
	{
		triangl_K[3].first = true;
		triangl_K[3].second = K[3].second;
	}
	else triangl_K[3].first = false;
	if( K[4].first == true && K[5].first == true )
	{
		triangl_K[4].first = true;
		triangl_K[4].second = K[5].second;
	}
	else triangl_K[4].first = false;
	if( K[5].first == true && K[6].first == true )
	{
		triangl_K[5].first = true;
		triangl_K[5].second = K[5].second;
	}
	else triangl_K[5].first = false;

	if( K[6].first == true && K[1].first == true )
	{
		triangl_K[6].first = true;
		triangl_K[6].second = K[6].second;
	}
	else triangl_K[6].first = false;
	return triangl_K;
}

map<int,double> integral::TriangleArea(map<int,pair<bool,int> > triangl_K, pair<int,int> x, int number)
{
	map<int,double> T;//площади треугольников
	//Зануление всех переменных площадей К
	for(int j = 0 ; j < 7 ; ++j)
		T[j] = 0.0;
	// k == 0
	for(int i = 1; i < 7 ; ++i)
		if( triangl_K[i].first == true)
			T[0] += Area(i,i,x,number,triangl_K[i].second);//0 - узел начальный i - номер треугольника
	// k=1
	if(triangl_K[1].first == true)
		T[1] += Area(3,1,x,number,triangl_K[1].second);
	if(triangl_K[6].first == true)
		T[1] += Area(4,6,x,number,triangl_K[6].second);
	// k=2
	if(triangl_K[1].first == true)
		T[2] += Area(5,1,x,number,triangl_K[1].second);
	if(triangl_K[2].first == true)
		T[2] += Area(4,2,x,number,triangl_K[2].second);
	// k=3
	if(triangl_K[2].first == true)
		T[3] += Area(6,2,x,number,triangl_K[2].second);
	if(triangl_K[3].first == true)
		T[3] += Area(5,3,x,number,triangl_K[3].second);
	// k=4
	if(triangl_K[3].first == true)
		T[4] += Area(1,3,x,number,triangl_K[3].second);
	if(triangl_K[4].first == true)
		T[4] += Area(6,4,x,number,triangl_K[4].second);
	// k=5
	if(triangl_K[4].first == true)
		T[5] += Area(2,4,x,number,triangl_K[4].second);
	if(triangl_K[5].first == true)
		T[5] += Area(1,5,x,number,triangl_K[5].second);
	// k=6
	if(triangl_K[5].first == true)
		T[6] += Area(3,5,x,number,triangl_K[5].second);
	if(triangl_K[6].first == true)
		T[6] += Area(2,6,x,number,triangl_K[6].second);
	return T;
}	