#include <fstream>
#include "riddle_atd.h"
using namespace std;
namespace simple_wisdom {
	// Ввод строк загадки из потока
	void In(riddle& rd, ifstream& ifst)
	{
		ifst.getline(rd.answer, 50);
	}

	// Вывод строк загадки в поток
	void Out(riddle& rd, ofstream& ofst)
	{
		ofst << "Ответ: " << rd.answer << endl;
	}
}