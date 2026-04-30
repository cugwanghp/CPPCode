/*
 * @Description: 
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2025-07-15 09:29:54
 * @LastEditors: Wang Hongping
 * @LastEditTime: 2025-07-15 09:30:13
 */
#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <utility>

using namespace std;

class Snake {
private:
    vector<pair<int, int>> body;
    char direction;
    
public:
    Snake(int startX, int startY);
    
    // 移动蛇
    void move();
    
    // 改变方向
    void changeDirection(char newDirection);
    
    // 增长蛇
    void grow();
    
    // 检查是否撞墙
    bool checkWallCollision(int width, int height) const;
    
    // 检查是否撞到自己
    bool checkSelfCollision() const;
    
    // 获取蛇头位置
    pair<int, int> getHead() const;
    
    // 获取蛇身体
    const vector<pair<int, int>>& getBody() const;
    
    // 获取当前方向
    char getDirection() const;
};

#endif
