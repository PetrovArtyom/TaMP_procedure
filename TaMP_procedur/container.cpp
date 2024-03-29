#include "container_atd.h"
#include "wisdom_atd.h"
#include <fstream>
#include <iostream>

using namespace std;
namespace simple_wisdom 
{
	// ��������� ��������� ������� �������
	wisdom* In(ifstream& ifdt);
	void Out(wisdom& wd, ofstream& ofst);
	void Out_proverb(wisdom& wd, ofstream& ofst);
	bool Compare(wisdom a, wisdom b);

	// ������������� ����������
	void Init(container& c)
	{
		c.len = 0;
	}

	// ������� ���������� �� ��������� (������������ ������)
	void Clear(container& c)
	{
		for (int i = 0; i < c.len; i++)
		{
			delete c.cont[i];
		}
		c.len = 0;
	}

	// ���� ����������� ���������� �� ���������� ������
	int In(container& c, ifstream& ifst)
	{
		// ������ ���� �� ����� �����
		while (!ifst.eof())
		{
			// �������� �� �������������� ������� ���������
			if (c.len < c.max_len)
			{
				// �������� �� �������� ����
				if ((c.cont[c.len] = In(ifst)) != 0)
				{
					c.len++;
				}
				else
				{
					return 1;
				}
			}
			else
			{
				cout << "������ ����������. ������� " << c.max_len << " ���������." << endl;
				ifst.close();
				break;
			}
		}
		return 0;
	}	

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

	// ������������� ����� ����������� ���������� � ��������� �����
	void Out_proverb(container& c, ofstream& ofst)
	{
		ofst << "���������� ��������� � ����������: " << c.len << endl << endl;
		cout << "���������� ��������� � ����������: " << c.len << endl << endl;
		
		for (int i = 0; i < c.len; i++)
		{
			Out_proverb(*(c.cont[i]), ofst);
		}
	}

	// ���������� ���������
	void Sort(container& c)                          
	{
		for (int i = 0; i < c.len - 1; i++)
		{
			for (int j = i + 1; j < c.len; j++)
			{
				if(Compare(*(c.cont[i]), *(c.cont[j])))
				{
					wisdom* tmp = c.cont[i];
					c.cont[i] = c.cont[j];
					c.cont[j] = tmp;
					tmp = NULL;
				}
			}
		}
	}
}
