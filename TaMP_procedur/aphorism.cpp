#include <fstream>
#include <iostream>
#include "aphorism_atd.h"

using namespace std;
namespace simple_wisdom 
{
	// ���� ����� �������� �� ������
	int In(aphorism& aph, ifstream& ifst)
	{
		// ������ ������
		ifst.getline(aph.author, 50);
		
		// �������� ������ �� ���������
		if (aph.author[0] == '\0')
		{
			cout << endl << "Error! Field author is empty. Please check input file." << endl;
			return 1;
		}
		return 0;
	}

	// ����� ����� �������� � �����
	void Out(aphorism& aph, ofstream& ofst)
	{
		ofst << "�����: " << aph.author << endl << "�������: ";
	}
}