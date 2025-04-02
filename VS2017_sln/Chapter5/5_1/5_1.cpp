//5_1.cpp
#include <iostream>

int	i;	//全局变量

int main() {
    i = 5;			//为全局变量i赋值
    {				//子块1
        int i;		//局部变量，局部作用域
        i = 7;		
        std::cout << "i = " << i << "global i=" << ::i << std::endl;//输出7
    }

    std::cout << "i = " << i << std::endl;	//输出5

    return 0;
}