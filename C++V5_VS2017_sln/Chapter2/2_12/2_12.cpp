#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));				//按时间设置随机数种子
	int		num = rand()%100;	//
	int		guessNum;
	int		times = 0;
	const int	maxGuessTimes = 6;

	do {
		std::cout << "Guess an integer in 0-99: ";
		std::cin >> guessNum;
		if (guessNum < num)
			std::cout << "less than number." << std::endl;
		else if (guessNum > num)
			std::cout << "more than number." << std::endl;
		else
			break;
		times++;
	} while (times < maxGuessTimes);

	if (guessNum == num)
	{
		std::cout << "You are WIN." << std::endl;
	}
	else
	{
		std::cout << "You are Lose." << std::endl;
	}
	
	return 0;
}