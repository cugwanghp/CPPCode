// EasyX.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <graphics.h>
#include <conio.h>

int main()
{
	IMAGE	img;
	loadimage(&img, L"C:\\Users\\wanghp\\Pictures\\car.png");

	initgraph(640, 480);
	putimage(0, 0, &img);

	_getch();
	closegraph();
	return 0;
}