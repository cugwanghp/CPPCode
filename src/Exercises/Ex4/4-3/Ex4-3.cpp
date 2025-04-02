/*
 * @Description:
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2024-04-22 15:51:28
 * @LastEditors: Wang Hongping
 * @LastEditTime: 2024-04-22 15:53:47
 */
#include <iostream>
#include "Histogram.h"

int main()
{
	std::vector<double> range = {0.0, 60.0, 70.0, 80.0, 90.0, 100.1};
	double score[] = {10, 20, 40, 80, 70, 90, 100};
	Histogram histScore(range);

	histScore.update(score, 7);
	histScore.display();

	return 0;
}