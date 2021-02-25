#include "container_atd.h"
#include "wisdom_atd.h"
#include <fstream>
#include <iostream>

using namespace std;
namespace simple_wisdom {
	// Инициализация контейнера
	void Init(container& c)
	{
		c.len = 0;
	}
	// Очистка контейнера от элементов
	// (освобождение памяти)
	void Clear(container& c)
	{
		for (int i = 0; i < c.len; i++)
		{
			delete c.cont[i];
		}
		c.len = 0;
	}

	// Сигнатуры требуемых внешних функций
	wisdom* In(ifstream& ifdt);
	// Ввод содержимого контейнера из указанного потока
	void In(container& c, ifstream& ifst)
	{
		while (!ifst.eof())
		{
			if (c.len < c.max_len)
			{
				if ((c.cont[c.len] = In(ifst)) != 0)
				{
					c.len++;
				}
			}
			else
			{
				cout << "Массив переполнен. Считано " << c.max_len << " элементов." << endl;
				ifst.close();
			}
		}
	}

	// Сигнатуры требуемых внешних функций
	void Out(wisdom& wd, ofstream& ofst);
	// Вывод содержимого контейнера в указанный поток
	void Out(container& c, ofstream& ofst)
	{
		ofst << "Количество элементов в контейнере: " << c.len << endl << endl;
		cout << "Количество элементов в контейнере: " << c.len << endl << endl;
		for (int i = 0; i < c.len; i++)
		{
			Out(*(c.cont[i]), ofst);
		}
	}
}
