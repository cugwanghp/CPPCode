#include <iostream>

int main() {
    int num;
    std::cin >> num;
    int hundreds = num / 100;  
    int tens = (num % 100) / 10;  
    int units = num % 10;  
    std::cout << "百位:" << hundreds << std::endl;
    std::cout << "十位:" << tens << std::endl;
    std::cout << "个位:" << units << std::endl;
    return 0;
}