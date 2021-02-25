#ifndef __wisdom_atd__
#define __wisdom_atd__

// Подключение необходимых типов данных
#include "proverb_atd.h"
#include "aphorism_atd.h"
#include "riddle_atd.h"
namespace simple_wisdom 
{
	// структура, обобщающая все имеющиеся фразы
	struct wisdom
	{
		char content[200];       // Содержание
		// значения ключей для каждой из фразы
		enum key { PROVERB, APHORISM, RIDDLE};
		key k; // ключ
		// используемые альтернативы
		union
		{ // используем включение
			proverb pr;
			aphorism aph;
			riddle rd;
		};
	};
}
#endif