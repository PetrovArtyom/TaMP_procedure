#include <fstream>
#include <iostream>
#include "riddle_atd.h"
using namespace std;
namespace simple_wisdom 
{
	// Ввод параметров загадки из файла
	int In(riddle& rd, ifstream& ifst)
	{
		ifst.getline(rd.answer, 50);
		if (rd.answer[0] == '\0')
		{
			cout << endl << "Error! Incorrect input of wisdom type. Please check input file." << endl;
			return 1;
		}
		return 0;
	}

	// Вывод параметров пословицы в поток
	void Out(riddle& rd, ofstream& ofst)
	{
		ofst << "Ответ: " << rd.answer << endl << "Загадка: ";
	}
}