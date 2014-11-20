//func.h
#ifndef FUNC_H 
#define FUNC_H
#include "header.h"

class MatrixElement//
{
public:
	MatrixElement(void);
	~MatrixElement(void);
	point t1;
	point t2;
};
list<MatrixElement> stringMatrix(const long int str , const long int post, const long int n);//функция заполнения матрицы 
list<double> FillingMatrix(int number, map< char ,list< map<int,double> > >T,int row, int column, int N); // Заполние матрицы в зависимости от положения конечного элемента
list<list<double> > BuildMatrix(int number,const map< char ,list< map<int,double> > >T , int N);

#endif


