#include <fstream>
#include "wisdom_atd.h"
using namespace std;
namespace simple_wisdom 
{
	// Сигнатуры требуемых внешних функций
	void In(proverb& pr, ifstream& ist);
	void In(aphorism& aph, ifstream& ist);
	void In(riddle& rd, ifstream& ist);

	// Ввод параметров обобщенной фразы из файла
	wisdom* In(ifstream& ifst)
	{
		// Считывание вида мудрости
		int k;
		ifst >> k;
		char tmp;
		ifst.get(tmp);

		// Ввод общих параметров 
		wisdom* wd = new wisdom;
		ifst.getline(wd->content, 200);
		int k2;
		ifst >> k2;
		ifst.get(tmp);
		wd->mark = k2;

		switch (k) 
		{
		case 1:
			wd->k = wisdom::key::PROVERB;
			In(wd->pr, ifst);
			return wd;
		case 2:
			wd->k = wisdom::key::APHORISM;
			In(wd->aph, ifst);
			return wd;
		case 3:
			wd->k = wisdom::key::RIDDLE;
			In(wd->rd, ifst);
			return wd;
		default:
			return 0;
		}
	}

	int marks_number(wisdom w)         //   Вычисление количества знаков препинания
	{
		int marks_num = 0;
		char marks[] = { '.', ',', '!', '?', '-', ';', ':' };
		int marks_len = 7;

		for (int i = 0; i < strlen(w.content); i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (w.content[i] == marks[j])
				{
					marks_num++;
				}
			}
		}

		return marks_num;
	}

	// Сигнатуры требуемых внешних функций.
	void Out(proverb& pr, ofstream& ofst);
	void Out(aphorism& aph, ofstream& ofst);
	void Out(riddle& rd, ofstream& ofst);

	// Вывод параметров текущей мудрости в поток
	void Out(wisdom& wd, ofstream& ofst)
	{
		int marks_num = marks_number(wd);

		// Вывод индивидуальных параметров
		switch (wd.k)
		{
		case wisdom::key::PROVERB:
			Out(wd.pr, ofst);
			break;
		case wisdom::key::APHORISM:
			Out(wd.aph, ofst);
			break;
		case wisdom::key::RIDDLE:
			Out(wd.rd, ofst);
			break;
		default:
			ofst << "Некорректная фраза!" << endl;
		}

		// Вывод общих параметров
		ofst << wd.content << endl << "Оценка: " << wd.mark << endl;
		ofst << "Знаков препинания: " << marks_num << endl << endl;
	}
}