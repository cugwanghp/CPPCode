#include <iostream>
/*编写表示有理数的 Rational 类（即 x
y 形式的数，其中 x 和 y 为整数，且 y ̸ = 0）。该类应满足以下要求：
(a).提供整型分子和分母成员。
(b).提供一个接收两个整型参数的构造函数，分别对应有理数的分子和分母值。第一个参数的默认值应为
0。第二个参数的默认值应为 1。
(c).提供移动和复制构造函数、移动和复制赋值运算符以及一个析构函数。
(d).提供 += 、 -= 、 *= 和 /= 操作符函数。
(e).提供强制转换为 double 成员函数，返回有理数的最佳浮点近似值。
(f).提供操作符 «，使用类似 - ̈15 / 23 的 ̈格式将有理数写入输出流（std::ostream）。
(g).简化有理数的分子和分母。
(h).所有数据成员都是私有的。*/
int gongyue(int a, int b);
class rational
{
public:
	rational(int a = 0, int b = 1);
	rational(double a);
	rational(const rational& rat);
	rational(rational&& rat);
	~rational();

	rational operator+(rational& rat);
	rational operator-(rational& rat);
	rational operator*(rational& rat);
	rational operator/(rational& rat);
	double turn()const;

	friend std::ostream& operator<<(std::ostream& os, rational& rat);
	friend std::istream& operator>>(std::istream& os, rational& rat);
	
private:
	int m_nu, m_de;
};

std::ostream& operator<<(std::ostream& os, rational& rat);
std::istream& operator>>(std::istream& os, rational& rat);
