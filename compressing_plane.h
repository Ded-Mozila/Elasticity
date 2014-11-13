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
	list<power> P;	// P-Поверхностная сила

	CompressingPlane();
	~CompressingPlane();

	// Нахождение входных параметров
	void F_fun(fstream& settings);
};
#endif