#ifndef __container_atd__
#define __container_atd__
namespace simple_wisdom
{
	struct wisdom;
	// ѕростейший контейнер на основе одномерного массива
	struct container
	{
		enum { max_len = 100 }; // максимальна€ длина
		int len;                // текуща€ длина
		wisdom* cont[max_len];
	};
}
#endif