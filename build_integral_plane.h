#ifndef BUILD_INTEGRAL_PLANE_H
#define BUILD_INTEGRAL_PLANE_H
#include "header.h"

class integral
{
public:
	integral(void);
	~integral(void);
    integral(double h, double l , int n, double e, double m);
	double l;
	double H;
	int N;
    double E;                           // E-модуль упругости(Юнга)
    double M;                           // M-Коэффициент Пуассона
    map<int,pair<double,double> >Fi; 
    vector<double> B;
    double ds;                          //Площадь треугольника
    vector<double> CalcElememt(int row, int column ,int xi , int xj , int number);
    double Area( int i, int j, int xi, int xj , int number);
    map<int,bool> BuildAreaElm_K( int n, int row, int column);
    vector<vector<double> > MakePlane(pair<int,int> x, int number);
};

#endif