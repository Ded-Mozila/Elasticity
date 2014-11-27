#include "zeidely.h"
 Zeidely::Zeidely()
{
}
 Zeidely::~Zeidely()
{
}
double Zeidely::FirstNorm(vector<vector<double> > A)
{
	double sum = 0, subSum;
	vector<vector<double> >::iterator i;
	vector<double>::iterator  j;
	for (i = A.begin(); i != A.end(); ++i)
	{
		subSum = 0;
		for (j = (*i).begin(); j != (*i).end(); ++j)
			subSum += abs(*j);
		if(subSum > sum)
			sum = subSum;
	}
	return sum;
}

double Zeidely::SecondNorm(vector<vector<double> > A)
{
	double sum = 0, subSum;
	vector<vector<double> >::iterator i;
	vector<double>::iterator  j;
	for (i = A.begin(); i != A.end(); ++i)
	{
		subSum = 0;
		for (j = (*i).begin(); j != (*i).end(); ++j)         
			subSum += abs(*j);
		if(subSum > sum) 
			sum = subSum;
	}
	return sum;
}

double Zeidely::ThirdNorm(vector<vector<double> > A)
{
	double sum = 0;
	vector<vector<double> >::iterator i;
	vector<double>::iterator  j;
	for (i = A.begin(); i != A.end(); ++i)
		for (j = (*i).begin(); j != (*i).end(); ++j)
			sum += ((*j) * (*j));
	sum = sqrt(sum);
	return sum;
}
void printMatrix (string message, vector <long double> matrix, size_t size) {
	size_t i, j;

	cout << "\n" << message << ":\n" << endl;

	for (i = 0 ;  i < size;  ++i) {
		cout << setw(8) << setprecision(3) << fixed << matrix[i];

		if ( ( i + 1 ) % 3 == 0 )
			cout << endl;
	}
}


double Zeidely::okr(double X, double eps)
{
	int i = 0;
	while (eps != 1) {
		i++;
		eps *= 10;
	}
	int okr = pow(double(10), i);
	X = int(X * okr + 0.5) / double(okr);
	return X;
}

void printMatrix (string message, vector < vector <long double> > matrix, size_t size_col, size_t size_row) {
	size_t i, j;

	cout << "\n" << message << ":\n" << endl;

	for (i = 0 ;  i < size_col;  ++i) {
		for(j = 0; j < size_row;  ++j) {
			cout << setw(8) << setprecision(3) << fixed << matrix[i][j];

			if ( ( j + 1 ) % size_row == 0 )
				cout << endl;
		}

		if ( ( i + 1 ) % size_col == 0 )
			cout << endl;
	}
}

