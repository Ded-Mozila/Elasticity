#ifndef ZEIDELY_H
#define ZEIDELY_H
#include "header.h"

class Zeidely
{
public:
	Zeidely();
	~Zeidely();
	double FirstNorm(list<list<double> > A);
	double SecondNorm(list<list<double> > A);
	double ThirdNorm(list<list<double> > A);
	void Iterat(list<list<double> > A, vector<double> B, int N, double eps);
	double okr(double X, double eps);
};

#endif

