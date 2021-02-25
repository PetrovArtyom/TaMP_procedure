#include <fstream>
#include "aphorism_atd.h"
using namespace std;
namespace simple_wisdom {
	// Ввод строк афоризма из потока
	void In(aphorism& aph, ifstream& ifst)
	{
		ifst.getline(aph.author, 50);
	}

	// Вывод строк афоризма в поток
	void Out(aphorism& aph, ofstream& ofst)
	{
		ofst << "Автор: " << aph.author << endl;
	}
}