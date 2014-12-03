#include "compressing_plane.h"
#include "write.h"
CompressingPlane::CompressingPlane(int n, int a)
{
		//Начальные настройки для задачи
		A = a;
		M = 0.3;
		E = 1000000000;
		H = 0.05;
		F.push_back(2);
		F.push_back(3);
		G = (E/(2*(1+M)));
		N = n;
		f = 0;
		p1 =100.0;
		p2 =-100.0;
		P.push_back(100.0);
		P.push_back(-100.0);
}
CompressingPlane::~CompressingPlane()
{

}


vector<vector<double> > CompressingPlane::MatrixNxN(pair<int,int> x, int number)
{
	integral mat(H,N,E,M,A);
	return mat.MakePlane(x, number);
}

vector<vector<double> > CompressingPlane::Multiplication(int a,int b)
{
	vector<vector<double> > Matrix(matrixMatrix_NxN[a]);
	for (int i = 0; i < Matrix.size(); ++i)
		for (int j = 0; j < Matrix[i].size(); ++j)
			Matrix[i][j] += matrixMatrix_NxN[b][i][j];
	return Matrix;
}
void CompressingPlane::MatrixCompit(int x)
{
	if(x ==1)
	{
		matrixMatrix_NxN[0] = MatrixNxN(make_pair(1,1),1);//1
		matrixMatrix_NxN[1] = MatrixNxN(make_pair(2,1),1);//2
		matrixMatrix_NxN[2] = MatrixNxN(make_pair(2,2),1);//1
		matrixMatrix_NxN[3] = MatrixNxN(make_pair(1,2),1);//2
	}
	else if(x ==2)
	{
		matrixMatrix_NxN[0] = MatrixNxN(make_pair(2,2),2);//2
		matrixMatrix_NxN[1] = MatrixNxN(make_pair(1,2),2);//1
		matrixMatrix_NxN[2] = MatrixNxN(make_pair(2,1),2);//1
		matrixMatrix_NxN[3] = MatrixNxN(make_pair(1,1),2);//2
	}
}

vector<vector<double> > CompressingPlane::InsertMatix(vector<vector<double> > t1,vector<vector<double> > t2)
{
	vector<vector<double> >::iterator i;
	vector<vector<double> >::iterator ii;
	vector<vector<double> > Matrix(t1);// Матрица значений t1
	for ( i = Matrix.begin(), ii = t2.begin(); i != Matrix.end(), ii != t2.end(); ++i , ++ii)
		(*i).insert((*i).end(),(*ii).begin(),(*ii).end());
	return Matrix;
}
vector<double> CompressingPlane::B_l(int size, double p)
{
	vector<double> B;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N*2-i ; ++j)
		{
			if( j>0 && j < N*2-i-1 )
			{
				if( i == 0 )
				{
					if(j < N )
						B.push_back(p*H);
					else B.push_back(p*H/tan(A*M_PI/(180))); 
				}
				else 
				{	
					if ( i == N-1 )
					{	
						B.push_back(p*H*(-1));
					}
					else B.push_back(0);
				}
			}else B.push_back(0);
		}
	}
	return B;
}
vector<double> CompressingPlane::B_r (int size, double p)
{

	vector<double> B;
	for (int i = 0; i < size; ++i)
	{
		B.push_back(0);
	}
	return B;
}