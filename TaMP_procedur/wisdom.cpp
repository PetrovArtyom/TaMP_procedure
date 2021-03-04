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
		wisdom* wd;
		int k;
		ifst >> k;
		char tmp;
		ifst.get(tmp);
		switch (k) {
		case 1:
			wd = new wisdom;
			wd->k = wisdom::key::PROVERB;
			ifst.getline(wd->content, 200);
			In(wd->pr, ifst);
			return wd;
		case 2:
			wd = new wisdom;
			wd->k = wisdom::key::APHORISM;
			ifst.getline(wd->content, 200);
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
		switch (wd.k)
		{
		case wisdom::key::PROVERB:
			ofst << "Пословица: " << wd.content << endl;
			Out(wd.pr, ofst);
			break;
		case wisdom::key::APHORISM:
			ofst << "Афоризм: " << wd.content << endl;
			Out(wd.pr, ofst);
			break;
		default:
			ofst << "Некорректная фраза!" << endl;
		}
	}

	// Фильтрованный вывод параметров текущей мудрости в поток
	void Out_proverb(wisdom& wd, ofstream& ofst)
	{
		switch (wd.k)
		{
		case wisdom::key::PROVERB:
			ofst << "Пословица: " << wd.content << endl;
			Out(wd.pr, ofst);
			break;
		case wisdom::key::APHORISM:
			break;
		default:
			ofst << "Некорректная фраза!" << endl;
		}
	}
}