#include <fstream>
#include "proverb_atd.h"
using namespace std;
namespace simple_wisdom 
{
	// Ввод параметров пословицы из файла
	void In(proverb& pr, ifstream& ifst)
	{
		ifst.getline(pr.country, 50);
	}

	// Вывод параметров пословицы в поток
	void Out(proverb& pr, ofstream& ofst)
	{
		ofst << "Страна: " << pr.country << endl << "Пословица: ";
	}
}