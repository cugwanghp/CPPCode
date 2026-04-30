#include <iostream>
#include "Complex.h"
#include <string>

class Integer {
public:
		Integer(int val) : m_data(val) {}
		~Integer() = default;
		Integer operator+(Integer j) { return Integer(this->m_data*j.m_data); ; } //*this--i, j
		friend std::ostream& operator<<(std::ostream& os, Integer i);
		Integer& operator++();		//++i
		Integer operator++(int);		//i++
private:
		int	m_data; 
};

Integer& Integer::operator++() { //++i
		this->m_data += 1;
		return (*this);	//this
}

Integer Integer::operator++(int) {	//i++
		Integer	old = *this;
		this->m_data += 1;
		return old;
}

std::ostream& operator<<(std::ostream& os, Integer i) {
		os << i.m_data;
		return os;
}

int main()
{
		Int	a(3);		//
		Int	b(5);		//
		a.print();	//ok, print(&a) std::cout << a.m_val;
		b.print();	//ok, print(&b) std::cout << b.m_val;
		return 0;

		Integer	i(3), j(4);
		Integer	k = i+j;		//
		// operator<<(std::cout, k);		函数调用
		// operator<<(operator<<(std::cout, k),std::endl);
		return 0;
		//int a, b;	a+b -->表达式-值， a,b - 操作数（变量）， + - 操作符
		//int c = a+b;	//;--语句，c=a+b 复合表达式，=，+操作符，优先级，+>=
		//语句，--> function -- 多条语句组成，表达一个任务（中心），函数独立的功能
		//main函数 --> 函数（少用，语句）， 程序--目录
		//a+b 表达式， int add(int a, int b); + --> add
		//(1+2i)+(3+4i) add(1+2i, 3+4i); complex add(complex, complex);
		//int+int ==> int operator+(int,int)
		//complex+complex ==> complex operator+(complex, complex)
		//double+double ==> double operator+(doule, double)
		//int+double ==> double operator+(int, double)
		//double+int ==> double operator+(double, int)
		Complex	c1(1.0, 2.0), c2(3.0, 4.0);
		Complex	c3 = c1 + c2;		//c3=c1.operator+(c2) .operator c1+c2
		std::cout << c3 << std::endl;
		std::cout << c3++ << std::endl;
		std::cout << ++++c3++++ << std::endl;

		//a+b 表达式--值，a+b; 语句， a,b - 变量（操作数）, + - 操作符(operator)
		//function， add(a,b)--a+b, 
		//变量，操作符，表达式，c=a+b;//=,+,优先级,=>+
		//单个的操作符，c=a+b; 语句 完整的语义，数据的传递或者流动
		//语句数量多，混乱，划分章节 语句标记 --> 函数（语句的集合，一段话--函数
		//函数必须实现功能（不要在函数里做多件事）
		// +，-，*，/ ====> function 有没有关系
		// +，-，*， /， <<, >>,++,--,++,--,都是函数
		// + --> int operator+(int, int);   a+b ==> operator+(a,b) 函数的名称
		//1+2   int operator+(int, int);
		//1.0+2 double operator+(double, int);
		//1+2.0 double operator+(int, double);
			return 0;
}

