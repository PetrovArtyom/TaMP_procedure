#include <fstream>
#include <iostream>
#include "riddle_atd.h"

using namespace std;
namespace simple_wisdom 
{
	// Ввод параметров загадки из потока
	int In(riddle& rd, ifstream& ifst)
	{
		// Чтение строки
		ifst.getline(rd.answer, 50);
		
		// Проверка строки на непустоту
		if (rd.answer[0] == '\0')
		{
			cout << endl << "Error! Field answer is empty. Please check input file." << endl;
			return 1;
		}
		return 0;
	}

	// Вывод параметров загадки в поток
	void Out(riddle& rd, ofstream& ofst)
	{
		ofst << "Ответ: " << rd.answer << endl << "Загадка: ";
	}
}