/*
#include <iostream>

void f(int& n)
{
		int	m = 0;
		while (n)
		{
				m = 10*m + n % 10;
				n /= 10;
		}
		n = m;
}

int main()
{
		int			n = 123;
		f(n);
		std::cout << n << std::endl;
		return 0;
}
*/

/*2
#include <iostream>
int f(unsigned int a, unsigned int b)
{
		if (a == 0 || b == 0)   return 0;
		if (a%b == 0)   return b;
		return f(b, a%b);
}
int main()
{
		std::cout << f(120, 21) << std::endl;
		return 0;
}
*/

/*3
#include <iostream>
class Base {
public:
		virtual void print(std::ostream& os) const { os << "Base\n"; }
};

std::ostream& operator<<(std::ostream& os, const Base& obj)
{
		obj.print(os);
		return os;
}

class Derived : public Base {
		void print(std::ostream& os) const { os << "Derived\n"; }
};

int main()
{
		Base		obj_b;
		Derived	obj_d;
		std::cout << obj_d;
		std::cout << obj_b;
		return 0;
}
*/

/*4
#include <iostream>
class Base {
public:
		~Base() { std::cout << "~Base()\n"; }
};

class Derived : public Base {
public:
		Derived() : p{ new int{ 0 } } {}
		Derived(const Derived& other) : p{ new int{*other.p} } {}
		Derived& operator=(const Derived& other);
		~Derived();
private:
		int *p;
};
Derived& Derived::operator=(const Derived& other)
{
		if (this != &other)
				*p = *other.p;
		return *this;
}

Derived::~Derived() {
		delete p;
		std::cout << "~Derived()\n";
}

int main() {
		Base *pbobj = new Derived();
		delete pbobj;
		return 0;
}
*/

/*5-改错题
#include <iostream>
void swap(int a, int b)
{
		auto t = a;
		a = b;
		b = t;
}

int main()
{
		int	i, j;
		std::cin >> i >> j;
		swap(i, j);
		std::cout << i << "\t" << j << std::endl;
		return 0;
}
*/

/*6-改错题
#include <iostream>
int fac(unsigned int n)
{
		return (n==0? 1 : n * fac(n - 1));
}
int main()
{
		int			n;
		std::cin >> n;
		std::cout << fac(n) << std::endl;
		return 0;
}
*/

/*7-改错题
#include <iostream>
class Base {
public:
		virtual void f1(int) const { 
				std::cout << "Base::f1()\n"; }
		virtual ~Base() = default;
};

class Derived : public Base {
public:
		void f1(int) const override {
				std::cout << "Derived::f1()\n";	}
		~Derived() = default;
};

int main() {
		Base *pb = new Derived;
		pb->f1(0);
		delete pb;
		return 0;
}
*/

/*8-改错题
#include <iostream>
class Base {
public:
		Base() = default;
		~Base() = default;
};
class Derived : public Base {
public:
		Derived() = default;
		~Derived() = default;
private:
		int		data[5];
};

int main() {
		Base *pbobj = new Derived();
		std::cout << sizeof(Base) << "\t";
		std::cout << sizeof(Derived) << std::endl;
		delete pbobj;
		return 0;
}
*/
#include <iostream>
class Comparedd {
public:
		int operator<(int, int);
};

int Add::operator < (int x, int y) {
		return x < y;
}
int Add::operator[](int index) {
		return index + 1;
}

int main()
{
		int	x = 1, y = 2;
		Add	obj;
		int	z = obj(1, 2);	//obj(1,2)
		z = obj[1];	//obj[1]
		std::cout << z << std::endl;
}

template<typename T>
void sort(T* p0, T* p1, Compare& comp)