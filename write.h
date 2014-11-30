#ifndef WRITE_H
#define WRITE_H
#include "header.h"
void WriteMatrix_vector(vector<vector<double> > matrix);
void WriteMapMatrix_vector(map<int,vector<vector<double> > > matrixMatrix_NxN);

void  WriteminiMatrix(vector<vector<double> > matrix);
void DecodingMatrix(vector<double> line, int size);
void WriteVector(vector<double> line);
void genMatrix_plot(vector<double> x , int number,double h, string nameFile);
#endif