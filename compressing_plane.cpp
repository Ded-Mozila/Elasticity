#include "compressing_plane.h"

CompressingPlane::CompressingPlane()
{
		//Начальные настройки для задачи
		M = 0.3;
		E = 1e-9;
		H = 0.05;
		F.push_back(2);
		F.push_back(3);
		G = (E/(2*(1-M)));
		N = 21;
		f = 0;
		P.push_back(100.0);
		P.push_back(-100.0);
}
CompressingPlane::~CompressingPlane()
{
	
}


vector<vector<double> > CompressingPlane::MatrixNxN(pair<int,int> x)
{
	integral mat(H,H,N,E,M);
	return mat.MakePlane(x);
}
