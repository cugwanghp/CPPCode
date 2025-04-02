#include <iostream>
#include "array.h"

int main() {
		array   arr(3);
		std::cin >> arr[0] >> arr[1] >> arr[2];
		array   arr2 = 2 * arr;
		std::cout << arr2[0] << "\t" << arr2[1] << "\t" << arr2[2] << std::endl;
		return 0;
}