/*
 * @Description:
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2024-04-22 16:10:12
 * @LastEditors: Wang Hongping
 * @LastEditTime: 2024-04-22 16:23:00
 */
#include "Integer.h"

int main()
{
    const Integer x = 1;
    const Integer y = 2;
    const Integer z = 3;
    // Since the meaning of + and - are reversed and
    // the meaning of * and / are reversed,
    // the line of code following this comment
    // effectively computes:
    // (x - y) / (x - y) * z
    std::cout << (x + y) * (x + y) / z << "\n";
}