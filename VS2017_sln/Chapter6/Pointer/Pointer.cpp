#include <iostream>
#include <string>

int main()
{
		std::string	strTxt;
		//std::cin >> strTxt;
		std::getline(std::cin, strTxt, 'c');		//',', ';', ' ', '\t', 
		std::cout << strTxt;
		return 0;

		char		str[8] = "program";
		char		str2[8] = { 'p', 'r', 'o', '\0', 'g', 'r', 'a', 'm' };
		int			a4[4] = { 1,2,3,4 };

		int			len = 0;
		char*		pstr = str2;
		while (*pstr != '\0')		//'\0' == 0
		{
				len++;
				pstr++;
		}
		std::cout << str << std::endl;
		std::cout << str2 << std::endl;
		std::cout << a4 << std::endl;
		std::cout << len << std::endl;
		return 0;

		int			a[4] = { 1,2,3,4 };
		int*		pa = a;	//pa=&a[0]

		std::cout << std::hex << pa << ": " << *pa << std::endl;
		std::cout << std::hex << ++pa << ": " << *pa << std::endl;
		std::cout << std::hex << ++pa << ": " << *pa << std::endl;
		std::cout << std::hex << ++pa << ": " << *pa << std::endl;
		std::cout << std::hex << ++pa << ": " << *pa << std::endl;

		// for-each
		for (const auto& elem : a)
				std::cout << elem << "\t";
		std::cout << std::endl;

		// 通过数组名称
		for (int i = 0; i < 4; i++)
				std::cout << a[i] << "\t";
		std::cout << std::endl;

		// int* pa = int* const a, int a=4; a=5;
		pa = a;	//int a[4], a -- int* const a;	a is const, a++,++a,--a
		for (int i = 0; i < 4; i++)
				std::cout << pa[i] << "\t";	//pa[i], *(pa+i)
		std::cout << std::endl;

		for (pa = a; pa < a + 4; ++pa)
				std::cout << *pa << "\t";
		std::cout << std::endl;

		return 0;
}

int add(int a, int& b)
{
		return a + b;
}

int add(const int a, const int& b)
{
		return a + b;
}

/*
// 数组名称作为函数的参数
int sum(int a[], int n) //int sum(int *pa, int n)		等价的
{
		if (a == nullptr)
				return 0;		//

		int	res = 0;
		for (int i = 0; i < n; ++i)
				res += a[i];
		return res;
}
*/

// int sum(int* const pData, int n)
int sum(int* pData, int n)
{
		int	total = 0;
		for (int i = 0; i < n; ++i)
				total += pData[i];

		return total;
}

//[beg,end), int a[10]; sum(a, a+10);
int sum(int* beg, int* end)
{
		int	total = 0;
		for (int* ptr = beg; ptr < end; ++ptr)
				total += *ptr;
		
		return total;
}

