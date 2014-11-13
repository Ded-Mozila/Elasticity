#include "compressing_plane.h"

void CompressingPlane::F_fun(fstream& settings)
{
	char s;
	settings.get(s);
	while(s != '\n')
		{
			int fff = 0;
			settings >> fff;
			F.push_back(fff);
			settings.get(s);
		}
}
CompressingPlane::CompressingPlane()
{
	fstream settings("settings.txt", ios_base::in);
	if (!settings)
	{
		perror("Error open file settings!");
		exit(EXIT_FAILURE);
	}else
	{
		char * strings = new char[500];
		char s;
		while(!settings.get(s).eof())
		{
			switch(s)
			{
				case '#':// Указатель на Дату 
				{
					settings.getline(strings,500,'\n');
					cout<< strings << endl;
					break;
				}
				case 'F':// граница (F1-левая,F2-верхняя,F3-правая,F4-нижняя)
				{
					F_fun(settings);
					list<double>::iterator i;
					for (i = F.begin(); i != F.end(); ++i)
					{
						cout << "F="<< *i << '\n'; 
					}
					break;
				}
				case 'V':// Внутренние узлы 
				{
					break;
				}
				case 'N':// количество узлов
				{
					settings >> N;
					break;
				}
				case 'H':// шаг сетки 
				{
					settings.getline(strings,500, '\n');
					H = atof(strings);
					cout << H << endl;
					break;
				}
				case 'G':// Коэффициент Лама
				{
					settings.getline(strings,500, '\n');
					cout<< strings << endl;
					break;
				}
				case 'E':// модуль упругости(Юнга) 
				{
					settings.getline(strings,500,'\n');
					E = atoi(strings);
					cout << E << endl;
					break;
				}
				case 'M':// Коэффициент Пуассона
				{
					settings.getline(strings,500,'\n');
					M = atof(strings);
					cout << M << endl;
					break;
				}
				case 'P':// Поверхностная сила((P1-левая,P2-верхняя,P3-правая,P4-нижняя)
				{
					// settings.getline(strings,100,'\n');
					// cout<< strings << endl;
					power Element_P;
					settings.get(s);
					while(s != '\n')
					{
						Element_P.side = s;
						cout << Element_P.side;
					}
					break;
				}
				case 'f':// Объемная сила
				{
					settings.getline(strings,500,'\n');
					cout<< strings << endl;
					break;
				}
				default:
				{
					settings.getline(strings,100,'\n');
					break;
				}
			}
		}
		delete []strings;

		cout << strings;
	}
}
CompressingPlane::~CompressingPlane()
{}