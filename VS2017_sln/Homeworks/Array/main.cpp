#include <iostream>
using namespace std;

int Sum(int a[], int n) {
	int nSum{ 0 };
	for (int i = 0; i < n; i++) {
		nSum += a[i];
	}
	return nSum;
}

int Sum(int a[], int end[])
{
	int nsum = 0;
	for (int* p = a; p < end; ++p)
	{
		nsum += *p;
	}
	return nsum;
}

int main() {	//主函数
	//定义并初始化数组
	int table[] = { 1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6 };
	//输出数组元素
	for (const auto &e : table) {
		cout << e << "   ";
	}
	cout << endl;

	cout << "Sum is " << Sum(table+1, 4) << endl;	//调用子函数，计算和
		return 0;
}
