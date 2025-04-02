#include <iostream>

template <typename T>
void print(const T& val)
{
	std::cout << val << std::endl;
}

void print(char* val)
{
	std::cout << static_cast<void*>(val) << std::endl;
}

int main()
{
	int	i = 10;
	char c = 's';

	print(i);
	print(&i);

	print(c);
	print(&c);
	print(static_cast<void*>(&c));

	return 0;
}