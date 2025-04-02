//6_7_3.cpp
#include <iostream>
using namespace std;

//"s1", "s2" ==> "s1s2"
namespace cug {
		const char* strcat(char* s1, const char* s2)
		{
				char*		ps = s1;
				const char* ps2 = s2;
				while (*ps != '\0') ps++;	//ps-->s1 tail
				while (*ps2 != '\0') {
						*ps++ = *ps2++;
				}
				*ps = '\0';
				return s1;
		}
}

int main() {		
		int	a[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
		//1. 因为数组元素地址是连续的，
		//2. 二维数组可以通过a[i][j], a[i]
		std::cout << a << std::endl;
		for (int i = 0; i < 3; i++)
				std::cout << /*a[i]*/ *(a+i) << "\t";
		int*		pa = &a[0][0];	//a[0], &a[0][0]
		for (int i = 0; i < 3; i++)
		{
				for (int j = 0; j < 4; j++)
				{
						cout << *pa++;
				}
		}
		int*		pa[] = { a[0], a[1], a[2] };
		
		int (*pb)[4] = a;	//a[3][4]
		//int (*pb)[4]=a;	//pb 是一个指针数组
		//std::cout << a[0] << "\t" << a[1] << "\t" << a[2] << std::endl;
		//for (int* pa = &a[0][0]; pa < &a[0][0]+12; ++pa)
		//		std::cout << *pa << "\t";
		std::cout << std::endl;
		return 0;		
		

		/*
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	for (int *p = a; p < (a + 10); p++)
		cout << *p << "  ";
	cout << endl;
	*/
	return 0;
}
