#include <fstream>
#include "wisdom_atd.h"
using namespace std;
namespace simple_wisdom 
{
	// ��������� ��������� ������� �������
	void In(proverb& pr, ifstream& ist);
	void In(aphorism& aph, ifstream& ist);

	// ���� ���������� ���������� ����� �� �����
	wisdom* In(ifstream& ifst)
	{
		wisdom* wd;
		int k;
		ifst >> k;
		char tmp;
		ifst.get(tmp);
		switch (k) {
		case 1:
			wd = new wisdom;
			wd->k = wisdom::key::PROVERB;
			ifst.getline(wd->content, 200);
			wd->mark = rand() % 10;
			In(wd->pr, ifst);
			return wd;
		case 2:
			wd = new wisdom;
			wd->k = wisdom::key::APHORISM;
			ifst.getline(wd->content, 200);
			wd->mark = rand() % 10;
			In(wd->aph, ifst);
			return wd;
		default:
			return 0;
		}
	}

	// ��������� ��������� ������� �������.
	void Out(proverb& pr, ofstream& ofst);
	void Out(aphorism& aph, ofstream& ofst);

	// ����� ���������� ������� �������� � �����
	void Out(wisdom& wd, ofstream& ofst)
	{
		switch (wd.k)
		{
		case wisdom::key::PROVERB:
			ofst << "���������: " << wd.content << endl;
			Out(wd.pr, ofst);
			ofst << "������: " << wd.mark << endl << endl;
			break;
		case wisdom::key::APHORISM:
			ofst << "�������: " << wd.content << endl;
			Out(wd.aph, ofst);
			ofst << "������: " << wd.mark << endl << endl;
			break;
		default:
			ofst << "������������ �����!" << endl;
		}
	}
}