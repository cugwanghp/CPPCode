#include <iostream>

int sum(int a[], int n);

int main() {
		int	tables[] = { 1,2,3,4,5,6,7,8,9,10 };

		for (const auto& e : tables) {
				std::cout << e << "\t";
		}
		std::cout << std::endl;

		std::cout << "sum = " << sum(tables, 12) << std::endl;
		return 0;
}

int sum(int a[], int n) {
		int	res = 0;
		for (int i = 0; i < n; i++) {
				res += a[i];
		}
		return res;
}