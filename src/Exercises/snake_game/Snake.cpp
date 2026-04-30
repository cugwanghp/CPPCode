/*
 * @Description: Snake类实现
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2025-07-15 09:31:25
 */

#include "Snake.h"

Snake::Snake(int startX, int startY) {
    body.push_back(make_pair(startX, startY));
    direction = 'd'; // 默认向右移动
}

void Snake::move() {
    if (body.empty()) return;
    
    pair<int, int> newHead = body[0];
    
    // 根据方向移动蛇头
    switch (direction) {
        case 'w': newHead.second--; break; // 上
        case 's': newHead.second++; break; // 下
        case 'a': newHead.first--; break;  // 左
        case 'd': newHead.first++; break;  // 右
    }
    
    // 将新头部插入到身体前面
    body.insert(body.begin(), newHead);
    
    // 移除尾部（除非蛇正在增长）
    if (body.size() > 1) {
        body.pop_back();
    }
}

void Snake::changeDirection(char newDirection) {
    // 防止反向移动
    if ((direction == 'w' && newDirection == 's') ||
        (direction == 's' && newDirection == 'w') ||
        (direction == 'a' && newDirection == 'd') ||
        (direction == 'd' && newDirection == 'a')) {
        return;
    }
    direction = newDirection;
}

void Snake::grow() {
    // 蛇增长：不移除尾部
    if (!body.empty()) {
        pair<int, int> tail = body.back();
        body.push_back(tail);
    }
}

bool Snake::checkWallCollision(int width, int height) const {
    if (body.empty()) return false;
    
    pair<int, int> head = body[0];
    return (head.first < 0 || head.first >= width || 
            head.second < 0 || head.second >= height);
}

bool Snake::checkSelfCollision() const {
    if (body.size() < 2) return false;
    
    pair<int, int> head = body[0];
    
    // 检查蛇头是否与身体其他部分碰撞
    for (size_t i = 1; i < body.size(); i++) {
        if (body[i] == head) {
            return true;
        }
    }
    return false;
}

pair<int, int> Snake::getHead() const {
    return body.empty() ? make_pair(0, 0) : body[0];
}

const vector<pair<int, int>>& Snake::getBody() const {
    return body;
}

char Snake::getDirection() const {
    return direction;
}
