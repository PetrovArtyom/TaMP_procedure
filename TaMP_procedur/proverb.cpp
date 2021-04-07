#include <fstream>
#include <iostream>
#include "proverb_atd.h"

using namespace std;
namespace simple_wisdom 
{
	// Ввод параметров пословицы из потока
	int In(proverb& pr, ifstream& ifst)
	{
		// Чтение строки
		ifst.getline(pr.country, 50);
		
		// Проверка строки на непустоту
		if (pr.country[0] == '\0')
		{
			cout << endl << "Error! Field country is empty. Please check input file." << endl;
			return 1;
		}
		return 0;
	}

	// Вывод параметров пословицы в поток
	void Out(proverb& pr, ofstream& ofst)
	{
		ofst << "Страна: " << pr.country << endl << "Пословица: ";
	}
}