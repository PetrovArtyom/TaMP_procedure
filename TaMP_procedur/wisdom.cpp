#include <fstream>
#include <iostream>
#include "wisdom_atd.h"
using namespace std;
namespace simple_wisdom 
{
	// ��������� ��������� ������� �������
	int In(proverb& pr, ifstream& ist);
	int In(aphorism& aph, ifstream& ist);
	int In(riddle& rd, ifstream& ist);

	// ���� ���������� ���������� �������� �� �����
	wisdom* In(ifstream& ifst)
	{
		// ���������� ���� ��������
		char k;
		ifst >> k;

		// �������� ������� �� �������������� � ������
		if ((int)k > 57 || (int)k < 48)			
		{
			cout << endl << "Error! Incorrect input of wisdom type. Please check input file." << endl;
			return 0;
		}

		// ��������������� char � int
		int wd_type = (int)k - 48;

		// ���������� ����������� ������� \n
		char tmp;
		ifst.get(tmp);

		// ���� ������� ������ ��������� �������� - ����������
		wisdom* wd = new wisdom;
		ifst.getline(wd->content, 200);

		//�������� ��������� ������
		if (wd->content[0] == '\0')
		{
			cout << endl << "Error! Incorrect input of wisdom type. Please check input file." << endl;
			return 0;
		}

		// ���� ������� ������ ��������� �������� - ������
		char str[4];
		ifst.getline(str, 4);

		// �������� ����, ��� ������ �������� ������
		int count = 0;
		while (str[count] != '\n' && str[count] != '\0' && count < 4)
		{
			if ((int)str[count] > 57 || (int)str[count] < 48)
			{
				cout << endl << "Error! Incorrect input of wisdom type. Please check input file." << endl;
				return 0;
			}
			count++;
		}

		// �������� �� ���������� ������� ������ ��������� - ������
		if (count == 0)
		{
			cout << endl << "Error! Incorrect input of wisdom type. Please check input file." << endl;
			return 0;
		}

		// ��������� ������ � int 
		int mark = atoi(str);

		ifst.get(tmp);
		wd->mark = mark;

		switch (wd_type) 
		{
		case 1:
			wd->k = wisdom::key::PROVERB;
			if (In(wd->pr, ifst) == 1)
			{
				return 0;
			}
			return wd;
		case 2:
			wd->k = wisdom::key::APHORISM;
			if (In(wd->aph, ifst) == 1)
			{
				return 0;
			}
			return wd;
		case 3:
			wd->k = wisdom::key::RIDDLE;
			if (In(wd->rd, ifst) == 1)
			{
				return 0;
			}
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
	void Out(riddle& rd, ofstream& ofst);

	// ����� ���������� ������� �������� � �����
	void Out(wisdom& wd, ofstream& ofst)
	{
		int marks_num = marks_number(wd);

		// ����� �������������� ����������
		switch (wd.k)
		{
		case wisdom::key::PROVERB:
			Out(wd.pr, ofst);
			break;
		case wisdom::key::APHORISM:
			Out(wd.aph, ofst);
			break;
		case wisdom::key::RIDDLE:
			Out(wd.rd, ofst);
			break;
		default:
			ofst << "������������ �����!" << endl;
		}

		// ����� ����� ����������
		ofst << wd.content << endl << "������: " << wd.mark << endl;
		ofst << "������ ����������: " << marks_num << endl << endl;
	}

	// ������������� ����� ���������� ������� �������� � �����
	void Out_proverb(wisdom& wd, ofstream& ofst)
	{
		int marks_num = marks_number(wd);

		// ����� �������������� ����������
		switch (wd.k)
		{
		case wisdom::key::PROVERB:
			Out(wd.pr, ofst);
			break;
		case wisdom::key::APHORISM:
			break;
		case wisdom::key::RIDDLE:
			break;
		default:
			ofst << "������������ �����!" << endl;
		}

		// ����� ����� ����������
		if (wd.k == wisdom::key::PROVERB)
		{
			ofst << wd.content << endl << "������: " << wd.mark << endl;
			ofst << "������ ����������: " << marks_num << endl << endl;
		}
	}

	bool compare(wisdom a, wisdom b)
	{
		return marks_number(a) > marks_number(b);
	}
}