/*
 * @Author: cugwanghp wanghp@cug.edu.cn
 * @Date: 2026-03-30 15:11:29
 * @LastEditors: cugwanghp wanghp@cug.edu.cn
 * @LastEditTime: 2026-04-06 10:31:25
 * @FilePath: \CPPCode\VS2017_sln\Chapter4\4_4\Line.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "Line.h"
#include <iostream>
#include <cmath>
#include <utility>

//组合类的构造函数
Line::Line(const Point& xp1, const Point& xp2) : p1(xp1), p2(xp2){
		std::cout << "Calling constructor of Line" << std::endl;
		double x = static_cast<double>(p1.getX() - p2.getX());
    double y = static_cast<double>(p1.getY() - p2.getY());
    len = sqrt(x * x + y * y);
}

//组合类的复制构造函数
Line::Line (const Line &l): p1(l.p1), p2(l.p2) {
    std::cout << "Calling the copy constructor of Line" << std::endl;
    len = l.len;
}

Line::Line(Line&& l) : p1(std::move(l.p1)), p2(std::move(l.p2)), len(std::move(l.len)){
		std::cout << "Calling the move constructor of Line" << std::endl;
}

Line getLine(){
		Line		l(Point(1, 2), Point(1, 3));
		return l;
}