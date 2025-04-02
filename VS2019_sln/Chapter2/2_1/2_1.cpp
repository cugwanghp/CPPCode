//2_1.cpp
#include <iostream>

using namespace std;

int main() 
{
	char	text[] = "Hello world.";//'H', 'e', 'l', 'l', 'o', '\0'=0
	int		len = 0;
	while (text[len])
	{
		if (text[len] >= 'a' && text[len] <= 'z')	//char
		{
			text[len] = text[len] + 'A' - 'a';
		}
		++len;
	}
	std::cout << len << std::endl;
	std::cout << text << std::endl;

	int	a = -2;
	int b = 1;
	auto c = a + b;
	std::cout << c << std::endl;

	return 0;
}