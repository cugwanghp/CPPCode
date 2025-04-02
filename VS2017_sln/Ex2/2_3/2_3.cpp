#include <iostream>


int main()
{
	int	hour, minute, second;

	//input time
	inputTime(hour, minute, second);

	//output time
	outputTime(hour, minute, second);

	std::cin >> hour >> minute >> second;
	if (hour < 0 || hour > 24 || minute<0 || minute>60 || second<0 || second>60)
	{
		std::cout << "input error." << std::endl;
	}
	else
	{
		std::cout << hour << minute << second;
	}

	return 0;
}