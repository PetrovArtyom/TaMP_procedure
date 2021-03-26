#include "pch.h"
#include "CppUnitTest.h"
#include "../TaMP_procedur/aphorism_atd.h"
#include "../TaMP_procedur/proverb_atd.h"
#include "../TaMP_procedur/riddle_atd.h"
#include "../TaMP_procedur/wisdom_atd.h"
#include "../TaMP_procedur/container_atd.h"
#include <iostream>
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace simple_wisdom
{
	// ��������� ��������� ������� �������
	void Init(container& c);
	void Clear(container& c);
	void In(container& c, std::ifstream& ifst);
	void Out(container& c, std::ofstream& ofst);
	void Out_proverb(container& c, std::ofstream& ofst);
	void Sort(container& c);
	
	wisdom* In(std::ifstream& ifst);
	void Out(wisdom& wd, std::ofstream& ofst);
	int marks_number(wisdom w);

	void In(proverb& pr, std::ifstream& ist);
	void In(aphorism& aph, std::ifstream& ist);
	void In(riddle& rd, std::ifstream& ist);

	void Out(proverb& pr, std::ofstream& ofst);
	void Out(aphorism& aph, std::ofstream& ofst);
	void Out(riddle& rd, std::ofstream& ofst);
}

namespace TaMPProcedureTests
{
	TEST_CLASS(TaMPProcedureTests)
	{
	public:

		TEST_METHOD(Test_Input_Container)
		{
			std::ifstream ifstr1("cont_in_1.txt");						// ������ 0 ���������
			std::ifstream ifstr2("cont_in_2.txt");						// ������ ����� - 3 ��������
			std::ifstream ifstr3("cont_in_3.txt");						// ������ ������������ - 105 ���������

			if (ifstr1.is_open() && ifstr2.is_open() && ifstr3.is_open())
			{
				int p = 4;
			}

			simple_wisdom::container c1;
			simple_wisdom::container c2;
			simple_wisdom::container c3;

			Init(c1);
			Init(c2);
			Init(c3);

			In(c1, ifstr1);
			Assert::AreEqual(0, c1.len, L"������� ������ ������ ����");
			In(c2, ifstr2);
			Assert::AreEqual(3, c2.len, L"������� ������ ����������� ������� ����");
			In(c3, ifstr3);
			Assert::AreEqual(100, c3.len, L"������� ������ ������������� ����");
		}

		TEST_METHOD(Test_Clear_Container)
		{
			std::ifstream ifstr1("cont_in_1.txt");						// ������ 0 ���������
			std::ifstream ifstr2("cont_in_2.txt");						// ������ ����� - 3 ��������
			std::ofstream ofstr1("cont_clear_1.txt");
			std::ofstream ofstr2("cont_clear_2.txt");

			simple_wisdom::container c1;
			simple_wisdom::container c2;

			Init(c1);
			Init(c2);

			In(c1, ifstr1);
			In(c2, ifstr2);

			Clear(c1);
			Clear(c2);

			Out(c1, ofstr1);
			Out(c2, ofstr2);

			std::string text_sample;
			std::string text_just;

			// �������� ������ �������� (����� ������� ����������)
			std::ifstream ifst_check1("cont_clear_1.txt");
			std::ifstream ifst_check_sample1("cont_clear_sample.txt");

			while (!(ifst_check1.eof() || ifst_check_sample1.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check1, text_just);
				getline(ifst_check_sample1, text_sample);
				Assert::AreEqual(text_sample, text_just, L"��������1. �� ��������� ������");			// ���������� ��������� �����
			}

			// �������� ������ �������� (����� ����������� ����������)
			std::ifstream ifst_check2("cont_clear_2.txt");
			std::ifstream ifst_check_sample2("cont_clear_sample.txt");

			while (!(ifst_check2.eof() || ifst_check_sample2.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check2, text_just);
				getline(ifst_check_sample2, text_sample);
				Assert::AreEqual(text_sample, text_just, L"��������2. �� ��������� ������");			// ���������� ��������� �����
			}
		}

		TEST_METHOD(Test_Output_Container)
		{
			std::ifstream ifstr1("cont_in_1.txt");						// ������ 0 ���������
			std::ifstream ifstr2("cont_in_2.txt");						// ������ ����� - 3 ��������
			std::ifstream ifstr3("cont_in_3.txt");						// ������ ������������ - 105 ���������

			std::ofstream ofstr1("cont_out_1.txt");						// ���������� ������ ���� (������ ���� 0)
			std::ofstream ofstr2("cont_out_2.txt");						// ���������� ������ ���� (������ ���� 3)
			std::ofstream ofstr3("cont_out_3.txt");						// ���������� ������ ���� (������ ���� 100)

			// ������ ������� ����������
			simple_wisdom::container c1;
			simple_wisdom::container c2;
			simple_wisdom::container c3;

			// ���������������� ����������
			Init(c1);
			Init(c2);
			Init(c3);

			// ��������� ����������
			In(c1, ifstr1);
			In(c2, ifstr2);
			In(c3, ifstr3);

			// ������� ������ � �����������
			Out(c1, ofstr1);
			Out(c2, ofstr2);
			Out(c3, ofstr3);

			// �������� ������ �������� (����� ������� ����������)
			std::ifstream ifst_check1("cont_out_1.txt");
			std::ifstream ifst_check_sample1("cont_out_1_sample.txt");

			std::string text_sample;
			std::string text_just;

			while (!(ifst_check1.eof() || ifst_check_sample1.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check1, text_just);
				getline(ifst_check_sample1, text_sample);
				Assert::AreEqual(text_sample, text_just, L"��������1. �� ��������� ������");			// ���������� ��������� �����
			}

			// �������� ������ �������� (����� ����������� ����������)
			std::ifstream ifst_check2("cont_out_2.txt");
			std::ifstream ifst_check_sample2("cont_out_2_sample.txt");

			while (!(ifst_check2.eof() || ifst_check_sample2.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check2, text_just);
				getline(ifst_check_sample2, text_sample);
				Assert::AreEqual(text_sample, text_just, L"��������2. �� ��������� ������");			// ���������� ��������� �����
			}

			// �������� ������� �������� (����� ������� ����������)
			std::ifstream ifst_check3("cont_out_3.txt");
			std::ifstream ifst_check_sample3("cont_out_3_sample.txt");

			while (!(ifst_check3.eof() || ifst_check_sample3.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check3, text_just);
				getline(ifst_check_sample3, text_sample);
				Assert::AreEqual(text_sample, text_just, L"��������3. �� ��������� ������");			// ���������� ��������� �����
			}
		}

		TEST_METHOD(Test_Filter_Output_Container)
		{
			std::ifstream ifstr1("cont_filter_in_1.txt");							// ��������� ��������
			std::ifstream ifstr2("cont_filter_in_2.txt");							// ������ ��, ������� �������
			std::ifstream ifstr3("cont_filter_in_3.txt");							// ���, ����� ���������

			std::ofstream ofstr1("cont_filter_out_1.txt");
			std::ofstream ofstr2("cont_filter_out_2.txt");
			std::ofstream ofstr3("cont_filter_out_3.txt");

			// ������ ������� ����������
			simple_wisdom::container c1;
			simple_wisdom::container c2;
			simple_wisdom::container c3;

			// �������������� ����������
			Init(c1);
			Init(c2);
			Init(c3);

			// ��������� ����������
			In(c1, ifstr1);
			In(c2, ifstr2);
			In(c3, ifstr3);

			// ������� ������ � �����������
			Out_proverb(c1, ofstr1);
			Out_proverb(c2, ofstr2);
			Out_proverb(c3, ofstr3);

			// �������� ������ �������� 
			std::ifstream ifst_check1("cont_filter_out_1.txt");
			std::ifstream ifst_check_sample1("cont_filter_out_sample_1.txt");

			std::string text_sample;
			std::string text_just;

			while (!(ifst_check1.eof() || ifst_check_sample1.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check1, text_just);
				getline(ifst_check_sample1, text_sample);
				Assert::AreEqual(text_sample, text_just, L"��������1. �� ��������� ������");			// ���������� ��������� �����
			}

			// �������� ������ �������� 
			std::ifstream ifst_check2("cont_filter_out_2.txt");
			std::ifstream ifst_check_sample2("cont_filter_out_sample_2.txt");

			while (!(ifst_check2.eof() || ifst_check_sample2.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check2, text_just);
				getline(ifst_check_sample2, text_sample);
				Assert::AreEqual(text_sample, text_just, L"��������2. �� ��������� ������");			// ���������� ��������� �����
			}

			// �������� ������� �������� 
			std::ifstream ifst_check3("cont_filter_out_3.txt");
			std::ifstream ifst_check_sample3("cont_filter_out_sample_3.txt");

			while (!(ifst_check3.eof() || ifst_check_sample3.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check3, text_just);
				getline(ifst_check_sample3, text_sample);
				Assert::AreEqual(text_sample, text_just, L"��������2. �� ��������� ������");			// ���������� ��������� �����
			}
		}

		TEST_METHOD(Test_Sort_Container)
		{
			std::ifstream ifstr1("cont_sort_in_1.txt");							// ��������� ��������������� ������
			std::ifstream ifstr2("cont_sort_in_2.txt");							// �� ��������������� ������
			std::ifstream ifstr3("cont_sort_in_3.txt");							// ������� ��������������� ������

			std::ofstream ofstr1("cont_sort_out_1.txt");
			std::ofstream ofstr2("cont_sort_out_2.txt");
			std::ofstream ofstr3("cont_sort_out_3.txt");

			// ������ ������� ����������
			simple_wisdom::container c1;
			simple_wisdom::container c2;
			simple_wisdom::container c3;

			//�������������� ����������
			Init(c1);
			Init(c2);
			Init(c3);

			// ��������� ����������
			In(c1, ifstr1);
			In(c2, ifstr2);
			In(c3, ifstr3);

			// ��������� ����������
			Sort(c1);
			Sort(c2);
			Sort(c3);

			// ������� ������ � �����������
			Out(c1, ofstr1);
			Out(c2, ofstr2);
			Out(c3, ofstr3);

			// �������� ������ �������� 
			std::ifstream ifst_check1("cont_sort_out_1.txt");
			std::ifstream ifst_check_sample1("cont_sort_sample_1.txt");

			std::string text_sample;
			std::string text_just;

			while (!(ifst_check1.eof() || ifst_check_sample1.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check1, text_just);
				getline(ifst_check_sample1, text_sample);
				Assert::AreEqual(text_sample, text_just, L"��������1. �� ��������� ������");			// ���������� ��������� �����
			}

			// �������� ������ �������� 
			std::ifstream ifst_check2("cont_sort_out_2.txt");
			std::ifstream ifst_check_sample2("cont_sort_sample_2.txt");

			while (!(ifst_check2.eof() || ifst_check_sample2.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check2, text_just);
				getline(ifst_check_sample2, text_sample);
				Assert::AreEqual(text_sample, text_just, L"��������2. �� ��������� ������");			// ���������� ��������� �����
			}

			// �������� ������� �������� 
			std::ifstream ifst_check3("cont_sort_out_3.txt");
			std::ifstream ifst_check_sample3("cont_sort_sample_3.txt");

			while (!(ifst_check3.eof() || ifst_check_sample3.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check3, text_just);
				getline(ifst_check_sample3, text_sample);
				Assert::AreEqual(text_sample, text_just, L"��������3. �� ��������� ������");			// ���������� ��������� �����
			}
		}

		TEST_METHOD(Test_Parent_Class_Input)
		{
			std::ifstream ifstr("par_class_in.txt");

			simple_wisdom::wisdom* w1;
			simple_wisdom::wisdom* w2;
			simple_wisdom::wisdom* w3;

			w1 = simple_wisdom::In(ifstr);
			w2 = simple_wisdom::In(ifstr);
			w3 = simple_wisdom::In(ifstr);

			Assert::AreEqual("���� ��� ������ � ��� �����.", w1->content, L"������������ ���������� ������� � 1-�� ��������");
			Assert::AreEqual("����� ����� - ������ �������?", w2->content, L"������������ ���������� ������� � 2-�� ��������");
			Assert::AreEqual("������� ����� ���� ������", w3->content, L"������������ ���������� ������� � 3-�� ��������");
		}

		TEST_METHOD(Test_mark_number)
		{
			std::ifstream ifstr("cont_in.txt");						// ������ ����� - 3 ��������

			simple_wisdom::wisdom* w1;
			simple_wisdom::wisdom* w2;
			simple_wisdom::wisdom* w3;

			w1 = simple_wisdom::In(ifstr);
			w2 = simple_wisdom::In(ifstr);
			w3 = simple_wisdom::In(ifstr);

			Assert::AreEqual(0, marks_number(*w1), L"������������ ���������� ������� � 1-�� ��������");
			Assert::AreEqual(2, marks_number(*w2), L"������������ ���������� ������� � 2-�� ��������");
			Assert::AreEqual(5, marks_number(*w3), L"������������ ���������� ������� � 3-�� ��������");
		}

		TEST_METHOD(Test_Parent_Class_Output)
		{
			std::ifstream ifstr("par_class_in.txt");
			std::ofstream ofstr("par_class_out.txt");

			simple_wisdom::wisdom* w1;
			simple_wisdom::wisdom* w2;
			simple_wisdom::wisdom* w3;

			w1 = simple_wisdom::In(ifstr);
			w2 = simple_wisdom::In(ifstr);
			w3 = simple_wisdom::In(ifstr);

			Out(*w1, ofstr);
			Out(*w2, ofstr);
			Out(*w3, ofstr);

			// �������� 
			std::ifstream ifst_check("par_class_out.txt");
			std::ifstream ifst_check_sample("par_class_out_sample.txt");

			std::string text_sample;
			std::string text_just;

			while (!(ifst_check.eof() || ifst_check_sample.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check, text_just);
				getline(ifst_check_sample, text_sample);
				Assert::AreEqual(text_sample, text_just, L"�� ��������� ������");					// ���������� ��������� �����
			}
		}

		TEST_METHOD(Test_Daughter_Class_Input)
		{
			std::ifstream ifstr("daug_class_in.txt");

			simple_wisdom::aphorism w1;
			simple_wisdom::proverb w2;
			simple_wisdom::riddle w3;

			In(w1, ifstr);
			Assert::AreEqual("������", w1.author, L"������ � ��������");
			In(w2, ifstr);
			Assert::AreEqual("������", w2.country, L"������ � ���������");
			In(w3, ifstr);
			Assert::AreEqual("�����", w3.answer, L"������ � �������");
		}

		TEST_METHOD(Test_Daughter_Class_Output)
		{
			std::ifstream ifstr("daug_class_in.txt");
			std::ofstream ofstr("daug_class_out.txt");

			simple_wisdom::aphorism w1;
			simple_wisdom::proverb w2;
			simple_wisdom::riddle w3;

			In(w1, ifstr);
			In(w2, ifstr);
			In(w3, ifstr);

			Out(w1, ofstr);
			Out(w2, ofstr);
			Out(w3, ofstr);
			ofstr.close();

			// �������� 
			std::ifstream ifst_check("daug_class_out.txt");
			std::ifstream ifst_check_sample("daug_class_out_sample.txt");

			std::string text_sample;
			std::string text_just;

			while (!(ifst_check.eof() || ifst_check_sample.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check, text_just);
				getline(ifst_check_sample, text_sample);
				Assert::AreEqual(text_sample, text_just, L"�� ��������� ������");					// ���������� ��������� �����
			}
		}
	};
}
