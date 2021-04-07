#include <fstream>
#include <iostream>
#include "proverb_atd.h"

using namespace std;
namespace simple_wisdom 
{
	// ���� ���������� ��������� �� ������
	int In(proverb& pr, ifstream& ifst)
	{
		// ������ ������
		ifst.getline(pr.country, 50);
		
		// �������� ������ �� ���������
		if (pr.country[0] == '\0')
		{
			cout << endl << "Error! Field country is empty. Please check input file." << endl;
			return 1;
		}
		return 0;
	}

	// ����� ���������� ��������� � �����
	void Out(proverb& pr, ofstream& ofst)
	{
		ofst << "������: " << pr.country << endl << "���������: ";
	}
}