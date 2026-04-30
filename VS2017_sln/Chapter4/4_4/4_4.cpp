/*
 * @Author: cugwanghp wanghp@cug.edu.cn
 * @Date: 2025-04-02 10:43:53
 * @LastEditors: cugwanghp wanghp@cug.edu.cn
 * @LastEditTime: 2026-03-30 15:18:45
 * @FilePath: \CPPCode\VS2017_sln\Chapter4\4_4\4_4.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
//4_4.cpp
#include "Line.h"
#include <iostream>

//主函数
int main() {
		Line		l2 = getLine();

    Point myp1(1, 1), myp2(4, 5);	//建立Point类的对象
    
    Line line(myp1, myp2);	//建立Line类的对象
    Line line2(line);	//利用复制构造函数建立一个新对象
    
    std::cout << "The length of the line is: ";
    std::cout << line.getLen() << std::endl;
    
    std::cout << "The length of the line2 is: ";
    std::cout << line2.getLen() << std::endl;
    
    return 0;
}
