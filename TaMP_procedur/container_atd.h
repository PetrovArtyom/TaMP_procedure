#ifndef __container_atd__
#define __container_atd__

namespace simple_wisdom
{
	// ���������� ������������ ���������
	struct wisdom;

	// ���������� ��������� �� ������ ����������� �������
	struct container
	{
		// ������������ �����
		enum { max_len = 100 }; 

		// ������� �����
		int len;

		// ������ �������� ���� "��������"
		wisdom* cont[max_len];
	};
}
#endif