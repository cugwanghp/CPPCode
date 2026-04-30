//6_1.cpp
#include <iostream>
using namespace std;

int sum(int* pbeg, int* pend) {
		int	res = 0;
		for (int* p = pbeg; p < pend; p++) {
				res += *p;
		}
}

int sum(int a[], int n) {
		int	res = 0;
		for (int i = 0; i < n; i++) {
				res += a[i];//*(a+i)
		}
}

int sum(int* pa, int n) {
		int res = 0;
		for (int i = 0; i < n; i++) {
				res += *(pa + i);//pa[i]
		}
}
//连接2个字符串-->字符串
void strcat(const char* s1, const char* s2, char* s) {
		// 数组越界
		const char* ps1 = s1;
		const char* ps2 = s2;
		char* ps = s;
		while (*ps1 != '\0') {
				*ps++ = *ps1++;
		}
		while (*ps2 != '\0') {
				*ps++ = *ps2++;
		}
		*ps = '\0';
}

int main() {
		char		s[10];	//9
		std::string	str;
		std::cin.getline(str);
		std::cin >> s;	//ok,
		// "C++ Program|1223|3333"

		std::cin.getline(s, 9);
		
		//std::cin >> s;	//输入一个字符串
		//strcat("C++ ", "program", s);
		std::cout << s << std::endl;
		return 0;

    int a[10], b[10];
    for (int i = 0; i < 10; i++) {
        a[i] = i * 2 - 1;
        b[10 - i - 1] = a[i];
    }
    for (const auto &e:a) //范围for循环，输出a中每个元素
        cout << e << " ";
    cout << endl;
    for (int i = 0; i <10; i++) //下标迭代循环，输出b中每个元素
        cout << b[i] << " ";
    cout << endl;

		int a2[3][4] = { 1,2 };	//1,2,0,0,0,
//		int	b2[3][4] = { {1,2}, {3,4}, {5,6} };	//1,2,0,0, 3,4,0,0, 5,6,0,0
//		int	c2[][4] = {1,2,3,4}; //c2[1][4]
		
		for (auto &row : a2)
		{
				std::cout << row << " : ";
				for (auto& elem : row)
				{
						std::cout << elem << "\t";
				}
				std::cout << std::endl;
		}
		std::cout << std::endl;

    return 0;
}