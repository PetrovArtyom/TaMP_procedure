#include <fstream>
#include "riddle_atd.h"
using namespace std;
namespace simple_wisdom {
	// ���� ���������� ������� �� �����
	void In(riddle& rd, ifstream& ifst)
	{
		ifst.getline(rd.answer, 50);
	}

	// ����� ���������� ��������� � �����
	void Out(riddle& rd, ofstream& ofst)
	{
		ofst << "�����: " << rd.answer << endl << "�������: ";
	}
}