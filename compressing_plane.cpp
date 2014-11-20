#include "compressing_plane.h"

void CompressingPlane::F_fun(FILE * sss)
{
	// char s;
	// while()
	// {
	// 	int fff = 0;
	// 	sss >> fff;
	// 	F.push_back(fff);
	// 	sss.get(s);
	// }
}
CompressingPlane::CompressingPlane()
{
	//fstream settings("settings.txt", ios_base::in);
	/*freopen("settings.txt","r",stdin);
	char s;
	while( !cin.get(s).eof() )
	{
		switch(s)
		{
			case '#':// Указатель на Дату 
			{
				char * strings = new char[500];
				cin.getline(strings,500,'\n');
				cout<< strings << endl;
				break;
			}
			case 'F':// граница (F1-левая,F2-верхняя,F3-правая,F4-нижняя)
			{
				list<double>::iterator i;
				while(  '\n' )
				{

				}
				for (i = F.begin(); i != F.end(); ++i)
				{
					cout << "F="<< *i << '\n'; 
				}
				break;
			}
			// 	case 'V':// Внутренние узлы 
			// 	{
			// 		break;
			// 	}
			// 	case 'N':// количество узлов
			// 	{
			// 		settings >> N;
			// 		break;
			// 	}
			// 	case 'H':// шаг сетки 
			// 	{
			// 		settings.getline(strings,500, '\n');
			// 		H = atof(strings);
			// 		cout << H << endl;
			// 		break;
			// 	}
			// 	case 'G':// Коэффициент Лама
			// 	{
			// 		settings.getline(strings,500, '\n');
			// 		cout<< strings << endl;
			// 		break;
			// 	}
			// 	case 'E':// модуль упругости(Юнга) 
			// 	{
			// 		settings.getline(strings,500,'\n');
			// 		E = atoi(strings);
			// 		cout << E << endl;
			// 		break;
			// 	}
			// 	case 'M':// Коэффициент Пуассона
			// 	{
			// 		settings.getline(strings,500,'\n');
			// 		M = atof(strings);
			// 		cout << M << endl;
			// 		break;
			// 	}
			// 	case 'P':// Поверхностная сила((P1-левая,P2-верхняя,P3-правая,P4-нижняя)
			// 	{
			// 		// settings.getline(strings,100,'\n');
			// 		// cout<< strings << endl;
			// 		power Element_P;
			// 		settings.get(s);
			// 		while(s != '\n')
			// 		{
			// 			Element_P.side = s;
			// 			cout << Element_P.side;
			// 		}
			// 		break;
			// 	}
			// 	case 'f':// Объемная сила
			// 	{
			// 		settings.getline(strings,500,'\n');
			// 		cout<< strings << endl;
			// 		break;
			// 	}
			// 	default:
			// 	{
			// 		settings.getline(strings,100,'\n');
			// 		break;
			// 	}
			// }
		}
		

		//cout << strings;
	}*/

		//Начальные настройки для задачи
		M = 0.3;
		E = 1000000000;
		H = 0.05;
		F.push_back(2);
		F.push_back(3);
		N = 21;
		f = 0;
		P.push_back(100.0);
		P.push_back(-100.0);
}
CompressingPlane::~CompressingPlane()
{

}

void CompressingPlane::MultiplicationByConstant( map< char ,list< map<int,double> > >& T )// Домножение на числа
{
	for (map< char ,list< map<int,double> > >::iterator i = T.begin(); i != T.end(); ++i)
	{
		int k = 0;
		for (list< map<int,double> >::iterator j = (*i).second.begin(); j != (*i).second.end(); ++j)
		{
			map<int,double> ::iterator b;
			switch(k)
			{
				case 0:
				{
					for ( b = (*j).begin(); b != (*j).end(); ++b)
						(*b).second *=E/(1-M*M);
					break;
				};
				case 1:
				{
					for ( b = (*j).begin(); b != (*j).end(); ++b)
						(*b).second *=E*M/(1-M*M);
					break;
				};
				case 2:
				{
					for ( b = (*j).begin(); b != (*j).end(); ++b)
						(*b).second *=G/2.0;
					break;
				};
				case 3:
				{
					for ( b = (*j).begin(); b != (*j).end(); ++b)
						(*b).second *=G/2.0;
					break;
				};
			}
			k++;
		}
	}
}
