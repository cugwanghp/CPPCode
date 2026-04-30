//7_3.cpp
#include <iostream>
using namespace std;

class Base1 { //基类Base1定义
public:
    virtual void display() const { cout << "Base1::ID=" << m_ID << endl; }
		virtual ~Base1() = default;
		int	m_ID = 1;
};

class Base2: public Base1 { //公有派生类Base2定义
public:
    void display() const { cout << "Base2::ID=" << m_ID << endl; }
		int			m_ID = 2;
};

class Derived: public Base2 { //公有派生类Derived定义
public:
    void display() const { cout << "Derived::ID=" << m_ID << endl; }
		int	m_ID = 3;
};

void fun(Base1 *ptr) { //参数为指向基类对象的指针
    if (ptr) ptr->display();	//"对象指针->成员名"
}

int main() {	//主函数
    Base1 base1;	//声明Base1类对象
    Base2 base2;	//声明Base2类对象
    Derived derived;	//声明Derived类对象
		
		Base1*	ptr = new Base2();	//Base2* --> Base1* 合法？
		//...
		delete ptr;	//ptr: ~Base1(), ~Base2()
    fun(&base1);	//用Base1对象的指针调用fun函数
    fun(&base2);	//用Base2对象的指针调用fun函数
    fun(&derived);	//用Derived对象的指针调用fun函数

	return 0;
}
