#include "build_integral_plane.h"

integral::integral()
{
}
integral::~integral()
{
}

integral::integral(double h, double l , int N)
{
	n(N);
	ds = h*l/2;
	Fi[1] = make_pair(-1/h,0.0);
	Fi[2] = make_pair(0.0,-1/h);
	Fi[3] = make_pair(1/h,-1/h);
	Fi[4] = make_pair(1/h,0.0);
	Fi[5] = make_pair(0.0,1/h); 
	Fi[6] = make_pair(-1/h,1/h);
}
vector<double> integral::CalcElememt(int row, int column ,int xi , int xj )// xi- первая константа для dFik/dxi , xj  - вторая константа для dFi/dxj 
{
	map<int, bool> K(BuildAreaElm_K(N,row,column);
	map<int, bool> triangl_K;
	//Проверка на существование треугольников
	for( int i = 1; i < 6; ++i)
		if( K[i] == true && K[i+1] == true )
			triangl_K[i] = true;
		else triangl_K[i] = false;
	if( K[6] == true && K[1] == true )
		triangl_K = true;
	else triangl_K[6] = false;
	map<int,double> T;//площади треугольников
	for(int j = 0 ; j < 7 ; ++j)
		T[j] = 0.0;
	// k == 0
	for(int i = 1; i < 7 ; ++i)
		if( triangl_K[i] == true)
			T[0] += Area(i,i,xi,xj);//0 - узел начальный i - номер треугольника
	// k=1
	if(triangl_K[1] == true)
		T[1] += Area(3,1,xi,xj);
	if(triangl_K[6] == true)
		T[1] += Area(4,6,xi,xj);
	// k=2
	if(triangl_K[1] == true)
		T[2] += Area(5,1,xi,xj);
	if(triangl_K[2] == true)
		T[2] += Area(4,2,xi,xj);
	// k=3
	if(triangl_K[2] == true)
		T[3] += Area(6,2,xi,xj);
	if(triangl_K[3] == true)
		T[3] += Area(5,3,xi,xj);
	// k=4
	if(triangl_K[3] == true)
		T[4] += Area(1,3,xi,xj);
	if(triangl_K[4] == true)
		T[4] += Areea(6,4,xi,xj);
	// k=5
	if(triangl_K[4] == true)
		T[5] += Area(2,4,xi,xj);
	if(triangl_K[5] == true)
		T[5] += Area(1,5,xi.xj);
	// K=6
	if(triangl_K[5] == true)
		T[6] += Area(3,5,xi,xj);
	if(triangl_K[6] == true)
		T[6] += Area(2,6,xi,xj);

}
double integral::Area( int i, int j int xi, int xj )
{	
	double area = 0.0;
	if(xi == 1 && xj == 1)
		area += Fi[i].first * Fi[j].first * ds;
	else if(xi == 1 && xj == 2)
		area += Fi[i].first * Fi[j].second * ds;
	else if(xi == 2 && xj == 1)
		area += Fi[i].second * Fi[j].first * ds;
	else if(xi == 2 && xj == 2)
		area += Fi[i].second * Fi[j].cecond * ds;
	else area -=1;//неверный вариант
	return ;
}
bool integral::NodeBelongsRegions(int row, int column, int h, int l, int k)
{
	
	return false;
}
map<int,bool> integral::BuildAreaElm_K( int N, int row, int column)
{
	map<int,bool> K;
	for(int i = 1 ; i< 7 ; ++i)
	switch(i)
	{
		case 1:
		{
			if(( 0 <= row && row < N ) && ( 0 <= column && column < N-1 ))
				K[1] = true;
			else K[1] = false;	
			break;
		}
		case 2:
		{
			if(( 1 < row && row < N ) && ( 0 <= column && column < N-1))
				K[2] = true;
			else K[2] = false;
			break;
		}
		case 3:
		{
			if(( 1 < row && row < N ) && ( 0 <= column && column < N ))
				K[3] = true;
			else K[3] = false; 
			break;
		}
		case 4:
		{
			if(( 0 <= row && row < N ) && ( 1 < column && column < N ))
				K[4] = true;
			else k[4] = false;	
			break;
		}
		case 5:
		{
			if(( 0 <= row && row < N-1 ) && ( 1 < column && column < N))
				K[5] = true;
			else K[5] = false;
			break;
		}
		case 6:
		{	
			if(( 0 <= row && row < N-1 ) && ( 0 < column && column < N))
				k[6] = true;
			else k[6] = false;
			break;
		}
	}
	return K;
}


