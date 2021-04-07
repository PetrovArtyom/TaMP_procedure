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
			ofst << i + 1 << ": ";
			Out(*(c.cont[i]), ofst);
		}
	}

	void Write_pairs(container& c, ofstream& ofst)
	{
		ofst << endl << "MultiMethod" << endl << endl;

		for (int i = 0; i < c.len - 1; i++)
		{
			if (c.cont[i]->k == wisdom::key::PROVERB && c.cont[i + 1]->k == wisdom::key::PROVERB)
			{
				Out(*(c.cont[i]), ofst);
				ofst << endl;
				Out(*(c.cont[i + 1]), ofst);
				ofst << endl;
				ofst << "Пословица и Пословица" << endl << endl;
			}

			if (c.cont[i]->k == wisdom::key::PROVERB && c.cont[i + 1]->k == wisdom::key::APHORISM)
			{
				Out(*(c.cont[i]), ofst);
				ofst << endl;
				Out(*(c.cont[i + 1]), ofst);
				ofst << endl;
				ofst << "Пословица и Афоризм" << endl << endl;
			}

			if (c.cont[i]->k == wisdom::key::PROVERB && c.cont[i + 1]->k == wisdom::key::RIDDLE)
			{
				Out(*(c.cont[i]), ofst);
				ofst << endl;
				Out(*(c.cont[i + 1]), ofst);
				ofst << endl;
				ofst << "Пословица и Загадка" << endl << endl;
			}

			if (c.cont[i]->k == wisdom::key::APHORISM && c.cont[i + 1]->k == wisdom::key::APHORISM)
			{
				Out(*(c.cont[i]), ofst);
				ofst << endl;
				Out(*(c.cont[i + 1]), ofst);
				ofst << endl;
				ofst << "Афоризм и Афоризм" << endl << endl;
			}

			if (c.cont[i]->k == wisdom::key::APHORISM && c.cont[i + 1]->k == wisdom::key::PROVERB)
			{
				Out(*(c.cont[i]), ofst);
				ofst << endl;
				Out(*(c.cont[i + 1]), ofst);
				ofst << endl;
				ofst << "Афоризм и Пословица" << endl << endl;
			}

			if (c.cont[i]->k == wisdom::key::APHORISM && c.cont[i + 1]->k == wisdom::key::RIDDLE)
			{
				Out(*(c.cont[i]), ofst);
				ofst << endl;
				Out(*(c.cont[i + 1]), ofst);
				ofst << endl;
				ofst << "Афоризм и Загадка" << endl << endl;
			}

			if (c.cont[i]->k == wisdom::key::RIDDLE && c.cont[i + 1]->k == wisdom::key::RIDDLE)
			{
				Out(*(c.cont[i]), ofst);
				ofst << endl;
				Out(*(c.cont[i + 1]), ofst);
				ofst << endl;
				ofst << "Загадка и Загадка" << endl << endl;
			}

			if (c.cont[i]->k == wisdom::key::RIDDLE && c.cont[i + 1]->k == wisdom::key::PROVERB)
			{
				Out(*(c.cont[i]), ofst);
				ofst << endl;
				Out(*(c.cont[i + 1]), ofst);
				ofst << endl;
				ofst << "Загадка и Пословица" << endl << endl;
			}

			if (c.cont[i]->k == wisdom::key::RIDDLE && c.cont[i + 1]->k == wisdom::key::APHORISM)
			{
				Out(*(c.cont[i]), ofst);
				ofst << endl;
				Out(*(c.cont[i + 1]), ofst);
				ofst << endl;
				ofst << "Загадка и Афоризм" << endl << endl;
			}
		}
	}
}
