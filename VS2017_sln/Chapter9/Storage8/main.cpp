#include <iostream>
#include "Storage8.hpp"

int main()
{
		// Define a Storage8 for integers
		Storage8<int> intStorage;

		for (int count{ 0 }; count < 8; ++count)
				intStorage[count] = count;

		for (int count{ 0 }; count < 8; ++count)
				std::cout << intStorage[count] << '\n';

		// Define a Storage8 for bool
		Storage8<bool> boolStorage;
		for (int count{ 0 }; count < 8; ++count)
				boolStorage[count] = count & 3;

		std::cout << std::boolalpha;
		for (int count{ 0 }; count < 8; ++count)
		{
				std::cout << boolStorage[count] << '\n';
		}

		return 0;
}
