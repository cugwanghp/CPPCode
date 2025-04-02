#include "swap.h"

// swap by reference
void swap(int& a, int& b) {
		int	t = a;
		a = b;
		b = t;
}

// swap by value
void swap(int a, int b) {
		int	t = a;
		a = b;
		b = t;
}

// int i, j;
// swap(&i, &j);
void swap(int* pa, int* pb) {
		// 参数合法性检查
		if (pa == nullptr || pb == nullptr)
				return;

		int	t = *pa;
		*pa = *pb;
		*pb = t;
		/*
		int* pt = pa;
		pa = pb;
		pb = pt;
		*/
}

// pa == nullptr ,*pa -- 无效的
void swap(int* pa, int* pb, int n)
{
		if (pa == nullptr || pb == nullptr)
				return;

		for (int i = 0; i < n; i++)
		{
				int	t = *(pa + i);
				*(pa + i) = *(pb + i);
				*(pb + i) = t;
		}
}