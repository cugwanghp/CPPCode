/*
1.编写程序将数组 a 和数组 b 中的素数合并到数组 c 中，
然后对数组 c 中的数据，按从小到大顺序重新排列后输出。
以此例子编写程序:int a[5]={19,24,40,37,11},b[5]={3,17,9,7,20},
c[10]={0};
要求:
1)编写一个判断素数的函数;
2)编写一个排序的函数:
3)在主函数中调用上述两个函数实现题目要求。
*/

/*
1. 函数的声明
2. 函数的定义
3. 函数的调用
*/
#include <iostream>
#include <algorithm>
#include <iterator>

template<typename T>
bool isPrime(T a)
{
		for (T i = 2; i < a; ++i)
				if (a%i == 0)	return false;
		return true;
}

template<class T>
void sort(T* beg, T* last)
{
		for (T* p = beg; p != last; ++p)
		{
				T*	min_ptr = p;
				for (T* q = p + 1; q != last; ++q)
				{
						if (*min_ptr > *q) {
								min_ptr = q;
						}
				}
				if (min_ptr != p)
				{
						auto tmp = *min_ptr;
						*min_ptr = *p;
						*p = tmp;
				}
		}
}

// main.cpp 1-2
int main()
{
		int a[5] = { 19,24,40,37,11 }, b[5] = { 3,17,9,7,20 }, c[10] = { 0 };
		int	count = 0;
		for (int i = 0; i < 5; i++) {
				if (isPrime(a[i]))	
						c[count++] = a[i];
		}
		for (int i = 0; i < 5; i++) {
				if (isPrime(b[i]))
						c[count++] = b[i];
		}

		sort(c, c + count);

		std::copy(c, c + count, std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		return 0;
}