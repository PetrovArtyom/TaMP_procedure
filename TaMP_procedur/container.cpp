#include "container_atd.h"
#include "wisdom_atd.h"
#include <fstream>
#include <iostream>

using namespace std;
namespace simple_wisdom 
{
	// Сигнатуры требуемых внешних функций
	wisdom* In(ifstream& ifdt);
	void Out(wisdom& wd, ofstream& ofst);
	void Out_proverb(wisdom& wd, ofstream& ofst);
	bool Compare(wisdom a, wisdom b);

	// Инициализация контейнера
	void Init(container& c)
	{
		c.len = 0;
	}

	// Очистка контейнера от элементов (освобождение памяти)
	void Clear(container& c)
	{
		for (int i = 0; i < c.len; i++)
		{
			delete c.cont[i];
		}
		c.len = 0;
	}

	// Ввод содержимого контейнера из указанного потока
	int In(container& c, ifstream& ifst)
	{
		// Чтение пока не конец файла
		while (!ifst.eof())
		{
			// Проверка на непереполнение массива элементов
			if (c.len < c.max_len)
			{
				// Проверка на успешный ввод
				if ((c.cont[c.len] = In(ifst)) != 0)
				{
					c.len++;
				}
				else
				{
					return 1;
				}
			}
			else
			{
				cout << "Массив переполнен. Считано " << c.max_len << " элементов." << endl;
				ifst.close();
				break;
			}
		}
		return 0;
	}	

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

	// Фильтрованный вывод содержимого контейнера в указанный поток
	void Out_proverb(container& c, ofstream& ofst)
	{
		ofst << "Количество элементов в контейнере: " << c.len << endl << endl;
		cout << "Количество элементов в контейнере: " << c.len << endl << endl;
		
		for (int i = 0; i < c.len; i++)
		{
			Out_proverb(*(c.cont[i]), ofst);
		}
	}

	// Сортировка пузырьком
	void Sort(container& c)                          
	{
		for (int i = 0; i < c.len - 1; i++)
		{
			for (int j = i + 1; j < c.len; j++)
			{
				if(Compare(*(c.cont[i]), *(c.cont[j])))
				{
					wisdom* tmp = c.cont[i];
					c.cont[i] = c.cont[j];
					c.cont[j] = tmp;
					tmp = NULL;
				}
			}
		}
	}
}
