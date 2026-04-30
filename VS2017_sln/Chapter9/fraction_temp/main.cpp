/******************************************************************************

*******************************************************************************/
//实现分数类fraction的功能，完成简单的运算。
//数据成员包括：分子和分母（整数）
//成员函数包括：构造函数、分数简化、分数与double的强制转换，输入输出操作符重载，分数运算（包
//括分数与分数之间的 + -*/ 运算，分数与整数的 + -*/ 运算，浮点与分数的 + -*/ 运算）
//主函数如下
#include <iostream>
#include "fraction.h"
#include <string>
using namespace std;

// 求两个数最大值
template<typename T>
T max(T x, T y) {
		return (x > y) ? x : y;
}

class Student {
public:
		Student(int id, const char* name) : m_id(id), m_name(name){}
		bool operator>(const Student& other) { return m_id > other.m_id; }
private:
		int	m_id;
		std::string	m_name;
};

template<typename T>
void sort(T a[], int n)
{
		for (int i = 0; i < n - 1; i++)
		{
				for (int j = i + 1; j < n; j++)
				{
						//a[i]>a[j]
						if (a[i] > a[j])
						{
								auto t = a[i];
								a[i] = a[j];
								a[j] = t;
						}
				}
		}
}

int main()
{
		max(1, 2);	//int max(int,int)
		max(1.0, 2.0);	//double max(double, double)
		Student	stus[] = { Student(5,"5"), Student(1,"1"), Student(9,"9") };
		sort(stus, 3);	//

	fraction f1(1, 2); // 表示1/2
	fraction f2(1.2 / 0.5); // 表示1.2/0.5
	fraction f3(0.6); //转换为分数3/5
	fraction f4;
	fraction f5 = f3; //拷贝构造
	std::cout << max(f1, f2) << std::endl;
	cin >> f4; //输入分子，分母，并简化
	cout << f1 + f2 << endl;
	cout << f1 - f2 << endl;
	cout << f1 * f2 << endl;
	cout << f1 / f2 << endl;
	cout << f3 + 0.5 << endl; // -*/都支持
	cout << 0.5 + f3 << endl; // -*/都支持
	cout << f4 + 1 << endl;
	cout << 1 + f4 << endl;
	//cout << double(f5) + 0.5 << endl;
	return 0;
}