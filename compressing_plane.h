#ifndef COMPRESSING_PLANE_H
#define COMPRESSING_PLANE_H
#include "header.h"
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
	double N;		// N-количество узлов
	double H;		// H-шаг сетки
	double G;		// G-Коэффициент Лама
	double E;		// E-модуль упругости(Юнга)
	double M;		// M-Коэффициент Пуассона
	double f;		// f-Объемная сила
	list<double> P;	// P-Поверхностная сила
	map<int,list<list<double> > > matrixMatrix_NxN;// Матрица содержащяя строки по элементро для каждого элемента сетки
	void MultiplicationByConstant( map< char ,list< map<int,double> > > &T );// Домножение на числа
	
	vector<vector<double> > MatrixNxN(int xi,int xi);// Расчетматрицы 21 на 21 только без 0 строк

	CompressingPlane();
	~CompressingPlane();

	// Нахождение входных параметров
	void F_fun(FILE * freopen);
};
#endif