#ifndef ZEIDELY_H
#define ZEIDELY_H
#include "header.h"

class Zeidely
{
public:
	Zeidely();
	~Zeidely();
	double FirstNorm(vector<vector<double> > A);
	double SecondNorm(vector<vector<double> > A);
	double ThirdNorm(vector<vector<double> > A);
	void Iterat(vector<vector<double> > A, vector<double> B, int N, double eps);
	vector<double> Iterat1(vector<vector<double> > A, vector<double> B, int N, double eps);
	vector<double> Iterat2(vector<vector<double> > A, vector<double> B, int N, double eps);


	double okr(double X, double eps);
};

#endif

