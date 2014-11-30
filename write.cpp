#include "write.h"

void WriteMatrix_vector(vector<vector<double> > matrix)
{
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[i].size(); ++j)
			cout << matrix[i][j] << ' ';
		cout << endl;
	}
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
void genMatrix_plot(vector<double> x , int number,double h, string nameFile)
{
	int k = 0;
	///t1 - y координата
	vector<vector<double> > matrix_t1;//(number, 0.0)
	// for (int i = 0; i < number; ++i)
	// 	matrix_t1[i].resize(number);
	vector<double> t0(number, 0);
	matrix_t1.push_back(t0);
	for (int i = 0; i < number-2; ++i)
	{
		vector<double> line;
		for (int j = 0; j < number; ++j)
		{
			line.push_back(x[++k]);
		}
		matrix_t1.push_back(line);
	}
	matrix_t1.push_back(t0);


	///t2 - x координата
	vector<vector<double> > matrix_t2;//(number, 0.0)
	// for (int i = 0; i < number; ++i)
	// 	matrix_t2[i].resize(number);
	matrix_t2.push_back(t0);
	for (int i = 0; i < number-2; ++i)
	{
		vector<double> line;
		for (int j = 0; j < number; ++j)
		{
			line.push_back(x[++k]);
		}
		matrix_t2.push_back(line);
	}
	matrix_t2.push_back(t0);
	freopen(nameFile.c_str(),"w+",stdout);
	for (int i = 0; i < number; ++i)
	{
		for (int j = 0; j < number; ++j)
		{
			cout << i*h << " " << j*h << " "  << matrix_t1[j][i] << " " << matrix_t2[j][i] << endl;
		}
		cout << endl;
	}
	fclose(stdout);
}