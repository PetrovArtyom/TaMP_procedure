#include <fstream>
#include "aphorism_atd.h"
using namespace std;
namespace simple_wisdom {
	// ���� ����� �������� �� ������
	void In(aphorism& aph, ifstream& ifst)
	{
		ifst.getline(aph.author, 50);
	}

	// ����� ����� �������� � �����
	void Out(aphorism& aph, ofstream& ofst)
	{
		ofst << "�����: " << aph.author << endl;
	}
}