#include <iostream>

int sum(int a[], int n)
{
		int	sum{ 0 };
		for (int i = 0; i<n; ++i){
		//for (const auto& e : a) {
				sum += a[i];
		}
		return sum;
}

int main() {
		int	array[] = { 1,2,3,4,5,6 };
		for (const auto& e : array) {
				std::cout << e << "\t";
		}
		std::cout << std::endl;

		std::cout << sum(array, 6) << std::endl;
		return 0;
}