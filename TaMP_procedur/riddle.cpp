#include <fstream>
#include "riddle_atd.h"
using namespace std;
namespace simple_wisdom {
	// Ввод параметров загадки из файла
	void In(riddle& rd, ifstream& ifst)
	{
		ifst.getline(rd.answer, 50);
	}

	// Вывод параметров пословицы в поток
	void Out(riddle& rd, ofstream& ofst)
	{
		ofst << "Ответ: " << rd.answer << endl << "Загадка: ";
	}
}