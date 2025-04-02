#pragma once

/*
3. 写一个 Histogram 类来执行直方图计算（即计算每个间隔中有多少个值）。类应满足以下要求：
(a). 提供一个构造函数，该构造函数采用 std::vector<double> 来指定直方图边界。std::vector 的元素必须严
格单调递增。例如：std::vector<double>{0.3, 3.14, 20.0, 42.42} 将创建一个具有三个级别的直方图，分
别对应于区间 [0, 3.14), [3.14, 20) 和 [20, 42.42)。
(b). 提供成员函数 clear，用于清除直方图统计值。
(c). 提供成员函数 update，将新的数据值添加到直方图统计中。该函数要能够以某种适当的方式处理超出
范围的数据。
(d). 提供一个成员函数 display，将直方图的内容输出到标准输出流（即 std::ostream）。
(e). 不提供默认构造函数。
(f). 提供移动和复制构造函数、移动和复制赋值运算符以及析构函数。
(g). 所有数据成员都是私有的。
编写一个程序来全面测试直方图类。
*/
#include <vector>
class Histogram
{
public:
		Histogram(std::vector<double>& range);
		Histogram() = delete;

		Histogram(const Histogram& hr);
		Histogram operator=(const Histogram& hr);

		Histogram(Histogram&& hrr);
		Histogram operator=(const Histogram&& hrr);

		~Histogram();
		void clear();		//
		void update(double data[], int n);	//

		void display() const;

private:
		std::vector<double>	m_range;		//range
		std::vector<int>		m_hist;			//histogram
};

