#ifndef BUILD_INTEGRAL_PLANE_H
#define BUILD_INTEGRAL_PLANE_H
#include "header.h"

class integral
{
public:
	integral(void);
	~integral(void);
	integral(double h, int n, double e, double m, int a); //Конструктор с входными данными
	map<int,pair<double,double> > H;			// Шаг матрицы по х и у для каждой облати
	int N;										// Количество узлов
	int a;										// Острый угол у треугольника 
	double E;									// E-модуль упругости(Юнга)
	double M;									// M-Коэффициент Пуассона
	double G;
	map<int,map<int,pair<double,double> > >Fi;	// библиотека базисов для каждого треугольника
	vector<double> B;							// Вектор свободных членов
	map<int,double> ds;							//Площадь треугольника для каждой области
	vector<double> CalcElememt(int row, int column ,pair<int,int> x , int number); // нахождение вектора матрицы с заданным конгечным элементом
	double Area( int i, int j, pair<int,int> x, int number, int roomArea);	//Расчет площади треугольника
	map<int,pair<bool,int> > BuildAreaElm_K( int n, int row, int column);	// Расчет конечной области конечного эленмента для данного узла (какие узлы входят в облать)
	vector<vector<double> > MakePlane(pair<int,int> x, int number);// Создание глобальной(1/4 матрицы жескости) матрицы жескости
	map<int,pair<bool,int> > BuildAreaTriangl_K(map<int,pair<bool,int> > K); //Определение существующих треугольников и областям которым они пренадлежат
	map<int,double> TriangleArea(map<int,pair<bool,int> > triangl_K, pair<int,int> x, int number); //Расчет площади треугольников для каждого из узлов
};

#endif