//6_1.cpp
#include <iostream>
using namespace std;

int main() {
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