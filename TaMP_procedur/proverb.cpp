#include <fstream>
#include "proverb_atd.h"
using namespace std;
namespace simple_wisdom 
{
	// ���� ���������� ��������� �� �����
	void In(proverb& pr, ifstream& ifst)
	{
		ifst.getline(pr.country, 50);
	}

	// ����� ���������� ��������� � �����
	void Out(proverb& pr, ofstream& ofst)
	{
		ofst << "������: " << pr.country << endl << "���������: ";
	}
}