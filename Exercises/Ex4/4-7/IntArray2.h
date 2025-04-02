/*
 * @Description:
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2024-04-22 17:06:17
 * @LastEditors: Wang Hongping
 * @LastEditTime: 2024-04-22 17:41:41
 */
#pragma once
/*
7. 编写一个表示二维整数数组的类 IntArray2。类应满足以下要求：
(a).提供一个默认构造函数来创建一个空（即 0 × 0）数组。
(b).提供一个构造函数，该构造函数采用与要创建的数组的宽度和高度相对应的两个参数。
(c).可使用 std::vector 类模板存储数组的元素。
(d).提供可移动和可复制的拷贝构造函数。
(e).提供成员函数来查询数组的宽度、高度和大小（即元素数量）。
(f).提供对数组第(x, y) 个元素的访问。
(g).提供输出流操作符 «，以便可以将数组写入输出流（std::ostream）。
(h).提供输入流操作符 »，以便可以从输入流（std::istream）读取数组。
(i).所有数据成员都应该是私有的。
编写一个程序来彻底测试 IntArray2
*/
#include <vector>
#include <iostream>

class IntArray2
{
public:
	IntArray2();
	IntArray2(int m, int n);
	IntArray2(const IntArray2 &arr);
	IntArray2& operator=(const IntArray2& arr);
	IntArray2(IntArray2&& arr);
	IntArray2& operator=(IntArray2&& arr);
	~IntArray2();

	int &get(int x, int y);
	const int &get(int x, int y) const;

	friend std::ostream &operator<<(std::ostream &os, const IntArray2& arr);
	friend std::istream &operator>>(std::istream &is, IntArray2& arr);

private:
	std::vector<std::vector<int> > m_data; //
	int m_row;
	int m_col;
};

std::ostream & operator<<(std::ostream &os, const IntArray2 &arr);
std::istream & operator>>(std::istream &is, IntArray2 &arr);