#include "build_integral_plane.h"

integral::integral()
{
}
integral::~integral()
{
}

integral::integral(double h, int N)
{
	n(N);
	Fi[1] = make_pair(-1/h,0.0);
	Fi[2] = make_pair(0.0,-1/h);
	Fi[3] = make_pair(1/h,-1/h);
	Fi[4] = make_pair(1/h,0.0);
	Fi[5] = make_pair(0.0,1/h); 
	Fi[6] = make_pair(-1/h,1/h);
}
bool integral::NodeBelongsRegions(int row, int column, int h, int l, int k)
{
	
	return false;
}
map<int,bool> integral::BuildAreaElm_K( int l, int h int row, double column)
{
	map<int,bool> K;
	for(int i = 1 ; i< 7 ; ++i)
	switch(i)
	{
		case 1:
		{
			if(( 0 <= row && row < N ) && ( 0 <= column && column < N-1 ))
				K[1] = true;
			else K[1] = false;	
			break;
		}
		case 2:
		{
			if(( 1 < row && row < N ) && ( 0 <= column && column < N-1))
				K[2] = true;
			else K[2] = false;
			break;
		}
		case 3:
		{
			if(( 1 < row && row < N ) && ( 0 <= column && column < N ))
				K[3] = true;
			else K[3] = false; 
			break;
		}
		case 4:
		{
			if(( 0 <= row && row < N ) && ( 1 < column && column < N ))
				K[4] = true;
			else k[4] = false;	
			break;
		}
		case 5:
		{
			if(( 0 <= row && row < N-1 ) && ( 1 < column && column < N))
				K[5] = true;
			else K[5] = false;
			break;
		}
		case 6:
		{	
			if(( 0 <= row && row < N-1 ) && ( 0 < column && column < N))
				k[6] = true;
			else k[6] = false;
			break;
		}
	}
	return K;
}
