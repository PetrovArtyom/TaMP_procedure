#ifndef __wisdom_atd__
#define __wisdom_atd__
// ����������� ����������� ����� ������
#include "proverb_atd.h"
#include "aphorism_atd.h"
namespace simple_wisdom {
	// ���������, ���������� ��� ��������� �����
	struct wisdom
	{
		char content[200];       // ����������
		// �������� ������ ��� ������ �� �����
		enum key { PROVERB, APHORISM };
		key k; // ����
		// ������������ ������������
		union
		{ // ���������� ���������
			proverb pr;
			aphorism aph;
		};
	};
}
#endif