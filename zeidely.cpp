#include "zeidely.h"
#include "write.h"
 Zeidely::Zeidely()
{
}
 Zeidely::~Zeidely()
{
}

bool converge(vector<double> curr, vector<double> next, double eps, int N, int count )
{
    double norm = 0.0;
    for( int i = 0; i < N; i++ ) 
      norm += pow( fabs( curr[i] - next[i] ), 2 );
    
    cout << "      " << count << " - " << sqrt( norm ) << endl;
    if( sqrt( norm ) >= eps )
      return false;
    return true;
}
vector<double>  Zeidely::Iterat1(vector<vector<double> > A, vector<double> B, int N, double eps, double alfa, int n, double h)
{
	vector<double> next(B.size(),0);
	vector<double> curr(B);
	int count = 1;
	std::vector<int> node; // Граничные узлы
	double f = alfa; //коефициент трения
	map<int,double> g;// Сила трения
	map<int,double> g2;// Сила трения
	int ttttt;
	//alfa = 900000;
	while( true )
	{   
		int z2 = 0;
		int sum2 = z2;
		int z = 0;
		int sum = z;
	    for( int i = 0; i < N; i++ )
	    {        
	        bool a = true;
	        for( int j = 0; j < N; j++ )
	            if( A[i][j] != 0 ) 
	            	{
	            		a = false;
	            		break;
	            	}
	        if( a )
	        {
	            next[i] = 0;
	            continue;
	        }    
	        double var = 0.0;
	        for( int j = 0; j < i; j++ )
	        {
	            var += ( A[i][j] * next[j]  );
	        }
	        for( int j = i + 1; j < N; j++ )
	        {
	            var += ( A[i][j] * curr[j] );
	        }
        	next[i] = (-1)*( var -B[i]  ) / A[i][i];

			if( N/2+sum == i && z < n ) //Трение
			{
				sum += n*2-1-z;
				if (count ==1)
				{
					g[sum] = 0;
				}
				alfa = g[sum];
				//cout << next[i] << endl;
				if ( next[i] > 0 && ( var - B[i] ) < (-1)*alfa)
					next[i] = (( var - B[i] )+alfa)*(-1)/A[i][i];
				else if ( next[i] < 0 && ( var - B[i]) > alfa)
					next[i] = (alfa - ( var - B[i]))/A[i][i];
				g[sum]=f*fabs(var - B[i]);				
				z+=1;
			}
			if( sum2 == i && z2 < n)// Сеньерини
        	{
        		if (count == 1)
        		{
        			node.push_back(i);
        		}
        		if (next[i]> 0)
        		{
        			next[i]=0;
        		}
        		sum2 += n*2-1-z2;
        		z2+=1;
        	}

	    }
	    //проверка
	    if( converge( curr, next, eps, N, count ) ) break;
	    for( int i = 0; i < N; i++ )
	        curr[i] = next[i];
	    count++;
	}   
	  for (int i = 0; i < node.size(); ++i)
	    {
	    	g[node[i]] = curr[N/2+node[i]] *f;
	    }
	    count =1;

	return next; 
}
vector<double> Zeidely::Iterat2(vector<vector<double> > A, vector<double> B, int N, double eps,double alfa)
{
	vector<double> x(B);
	vector<double> xn(B);
	vector<vector<double> >::iterator ii;
	vector<double>::iterator ij;
	double w=1 ,norma , error_old;
	int i,j;
	int k = 0;

	do
	{  
		k++;
		norma=0;

		for(i=0;i<A.size();++i)
		{
			x[i]=0;
			for(j=0;j<A[i].size();++j)
			{
				if(i!=j)
				x[i]+=A[i][j]*x[j];
			}
			x[i]=(B[i]-x[i] )/A[i][i];
			
		 //x[i]=w*x[i]+(1-w)*xn[i];				   
			if(fabs(x[i]-xn[i]) > norma)
			  norma=fabs(x[i]-xn[i]);
			 xn[i]=x[i];
		}
		if (k > 2)
		{
			if (error_old == norma)
			{
				break;
			}
			else
			{
				error_old = norma;
			}
		}
cout<<"Кол-во итераций: "<<k<<" " << norma << " " << eps<< " \n";
	}
	 while(norma > eps);
	 cout<<"Кол-во итераций: ";cout<<k<<" \n";
	//  freopen("outtext.txt","w+",stdout);
	//  for(i=0;i<x.size();++i)
	// 	 cout<<x[i]<<"\n";
	// fclose(stdout);
	
	return x;
}
void Zeidely::Iterat(vector<vector<double> > A, vector<double> B, int N, double eps)
{
	////////////////////////////также расходится////////////////////
	int size =A.size();
	int k = 0 ;
	//версия 2.0 --- бежит в +++ 

	// double error_old=0.0;

	// int iterator = 0;

	// vector <long double> previousVariableValues (size, 0.0);
	// vector <long double> currentVariableValues (size);

	// long double error = 0.0;

	// do {
	// 	iterator++;
	// 	error = 0;

		
	// 	for (int i = 0; i < size; i++)
	// 	{
	// 		currentVariableValues[i] = B[i];

	// 		for (int j = 0; j < size; j++)
	// 		{
	// 			if (i != j)
	// 			{
	// 				currentVariableValues[i] -= A[i][j] * previousVariableValues[j];
	// 			}
	// 		}

	// 		currentVariableValues[i] /= A[i][i];
	// 	}

	// 	// if (iterator != 1) {
	// 	// 	cout << "\nПогрешность вычисления: \n";
	// 	// }

	// 	for (int i = 0; i < size; i++)
	// 	{

	// 		error = fabs(currentVariableValues[i] - previousVariableValues[i]) > error ? fabs(currentVariableValues[i] - previousVariableValues[i]):error;

	// 		// if (iterator != 1) {
	// 		// 	cout << setw(8) << setprecision(6) << fixed << error << endl;
	// 		// }
	// 	}

	// 	previousVariableValues = currentVariableValues;
	// 	cout << "Итерация номер " << iterator << " " <<error << " " << eps << endl;
	// 	//printMatrix("Текущие значения", previousVariableValues, size);

	// } while (error >= eps );

























	vector <double> previousVariableValues (B.size(), 0.0);
	double error_old=0;
	while (true)
    {
    	cout << ++k << " ";
        // Введем вектор значений неизвестных на текущем шаге       
        vector <double> currentVariableValues (B.size());

        // Посчитаем значения неизвестных на текущей итерации
        // в соответствии с теоретическими формулами
        for (int i = 0; i < A.size(); ++i)
        {
            // Инициализируем i-ую неизвестную значением 
            // свободного члена i-ой строки матрицы
        	 currentVariableValues[i]  = B[i];
            // Вычитаем сумму по всем отличным от i-ой неизвестным
            for (int j = 0; j < A[i].size(); ++j)
            {
                // При j < i можем использовать уже посчитанные
                // на этой итерации значения неизвестных
                if (j < i)
                {
                    currentVariableValues[i] -= A[i][j] * currentVariableValues[j];
                	//cout<<currentVariableValues[i] <<endl;
                }

                // При j > i используем значения с прошлой итерации
                if (j > i)
                {

                    currentVariableValues[i] -= A[i][j] * previousVariableValues[j];
                	//cout<<currentVariableValues[i] << endl;
                }
            }

            // Делим на коэффициент при i-ой неизвестной
            currentVariableValues[i] /= A[i][i];
        }

        // Посчитаем текущую погрешность относительно предыдущей итерации
        double error = 0.0;
        cout <<k << endl;
        for (int i = 0; i < size; ++i)
        {
        	//cout << (currentVariableValues[i] - previousVariableValues[i]) <<endl;
            error += fabs (currentVariableValues[i] - previousVariableValues[i]);
           // cin >> k;

        }

         //cout << error << " < "  << eps  << endl;
        // Если необходимая точность достигнута, то завершаем процесс
        if (error < eps)
        {
            break;
        }

        error_old = error;
        // Переходим к следующей итерации, так 
        // что текущие значения неизвестных 
        // становятся значениями на предыдущей итерации
        previousVariableValues = currentVariableValues;
    }
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