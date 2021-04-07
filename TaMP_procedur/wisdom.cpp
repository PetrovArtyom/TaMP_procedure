#include <fstream>
#include <iostream>
#include "wisdom_atd.h"

using namespace std;
namespace simple_wisdom 
{
	// Сигнатуры требуемых внешних функций
	int In(proverb& pr, ifstream& ist);
	int In(aphorism& aph, ifstream& ist);
	int In(riddle& rd, ifstream& ist);
	void Out(proverb& pr, ofstream& ofst);
	void Out(aphorism& aph, ofstream& ofst);
	void Out(riddle& rd, ofstream& ofst);

	// Ввод параметров обобщенной мудрости из потока
	wisdom* In(ifstream& ifst)
	{
		// Считывание типа мудрости
		char k;
		ifst >> k;

		// Проверка символа на принадлежность к цифрам
		if ((int)k > 57 || (int)k < 48)			
		{
			cout << endl << "Error! Not a number entered in an integer field. Please check input file." << endl;
			return 0;
		}

		// Конвертирование char в int
		int wd_type = (int)k - 48;

		// Считывание оставшегося символа \n
		char tmp;
		ifst.get(tmp);

		// Ввод первого общего параметра мудрости - содержания
		wisdom* wd = new wisdom;
		ifst.getline(wd->content, 200);

		//Проверка непустоты строки
		if (wd->content[0] == '\0')
		{
			cout << endl << "Error! Field content is empty. Please check input file." << endl;
			return 0;
		}

		// Ввод второго общего параметра мудрости - оценки
		char str[4];
		ifst.getline(str, 4);

		// Проверка того, что оценка является числом
		int count = 0;
		while (str[count] != '\n' && str[count] != '\0' && count < 4)
		{
			if ((int)str[count] > 57 || (int)str[count] < 48)
			{
				cout << endl << "Error! Not a number entered in an integer field. Please check input file." << endl;
				return 0;
			}
			count++;
		}

		// Проверка на невведение второго общего параметра - оценки
		if (count == 0)
		{
			cout << endl << "Error! Field mark is empty. Please check input file." << endl;
			return 0;
		}

		// Конвертация строки в число 
		int mark = atoi(str);

		// Запись проверенной оценки в соответствующее поле объекта
		wd->mark = mark;

		// Создание объекта соответствующего типа
		switch (wd_type) 
		{
		case 1:
			wd->k = wisdom::key::PROVERB;
			
			// Проверка успешности ввода индивидуального параметра
			if (In(wd->pr, ifst) == 1)
			{
				return 0;
			}
			return wd;
		case 2:
			wd->k = wisdom::key::APHORISM;
			
			// Проверка успешности ввода индивидуального параметра
			if (In(wd->aph, ifst) == 1)
			{
				return 0;
			}
			return wd;
		case 3:
			wd->k = wisdom::key::RIDDLE;
			
			// Проверка успешности ввода индивидуального параметра
			if (In(wd->rd, ifst) == 1)
			{
				return 0;
			}
			return wd;
		default:
			return 0;
		}
	}

	//   Вычисление количества знаков препинания
	int Marks_number(wisdom w)         
	{
		// Число знаков препинания
		int marks_num = 0;
		
		// Учитываемые знаки
		char marks[] = { '.', ',', '!', '?', '-', ';', ':' };
	
		// Длина массива учитываемых знаков
		int marks_len = 7;

		// Цикл подсчёта
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

	// Вывод параметров текущей мудрости в поток
	void Out(wisdom& wd, ofstream& ofst)
	{
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
		ofst << "Знаков препинания: " << Marks_number(wd) << endl << endl;
	}

	// Фильтрованный вывод параметров текущей мудрости в поток
	void Out_proverb(wisdom& wd, ofstream& ofst)
	{
		// Вывод индивидуальных параметров
		switch (wd.k)
		{
		case wisdom::key::PROVERB:
			Out(wd.pr, ofst);
			break;
		case wisdom::key::APHORISM:
			break;
		case wisdom::key::RIDDLE:
			break;
		default:
			ofst << "Некорректная фраза!" << endl;
		}

		// Вывод общих параметров
		if (wd.k == wisdom::key::PROVERB)
		{
			ofst << wd.content << endl << "Оценка: " << wd.mark << endl;
			ofst << "Знаков препинания: " << Marks_number(wd) << endl << endl;
		}
	}

	// Сравнение полей "оценка" двух объектов
	bool Compare(wisdom a, wisdom b)
	{
		return Marks_number(a) > Marks_number(b);
	}
}