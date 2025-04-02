#include <iostream>
#include <cmath>

double power(int x, int n) {
		int	res = 1;
		if (n >= 0) {
				while(n--) {
						res *= x;
				}
				return res;
		}
		return 1 / power(x, -n);
}

void swap(int& x, int& y) {		//x,y 形参
		int t = x;
		x = y;
		y = t;
}

inline int add(int x, int y) {
		return x + y;
}

inline double add(double x, double y) {
		return x + y;
}

inline double add(double x, int y) {
		return x + static_cast<double>(y);
}

inline double add(int x, double y) {
		return static_cast<double>(x) + y;
}

int main() {
		int	a = 2, b = 3;
		std::cout << add(2, 3) << std::endl;
		std::cout << add(2.1, 3) << std::endl;
		std::cout << add(2, 3.1) << std::endl;
		std::cout << add(2.1, 3.2) << std::endl;
		//swap(a, b);		// a,b 实参
		//std::cout << a << "\t" << b << std::endl;

		//std::cout << power(a, b) << std::endl;
		//std::cout << power(2.1f, b) << std::endl;
		
		return 0;
}
