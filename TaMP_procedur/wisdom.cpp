#include <fstream>
#include "wisdom_atd.h"
using namespace std;
namespace simple_wisdom {
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
			In(wd->pr, ifst);
			return wd;
		case 2:
			wd = new wisdom;
			wd->k = wisdom::key::APHORISM;
			ifst.getline(wd->content, 200);
			In(wd->aph, ifst);
			return wd;
		default:
			return 0;
		}
	}

	int marks_number(wisdom w)         //   ���������� ���������� ������ ����������
	{
		int marks_num = 0;
		char marks[] = { '.', ',', '!', '?', '-', ';', ':' };
		int marks_len = 7;

		for (int i = 0; i < strlen(w.content); i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (w.content[i] == marks[j])
				{
					marks_num++;
				}
			}
		}

		return marks_num;
	}

	// ��������� ��������� ������� �������.
	void Out(proverb& pr, ofstream& ofst);
	void Out(aphorism& aph, ofstream& ofst);

	// ����� ���������� ������� �������� � �����
	void Out(wisdom& wd, ofstream& ofst)
	{
		int marks_num = marks_number(wd);

		switch (wd.k)
		{
		case wisdom::key::PROVERB:
			ofst << "���������: " << wd.content << endl;
			Out(wd.pr, ofst);
			ofst << "������ ����������: " << marks_num << endl << endl;
			break;
		case wisdom::key::APHORISM:
			ofst << "�������: " << wd.content << endl;
			Out(wd.aph, ofst);
			ofst << "������ ����������: " << marks_num << endl << endl;
			break;
		default:
			ofst << "������������ �����!" << endl;
		}
	}

	bool compare(wisdom a, wisdom b)
	{
		return marks_number(a) > marks_number(b);
	}
}