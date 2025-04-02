#include <iostream>

int main()
{
		//1*1=1
		//1*2=2 2*2=4
		//1*3=3	
		int	a, b, c;
		//a: 1-9
		//b: 1-a
		for (a = 1; a < 10; ++a)
		{
				for (b = 1; b < a + 1; ++b)
				{
						c = a * b;
						std::cout << c;
				}
				std::cout << std::endl;
		}
		
		return 0;
}