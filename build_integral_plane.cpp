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

double integral::BuildAreaElm_K(int  k, int xi, int xj int row, double column)
{
	double area = 0;
	switch(k)
	{
		case 0:
		{
			//проити по кругу и определить какие из тереугольников пренадлежат
			if(column+1 > 0 || column+1 < N)
			
			break;
		}
		case 1:
		{
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			break;
		}
		case 6:
		{
			break;
		}
	}
	return area;
}
