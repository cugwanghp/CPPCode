/*
 * @Author: cugwanghp wanghp@cug.edu.cn
 * @Date: 2026-03-25 10:17:06
 * @LastEditors: cugwanghp wanghp@cug.edu.cn
 * @LastEditTime: 2026-03-26 23:27:38
 * @FilePath: \CPPCode\VS2017_sln\Chapter4\Clock\main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include "Clock.h"

int main() {
		std::cout << "你好C++\n";
		return 0;
		Clock		c;//ok - default
		Clock		c2(12, 0, 0);		//ok Clock(int, int, int) 
		Clock		c3(12);	//ok?
		Clock		c4(12, 0);	//ok?
		Clock		c5(c2);		//Clock::Clock(c2)， c2-实参, const Clock, Clock&, const Clock&
		//Clock(Clock c);		//c-形参， c2 copy to c
		// Clock fun();			//return value
		std::cin >> c.hour >> c.minute >> c.second;
		return 0;
}