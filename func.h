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
#endif