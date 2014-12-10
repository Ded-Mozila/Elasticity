#include "write.h"

void WriteMatrix_vector(vector<vector<double> > matrix)
{
	freopen("matrix.txt","w+",stdout);
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[i].size(); ++j)
			cout << matrix[i][j] << ' ';
		cout << endl;
	}
	fclose(stdout);
}
void WriteMapMatrix_vector(map<int,vector<vector<double> > > matrixMatrix_NxN)
{
	for (int i = 0; i < 4; ++i)
	{
		cout << i << endl;
		WriteMatrix_vector(matrixMatrix_NxN[i]);	
	}
	cout << "\n\n\n";
}

void DecodingMatrix(vector<double> line, int size)
{
	int k = 1;
	for (int i = 0; i <  line.size(); ++i, ++k)
	{
		cout << line[i] << ' ';
		if (k == size)
		{
			k=0;
			cout << endl;
		}
	}
}
void  WriteminiMatrix(vector<vector<double> > matrix)
{
	for (int i = 0; i < matrix.size(); ++i)
	{
		DecodingMatrix(matrix[i], 5);
		cout << "\n";
	}
}
void WriteVector(vector<double> line)
{
	freopen("vector.txt","w+",stdout);
	for (int i = 0; i < line.size(); ++i)
	{
		cout << line[i] << endl;
	}
	fclose(stdout);
}
void genMatrix_plot(vector<double> x , int number,double h, string nameFile, int a)
{
	int k = 0;
	///t1 - y координата
	vector<vector<double> > matrix_t1;
	for (int i = 0; i < number; ++i)
	{
		vector<double> line;
		for (int j = 0; j < number*2-i-1; ++j)
		{
			line.push_back(x[k]);
			k +=1;
		}
		matrix_t1.push_back(line);
	}
	///t2 - x координата
	vector<vector<double> > matrix_t2;
	for (int i = 0; i < number; ++i)
	{
		vector<double> line;
		for (int j = 0; j < number*2-i-1; ++j)
		{
			line.push_back(x[k]);
			k+=1;
		}
		matrix_t2.push_back(line);
	}

	freopen(nameFile.c_str(),"w+",stdout);
	double h2 = h/tan(a*M_PI/180);
	double dh = 0;
	for (int i = 0; i < number; ++i)
	{
		dh = 0;
		for (int j = 0; j < number*2-i-1; ++j)
		{
			// cout 
			cout << dh;
			if(j < (number-1) )
					dh+=h;
			else dh+=h2; 
			cout  << " " << i*h << " " << (-1)*matrix_t1[i][j] << " " << matrix_t2[i][j]  << endl;
		}
		cout << endl;
	}
	fclose(stdout);
}