void Zeidely::Iterat(vector<vector<double> > A, vector<double> B, int N, double eps)
{
	cout << A.size() << endl;

	//  if (ThirdNorm(A) < 1) 
	//  {
	// 	int k = 0;
	// 	vector<double> X(B);
	// 	int i,j;
	// 	double s;
	// 	double g;
	// 	vector<vector<double> >::iterator ii;
	// 	vector<double>::iterator ij;
	// 	do {
	// 		s = 0; k++;
	// 		// Решаем систему методом Зейделя.
	// 		for ( ii = A.begin(), i = 0 ; ii != A.end() ;++i, ++ii ) 
	// 		{
	// 			g = B.at(i);
	// 			for ( ij = (*ii).begin(), j = 0 ; ij != (*ii).end() ; ++j, ++ij)
	// 				g = g + (*ij) * X.at(i);

	// 			s += (X.at(i) - g) * (X.at(i) - g);
	// 			X.at(i) = g;
	// 		}
	// 		cout
	// 	} while (sqrt(s) <= eps * (1 - ThirdNorm(A)) / ThirdNorm(A));
	// 	for (i = 0; i < X.size(); ++i)
	// 		cout << "X" << i+1 << " = " << okr( X.at(i) ,eps) << endl;
	// 	cout << "Число итераций: " << k-1 << endl;
	// 	cout << "Первая норма матрицы A: " << FirstNorm(A) << endl;
	// 	cout << "Вторая норма матрицы A: " << SecondNorm(A) << endl;
	// 	cout << "Третья норма матрицы A: " << ThirdNorm(A) << endl;
	// fclose(stdout);	

	// } else {
	// 	cerr << "Условие сходимости по евклидовой метрике не выполняется!" << endl;
	// // }
	// vector<double> x(B);
	// vector<double> xn(B);
	// vector<vector<double> >::iterator ii;
	// vector<double>::iterator ij;
	// double w=1 ,norma;
	// int k = 0;
// 	do
// 	{  
// 		k++;
// 		cout << k << endl;
// 		norma=0;

// 		for(i=0;i<A.size()+1;++i)
// 		{
// 			x.at(i)=B.at(i);
// 			for(j=0;j<A.at(i).size()+1;++j)
// 			{
// 				if(i!=j)
// 				x.at(i)=x.at(i)-A.at(i).at(j)*x.at(j);
// 			}
// 			x.at(i)/=A.at(i).at(i);

// 		 //x.at(i)=w*x.at(i)+(1-w)*xn.at(i);
				   
// 			if(fabs(x.at(i)-xn.at(i)) > norma)
// 			  norma=fabs(x.at(i)-xn.at(i));
// 			  xn.at(i)=x.at(i);
// 	}
// 	}
// 	 while(norma > eps);
// 	 cout<<"Кол-во итераций: ";cout<<k<<" \n";
// 	 for(i=0;i<x.size();++i)
// 		 cout<<"x ["<<i+1<<"] = "<<x.at(i)<<"; ";
//fclose(stdout);
	
	int size =A.size();
	int k = 0 ;
	//версия 2.0
	double error_old=0.0;

	int iterator = 0;

	vector <long double> previousVariableValues (size, 0.0);
	vector <long double> currentVariableValues (size);

	long double error = 0.0;

	do {
		iterator++;
		error = 0;

		cout << "\nИтерация номер " << iterator;
		for (int i = 0; i < size; i++)
		{
			currentVariableValues[i] = B[i];

			for (int j = 0; j < size; j++)
			{
				if (i != j)
				{
					currentVariableValues[i] -= A[i][j] * previousVariableValues[j];
				}
			}

			currentVariableValues[i] /= A[i][i];
		}

		if (iterator != 1) {
			cout << "\nПогрешность вычисления: \n";
		}

		for (int i = 0; i < size; i++)
		{

			error = fabs(currentVariableValues[i] - previousVariableValues[i]) > error ? fabs(currentVariableValues[i] - previousVariableValues[i]):error;

			if (iterator != 1) {
				cout << setw(8) << setprecision(6) << fixed << error << endl;
			}
		}

		previousVariableValues = currentVariableValues;

		printMatrix("Текущие значения", previousVariableValues, size);

	} while (error >= eps );

























	// vector <double> previousVariableValues (size, 0.0);
	// while (true)
 //    {
 //    	cout << ++k << " ";
 //        // Введем вектор значений неизвестных на текущем шаге       
 //        vector <double> currentVariableValues (B.begin(),B.end());

 //        // Посчитаем значения неизвестных на текущей итерации
 //        // в соответствии с теоретическими формулами
 //        for (int i = 0; i < size; ++i)
 //        {
 //            // Инициализируем i-ую неизвестную значением 
 //            // свободного члена i-ой строки матрицы

 //            // Вычитаем сумму по всем отличным от i-ой неизвестным
 //            for (int j = 0; j < size; ++j)
 //            {
 //                // При j < i можем использовать уже посчитанные
 //                // на этой итерации значения неизвестных
 //                if (j < i)
 //                {
 //                    currentVariableValues[i] -= A[i][j] * currentVariableValues[j];
 //                	cout<<currentVariableValues[i] <<endl;
 //                }

 //                // При j > i используем значения с прошлой итерации
 //                if (j > i)
 //                {

 //                    currentVariableValues[i] -= A[i][j] * previousVariableValues[j];
 //                	cout<<currentVariableValues[i] << endl;
 //                }
 //            }

 //            // Делим на коэффициент при i-ой неизвестной
 //            currentVariableValues[i] /= A[i][i];
 //        }

 //        // Посчитаем текущую погрешность относительно предыдущей итерации
 //        double error = 0.0;
        
 //        for (int i = 0; i < size; ++i)
 //        {
 //        	//cout << (currentVariableValues[i] - previousVariableValues[i]) <<endl;
 //            error += fabs (currentVariableValues.at(i) - previousVariableValues.at(i));
 //           // cin >> k;

 //        }

 //         cout << error << " < "  << eps  << endl;
 //        // Если необходимая точность достигнута, то завершаем процесс
 //        if (error < eps)
 //        {
 //            break;
 //        }
 //        if (error > error_old)
 //        {
 //        	 break;
 //        }

 //        // Переходим к следующей итерации, так 
 //        // что текущие значения неизвестных 
 //        // становятся значениями на предыдущей итерации
 //        previousVariableValues = currentVariableValues;
 //    }
	/*while (true)
	  {
	  	cout << ++k << " ";
		  // Введем вектор значений неизвестных на текущем шаге       
		  vector <long double> currentVariableValues (size,0.0);

		  // Посчитаем значения неизвестных на текущей итерации
		  // в соответствии с теоретическими формулами
		  for (int i = 0; i < size; ++i)
		  {
			  // Инициализируем i-ую неизвестную значением 
			  // свободного члена i-ой строки матрицы
			  currentVariableValues.at(i)  = A.at(i).at(size);

			  // Вычитаем сумму по всем отличным от i-ой неизвестным
			  for (int j = 0; j < size; ++j)
			  {
				  // При j < i можем использовать уже посчитанные
				  // на этой итерации значения неизвестных
				  if (j < i)
				  {
					  currentVariableValues.at(i) -= A.at(i).at(j) * currentVariableValues.at(j) ;
				  }

				  // При j > i используем значения с прошлой итерации
				  if (j > i)
				  {
					  currentVariableValues.at(i)  -= A.at(i).at(j) * previousVariableValues.at(j) ;
				  }
			  }

			  // Делим на коэффициент при i-ой неизвестной
			  currentVariableValues.at(i)  /= A.at(i).at(i);
		  }

		  // Посчитаем текущую погрешность относительно предыдущей итерации
		  long double error = 0;
		  
		  for (int i = 0; i < size; ++i)
		  {
			  error += abs (currentVariableValues.at(i) - previousVariableValues.at(i) );
		  }
		  cout << error << " < "  << eps  << endl;
		  // Если необходимая точность достигнута, то завершаем процесс
		  if (error < eps)
		  {
			  break;
		  }

		  // Переходим к следующей итерации, так 
		  // что текущие значения неизвестных 
		  // становятся значениями на предыдущей итерации
		  previousVariableValues = currentVariableValues;
	  }*/
	  // Выводим найденные значения неизвестных с 8 знаками точности
	  	freopen("outtext.txt","w+",stdout);
    for (int i = 0; i < size; ++i)
    {
        cout << previousVariableValues.at(i)  << endl;
    }
	fclose(stdout);

}