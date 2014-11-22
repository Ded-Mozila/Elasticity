#ifndef BUILD_INTEGRAL_PLANE_H
#define BUILD_INTEGRAL_PLANE_H
#include "header.h"

class integral
{
public:
	integral(void);
	~integral(void);
	integral(double h);
	map< char[3] ,list< map<int,double> > >T;
	map<char, pair<double,double> > Fi;
	double l;
	double H;
	double CalculatingArea(double h, double l)
};

#endif