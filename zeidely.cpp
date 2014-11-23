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

void Zeidely::Iterat(vector<vector<double> > A, vector<double> B, int N, double eps)
{
	freopen("outtext.txt","w+",stdout);
	 if (ThirdNorm(A) < 1) 
	 {
		int k = 0;
		vector<double> X(B);
		int i,j;
		double s;
		double g;
		vector<vector<double> >::iterator ii;
		vector<double>::iterator ij;
		do {
			s = 0; k++;
			// Решаем систему методом Зейделя.
			for ( ii = A.begin(), i = 0 ; ii != A.end() ;++i, ++ii ) 
			{
				g = B.at(i);
				for ( ij = (*ii).begin(), j = 0 ; ij != (*ii).end() ; ++j, ++ij)
					g = g + (*ij) * X.at(i);

				s += (X.at(i) - g) * (X.at(i) - g);
				X.at(i) = g;
			}
			cout << k << endl;
		} while (sqrt(s) != eps * (1 - ThirdNorm(A)) / ThirdNorm(A));
		for (i = 0; i < X.size(); ++i)
			cout << "X" << i+1 << " = " << okr( X.at(i) ,eps) << endl;
		cout << "Число итераций: " << k-1 << endl;
		cout << "Первая норма матрицы A: " << FirstNorm(A) << endl;
		cout << "Вторая норма матрицы A: " << SecondNorm(A) << endl;
		cout << "Третья норма матрицы A: " << ThirdNorm(A) << endl;
	fclose(stdout);	

	} else {
		cerr << "Условие сходимости по евклидовой метрике не выполняется!" << endl;
	}

	
	// int size = A.size();
	// vector <vector < long double> > matrix;

	// for (vector<vector<double> >::iterator i = A.begin(); i != A.end(); ++i)
	// {
	// 	vector<long double> mm;
	// 	mm.insert(mm.end(),(*i).begin(), (*i).end());
	// }
	// //версия 2.0
	// vector <long double> previousVariableValues (size, 0.0);
	// while (true)
	//   {
	// 	  // Введем вектор значений неизвестных на текущем шаге       
	// 	  vector <long double> currentVariableValues (size);

	// 	  // Посчитаем значения неизвестных на текущей итерации
	// 	  // в соответствии с теоретическими формулами
	// 	  for (int i = 0; i < size; ++i)
	// 	  {
	// 		  // Инициализируем i-ую неизвестную значением 
	// 		  // свободного члена i-ой строки матрицы
	// 		  currentVariableValues.at(i)  = matrix.at(i).at(size);

	// 		  // Вычитаем сумму по всем отличным от i-ой неизвестным
	// 		  for (int j = 0; j < size; ++j)
	// 		  {
	// 			  // При j < i можем использовать уже посчитанные
	// 			  // на этой итерации значения неизвестных
	// 			  if (j < i)
	// 			  {
	// 				  currentVariableValues.at(i) -= matrix.at(i).at(j) * currentVariableValues.at(j) ;
	// 			  }

	// 			  // При j > i используем значения с прошлой итерации
	// 			  if (j > i)
	// 			  {
	// 				  currentVariableValues.at(i)  -= matrix.at(i).at(j) * previousVariableValues.at(j) ;
	// 			  }
	// 		  }

	// 		  // Делим на коэффициент при i-ой неизвестной
	// 		  currentVariableValues.at(i)  /= matrix.at(i).at(i);
	// 	  }

	// 	  // Посчитаем текущую погрешность относительно предыдущей итерации
	// 	  long double error = 0.0;
		  
	// 	  for (int i = 0; i < size; ++i)
	// 	  {
	// 		  error += abs (currentVariableValues.at(i) - previousVariableValues.at(i) );
	// 	  }

	// 	  // Если необходимая точность достигнута, то завершаем процесс
	// 	  if (error < eps)
	// 	  {
	// 		  break;
	// 	  }

	// 	  // Переходим к следующей итерации, так 
	// 	  // что текущие значения неизвестных 
	// 	  // становятся значениями на предыдущей итерации
	// 	  previousVariableValues = currentVariableValues;
	//   }
	//   // Выводим найденные значения неизвестных с 8 знаками точности
 //    for (int i = 0; i < size; ++i)
 //    {
 //        cout << previousVariableValues.at(i)  << endl;
 //    }


}