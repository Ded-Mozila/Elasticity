#ifndef COMPRESSING_PLANE_H
#define COMPRESSING_PLANE_H
#include "header.h"
#include "build_integral_plane.h"
struct power
{
	double U1;	//Параметры
	double U2;	//Параметры
	int side;	//Направление	
};
class CompressingPlane //Сжатие поверхности с двухсторон
{
public:
	list<double> F;	// F-граница
	double V;		// V-Внутренние узлы
	int N;		// N-количество узлов
	double H;		// H-шаг сетки
	double G;		// G-Коэффициент Лама
	double E;		// E-модуль упругости(Юнга)
	double M;		// M-Коэффициент Пуассона
	double f;		// f-Объемная сила
	list<double> P;	// P-Поверхностная сила
	vector<double> B;
	map<int,vector<vector<double> > > matrixMatrix_NxN;// Матрица содержащяя строки по элементро для каждого элемента сетки
	CompressingPlane();
	~CompressingPlane();
	vector<vector<double> > MatrixNxN(pair<int,int> x);
};
#endif