// TaMP_procedur.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <ctime>
#include <windows.h>
#include <iostream>
#include <fstream>
#include "container_atd.h"
using namespace std;
namespace simple_wisdom {
	// Сигнатуры требуемых внешних функций
	void Init(container& c);
	void Clear(container& c);
	void In(container& c, ifstream& ifst);
	void Out(container& c, ofstream& ofst);
	void Out_proverb(container& c, ofstream& ofst);
	void Sort(container& c);
}

using namespace simple_wisdom;
int main(int argc, char* argv[])
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");

	if (argc != 3) {
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	cout << "Начало выполнения программы" << endl;
	container c;
	Init(c);
	In(c, ifst);
	ofst << "Контейнер заполнен" << endl << endl;
	cout << "Контейнер заполнен" << endl << endl;
	Sort(c);
	ofst << "Контейнер отсортирован" << endl << endl;
	cout << "Контейнер отсортирован" << endl << endl;
	Out_proverb(c, ofst);
	Clear(c);
	ofst << "Контейнер пуст" << endl << endl;
	cout << "Контейнер пуст" << endl << endl;
	Out(c, ofst);
	cout << "Конец выполнения программы" << endl;
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
