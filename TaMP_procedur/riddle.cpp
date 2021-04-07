#include <fstream>
#include <iostream>
#include "riddle_atd.h"

using namespace std;
namespace simple_wisdom 
{
	// ���� ���������� ������� �� ������
	int In(riddle& rd, ifstream& ifst)
	{
		// ������ ������
		ifst.getline(rd.answer, 50);
		
		// �������� ������ �� ���������
		if (rd.answer[0] == '\0')
		{
			cout << endl << "Error! Field answer is empty. Please check input file." << endl;
			return 1;
		}
		return 0;
	}

	// ����� ���������� ������� � �����
	void Out(riddle& rd, ofstream& ofst)
	{
		ofst << "�����: " << rd.answer << endl << "�������: ";
	}
}