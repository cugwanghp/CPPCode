#pragma once

#include <iostream>
#include <cstring>

template <typename T, int size> // size is the expression parameter
class StaticArray
{
private:
		// The expression parameter controls the size of the array
		T m_array[size]{};

public:
		T* getArray() { return m_array; }

		T& operator[](int index)
		{
				return m_array[index];
		}

		friend std::ostream& operator<<(std::ostream& os,
				const StaticArray<T, size>& array);
		friend std::ostream& operator<<(std::ostream& os,
				const StaticArray<char, size>& array);
};

// Ä£°åº¯Êý
template<typename T, int size>
std::ostream& operator<<(std::ostream& os,
		const StaticArray<T, size>& array)
{
		for (int count{ 0 }; count < size; ++count)
				os << array[count] << ' ';
		return os;
}

// overload of print() function for partially specialized StaticArray<char, size>
template <int size>
std::ostream& operator<<(std::ostream& os, 
		const StaticArray<char, size>& array)
{
		for (int count{ 0 }; count < size; ++count)
				std::cout << array[count];
		return os;
}

