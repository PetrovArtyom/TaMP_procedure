#ifndef __container_atd__
#define __container_atd__

namespace simple_wisdom
{
	// Объявление используемой структуры
	struct wisdom;

	// Простейший контейнер на основе одномерного массива
	struct container
	{
		// Максимальная длина
		enum { max_len = 100 }; 

		// Текущая длина
		int len;

		// Массив объектов типа "мудрость"
		wisdom* cont[max_len];
	};
}
#endif