#include <fstream>
#include <iostream>
#include "aphorism_atd.h"

using namespace std;
namespace simple_wisdom 
{
	// Ввод строк афоризма из потока
	int In(aphorism& aph, ifstream& ifst)
	{
		// Чтение строки
		ifst.getline(aph.author, 50);
		
		// Проверка строки на непустоту
		if (aph.author[0] == '\0')
		{
			cout << endl << "Error! Field author is empty. Please check input file." << endl;
			return 1;
		}
		return 0;
	}

	// Вывод строк афоризма в поток
	void Out(aphorism& aph, ofstream& ofst)
	{
		ofst << "Автор: " << aph.author << endl << "Афоризм: ";
	}
}