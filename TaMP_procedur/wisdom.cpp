#include <fstream>
#include "wisdom_atd.h"
using namespace std;
namespace simple_wisdom 
{
	// Сигнатуры требуемых внешних функций
	void In(proverb& pr, ifstream& ist);
	void In(aphorism& aph, ifstream& ist);

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

		switch (k) {
		case 1:
			wd->k = wisdom::key::PROVERB;
			In(wd->pr, ifst);
			return wd;
		case 2:
			wd->k = wisdom::key::APHORISM;
			In(wd->aph, ifst);
			return wd;
		default:
			return 0;
		}
	}

	// Сигнатуры требуемых внешних функций.
	void Out(proverb& pr, ofstream& ofst);
	void Out(aphorism& aph, ofstream& ofst);

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
		default:
			ofst << "Некорректная фраза!" << endl;
		}

		// Вывод общих параметров
		ofst << wd.content << endl << "Оценка: " << wd.mark << endl << endl;
	}
}