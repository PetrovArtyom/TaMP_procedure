#ifndef __wisdom_atd__
#define __wisdom_atd__

// Подключение необходимых типов данных
#include "proverb_atd.h"
#include "aphorism_atd.h"
#include "riddle_atd.h"

namespace simple_wisdom 
{
	// Структура, обобщающая все имеющиеся фразы
	struct wisdom
	{
		// Строка для хранения содержания мудрости
		char content[200]; 

		// Переменная для хранения субъективной оценки
		int mark = 0;            

		// Значения ключей для каждой мудрости
		enum key { PROVERB, APHORISM, RIDDLE};

		// Переменная, являющаяся ключом
		key k; 

		// Используемые альтернативы
		union
		{ 
			proverb pr;
			aphorism aph;
			riddle rd;
		};
	};
}
#endif