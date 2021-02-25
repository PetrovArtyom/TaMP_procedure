#include "container_atd.h"
#include "wisdom_atd.h"
#include <fstream>
#include <iostream>

using namespace std;
namespace simple_wisdom {
	// ������������� ����������
	void Init(container& c)
	{
		c.len = 0;
	}
	// ������� ���������� �� ���������
	// (������������ ������)
	void Clear(container& c)
	{
		for (int i = 0; i < c.len; i++)
		{
			delete c.cont[i];
		}
		c.len = 0;
	}

	// ��������� ��������� ������� �������
	wisdom* In(ifstream& ifdt);
	// ���� ����������� ���������� �� ���������� ������
	void In(container& c, ifstream& ifst)
	{
		while (!ifst.eof())
		{
			if (c.len < c.max_len)
			{
				if ((c.cont[c.len] = In(ifst)) != 0)
				{
					c.len++;
				}
			}
			else
			{
				cout << "������ ����������. ������� " << c.max_len << " ���������." << endl;
				ifst.close();
			}
		}
	}

	// ��������� ��������� ������� �������
	void Out(wisdom& wd, ofstream& ofst);
	// ����� ����������� ���������� � ��������� �����
	void Out(container& c, ofstream& ofst)
	{
		ofst << "���������� ��������� � ����������: " << c.len << endl << endl;
		cout << "���������� ��������� � ����������: " << c.len << endl << endl;
		for (int i = 0; i < c.len; i++)
		{
			Out(*(c.cont[i]), ofst);
		}
	}
}
