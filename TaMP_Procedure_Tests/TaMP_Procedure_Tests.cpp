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
	// Сигнатуры требуемых внешних функций
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
			std::ifstream ifstr1("cont_in_1.txt");						// Читаем 0 элементов
			std::ifstream ifstr2("cont_in_2.txt");						// Читаем норму - 3 элемента
			std::ifstream ifstr3("cont_in_3.txt");						// Читаем переполнение - 105 элементов

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
			Assert::AreEqual(0, c1.len, L"Неверно считан пустой файл");
			In(c2, ifstr2);
			Assert::AreEqual(3, c2.len, L"Неверно считан нормального размера файл");
			In(c3, ifstr3);
			Assert::AreEqual(100, c3.len, L"Неверно считан переполненный файл");
		}

		TEST_METHOD(Test_Clear_Container)
		{
			std::ifstream ifstr1("cont_in_1.txt");						// Читаем 0 элементов
			std::ifstream ifstr2("cont_in_2.txt");						// Читаем норму - 3 элемента
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

			// Проверка первой ситуации (вывод пустого контейнера)
			std::ifstream ifst_check1("cont_clear_1.txt");
			std::ifstream ifst_check_sample1("cont_clear_sample.txt");

			while (!(ifst_check1.eof() || ifst_check_sample1.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check1, text_just);
				getline(ifst_check_sample1, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Ситуация1. Не совпадает строка");			// Сравниваем построчно файлы
			}

			// Проверка второй ситуации (вывод нормального контейнера)
			std::ifstream ifst_check2("cont_clear_2.txt");
			std::ifstream ifst_check_sample2("cont_clear_sample.txt");

			while (!(ifst_check2.eof() || ifst_check_sample2.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check2, text_just);
				getline(ifst_check_sample2, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Ситуация2. Не совпадает строка");			// Сравниваем построчно файлы
			}
		}

		TEST_METHOD(Test_Output_Container)
		{
			std::ifstream ifstr1("cont_in_1.txt");						// Читаем 0 элементов
			std::ifstream ifstr2("cont_in_2.txt");						// Читаем норму - 3 элемента
			std::ifstream ifstr3("cont_in_3.txt");						// Читаем переполнение - 105 элементов

			std::ofstream ofstr1("cont_out_1.txt");						// Записываем первый файл (должен быть 0)
			std::ofstream ofstr2("cont_out_2.txt");						// Записываем второй файл (должен быть 3)
			std::ofstream ofstr3("cont_out_3.txt");						// Записываем третий файл (должен быть 100)

			// Создаём объекты контейнера
			simple_wisdom::container c1;
			simple_wisdom::container c2;
			simple_wisdom::container c3;

			// Иницианализируем контейнеры
			Init(c1);
			Init(c2);
			Init(c3);

			// Заполняем контейнеры
			In(c1, ifstr1);
			In(c2, ifstr2);
			In(c3, ifstr3);

			// Выводим данные с контейнеров
			Out(c1, ofstr1);
			Out(c2, ofstr2);
			Out(c3, ofstr3);

			// Проверка первой ситуации (вывод пустого контейнера)
			std::ifstream ifst_check1("cont_out_1.txt");
			std::ifstream ifst_check_sample1("cont_out_1_sample.txt");

			std::string text_sample;
			std::string text_just;

			while (!(ifst_check1.eof() || ifst_check_sample1.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check1, text_just);
				getline(ifst_check_sample1, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Ситуация1. Не совпадает строка");			// Сравниваем построчно файлы
			}

			// Проверка второй ситуации (вывод нормального контейнера)
			std::ifstream ifst_check2("cont_out_2.txt");
			std::ifstream ifst_check_sample2("cont_out_2_sample.txt");

			while (!(ifst_check2.eof() || ifst_check_sample2.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check2, text_just);
				getline(ifst_check_sample2, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Ситуация2. Не совпадает строка");			// Сравниваем построчно файлы
			}

			// Проверка третьей ситуации (вывод полного контейнера)
			std::ifstream ifst_check3("cont_out_3.txt");
			std::ifstream ifst_check_sample3("cont_out_3_sample.txt");

			while (!(ifst_check3.eof() || ifst_check_sample3.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check3, text_just);
				getline(ifst_check_sample3, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Ситуация3. Не совпадает строка");			// Сравниваем построчно файлы
			}
		}

		TEST_METHOD(Test_Filter_Output_Container)
		{
			std::ifstream ifstr1("cont_filter_in_1.txt");							// Различные мудрости
			std::ifstream ifstr2("cont_filter_in_2.txt");							// Только те, которые вывести
			std::ifstream ifstr3("cont_filter_in_3.txt");							// Все, кроме выводимых

			std::ofstream ofstr1("cont_filter_out_1.txt");
			std::ofstream ofstr2("cont_filter_out_2.txt");
			std::ofstream ofstr3("cont_filter_out_3.txt");

			// Создаём объекты контейнера
			simple_wisdom::container c1;
			simple_wisdom::container c2;
			simple_wisdom::container c3;

			// Инициализиурем контейнеры
			Init(c1);
			Init(c2);
			Init(c3);

			// Заполняем контейнеры
			In(c1, ifstr1);
			In(c2, ifstr2);
			In(c3, ifstr3);

			// Выводим данные с контейнеров
			Out_proverb(c1, ofstr1);
			Out_proverb(c2, ofstr2);
			Out_proverb(c3, ofstr3);

			// Проверка первой ситуации 
			std::ifstream ifst_check1("cont_filter_out_1.txt");
			std::ifstream ifst_check_sample1("cont_filter_out_sample_1.txt");

			std::string text_sample;
			std::string text_just;

			while (!(ifst_check1.eof() || ifst_check_sample1.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check1, text_just);
				getline(ifst_check_sample1, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Ситуация1. Не совпадает строка");			// Сравниваем построчно файлы
			}

			// Проверка второй ситуации 
			std::ifstream ifst_check2("cont_filter_out_2.txt");
			std::ifstream ifst_check_sample2("cont_filter_out_sample_2.txt");

			while (!(ifst_check2.eof() || ifst_check_sample2.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check2, text_just);
				getline(ifst_check_sample2, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Ситуация2. Не совпадает строка");			// Сравниваем построчно файлы
			}

			// Проверка третьей ситуации 
			std::ifstream ifst_check3("cont_filter_out_3.txt");
			std::ifstream ifst_check_sample3("cont_filter_out_sample_3.txt");

			while (!(ifst_check3.eof() || ifst_check_sample3.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check3, text_just);
				getline(ifst_check_sample3, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Ситуация2. Не совпадает строка");			// Сравниваем построчно файлы
			}
		}

		TEST_METHOD(Test_Sort_Container)
		{
			std::ifstream ifstr1("cont_sort_in_1.txt");							// Правильно отсортированный массив
			std::ifstream ifstr2("cont_sort_in_2.txt");							// Не отсортированный массив
			std::ifstream ifstr3("cont_sort_in_3.txt");							// Обратно отсортированный массив

			std::ofstream ofstr1("cont_sort_out_1.txt");
			std::ofstream ofstr2("cont_sort_out_2.txt");
			std::ofstream ofstr3("cont_sort_out_3.txt");

			// Создаём объекты контейнера
			simple_wisdom::container c1;
			simple_wisdom::container c2;
			simple_wisdom::container c3;

			//Инициализируем контейнеры
			Init(c1);
			Init(c2);
			Init(c3);

			// Заполняем контейнеры
			In(c1, ifstr1);
			In(c2, ifstr2);
			In(c3, ifstr3);

			// Сортируем контейнеры
			Sort(c1);
			Sort(c2);
			Sort(c3);

			// Выводим данные с контейнеров
			Out(c1, ofstr1);
			Out(c2, ofstr2);
			Out(c3, ofstr3);

			// Проверка первой ситуации 
			std::ifstream ifst_check1("cont_sort_out_1.txt");
			std::ifstream ifst_check_sample1("cont_sort_sample_1.txt");

			std::string text_sample;
			std::string text_just;

			while (!(ifst_check1.eof() || ifst_check_sample1.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check1, text_just);
				getline(ifst_check_sample1, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Ситуация1. Не совпадает строка");			// Сравниваем построчно файлы
			}

			// Проверка второй ситуации 
			std::ifstream ifst_check2("cont_sort_out_2.txt");
			std::ifstream ifst_check_sample2("cont_sort_sample_2.txt");

			while (!(ifst_check2.eof() || ifst_check_sample2.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check2, text_just);
				getline(ifst_check_sample2, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Ситуация2. Не совпадает строка");			// Сравниваем построчно файлы
			}

			// Проверка третьей ситуации 
			std::ifstream ifst_check3("cont_sort_out_3.txt");
			std::ifstream ifst_check_sample3("cont_sort_sample_3.txt");

			while (!(ifst_check3.eof() || ifst_check_sample3.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check3, text_just);
				getline(ifst_check_sample3, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Ситуация3. Не совпадает строка");			// Сравниваем построчно файлы
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

			Assert::AreEqual("Семь раз отмерь и иди спать.", w1->content, L"Неправильное количество запятых у 1-го элемента");
			Assert::AreEqual("Висит груша - нельзя скушать?", w2->content, L"Неправильное количество запятых у 2-го элемента");
			Assert::AreEqual("Безумно можно быть первым", w3->content, L"Неправильное количество запятых у 3-го элемента");
		}

		TEST_METHOD(Test_mark_number)
		{
			std::ifstream ifstr("cont_in.txt");						// Читаем норму - 3 элемента

			simple_wisdom::wisdom* w1;
			simple_wisdom::wisdom* w2;
			simple_wisdom::wisdom* w3;

			w1 = simple_wisdom::In(ifstr);
			w2 = simple_wisdom::In(ifstr);
			w3 = simple_wisdom::In(ifstr);

			Assert::AreEqual(0, marks_number(*w1), L"Неправильное количество запятых у 1-го элемента");
			Assert::AreEqual(2, marks_number(*w2), L"Неправильное количество запятых у 2-го элемента");
			Assert::AreEqual(5, marks_number(*w3), L"Неправильное количество запятых у 3-го элемента");
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

			// Проверка 
			std::ifstream ifst_check("par_class_out.txt");
			std::ifstream ifst_check_sample("par_class_out_sample.txt");

			std::string text_sample;
			std::string text_just;

			while (!(ifst_check.eof() || ifst_check_sample.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check, text_just);
				getline(ifst_check_sample, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Не совпадает строка");					// Сравниваем построчно файлы
			}
		}

		TEST_METHOD(Test_Daughter_Class_Input)
		{
			std::ifstream ifstr("daug_class_in.txt");

			simple_wisdom::aphorism w1;
			simple_wisdom::proverb w2;
			simple_wisdom::riddle w3;

			In(w1, ifstr);
			Assert::AreEqual("Волков", w1.author, L"Ошибка в афоризме");
			In(w2, ifstr);
			Assert::AreEqual("Россия", w2.country, L"Ошибка в пословице");
			In(w3, ifstr);
			Assert::AreEqual("Замок", w3.answer, L"Ошибка в загадке");
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

			// Проверка 
			std::ifstream ifst_check("daug_class_out.txt");
			std::ifstream ifst_check_sample("daug_class_out_sample.txt");

			std::string text_sample;
			std::string text_just;

			while (!(ifst_check.eof() || ifst_check_sample.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check, text_just);
				getline(ifst_check_sample, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Не совпадает строка");					// Сравниваем построчно файлы
			}
		}
	};
}
