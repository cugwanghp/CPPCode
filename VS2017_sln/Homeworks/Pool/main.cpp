//一个两端是半圆形，中间是矩形的游泳池，需在周围建个过道，并在其四周围上栅栏，栅栏价格为35元/米，过道造价为20元/平方米。
//过道宽度为3米，游泳池矩形长度和宽度由键盘输入。
//要求编程计算并输出过道和栅栏的造价。
#include <iostream>
#include "pool.h"
using namespace std;
//主函数实现
int main()
{
	float width, height;
	float FenceCost, ConcreteCost;
	cout << "Enter the width and height of the pool: ";	 // 提示用户输入半径
	cin >> width >> height;

	pool poolRim(width, height);       //泳池边缘

	// 计算栅栏造价并输出
	int FencePrice = 35;
	FenceCost = poolRim.circumference() * FencePrice;       //圆周
	cout << "Fencing Cost is " << FenceCost << endl;

	//  计算过道造价并输出
	int ConcretePrice = 20;
	ConcreteCost = poolRim.area() * ConcretePrice;
	cout << "Concrete Cost is " << ConcreteCost << endl;

	return 0;
}