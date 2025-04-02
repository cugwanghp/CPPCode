/*
 * @Description: 
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2025-02-27 11:05:55
 * @LastEditors: Wang Hongping
 * @LastEditTime: 2025-02-28 21:37:21
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

int main()
{
    srand(time(0));
    int num = rand() % 100 + 1;

    int guess;
    int tries = 0;
    
    do {
        std::cout << "Enter a guess: ";
        std::cin >> guess;
        tries++;
        
        if (guess > num) {
            std::cout << "Too high!\n";
        } else if (guess < num) {
            std::cout << "Too low!\n";
        } else {
            std::cout << "Correct! The number was " << num << std::endl;
            std::cout << "It took you " << tries << " tries.\n";
        }
    } while (guess != num);

    return 0;
}