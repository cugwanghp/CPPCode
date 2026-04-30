/*
 * @Description: 食物类实现
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2025-07-15 09:33:07
 */

#include "Food.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

Food::Food() {
    position = make_pair(0, 0);
    srand(static_cast<unsigned>(time(0)));
}

void Food::generate(int width, int height, const vector<pair<int, int>>& snakeBody) {
    if (width <= 0 || height <= 0) return;
    
    vector<pair<int, int>> availablePositions;
    
    // 收集所有可用位置
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            pair<int, int> pos = make_pair(x, y);
            
            // 检查该位置是否被蛇占用
            bool isOccupied = false;
            for (const auto& segment : snakeBody) {
                if (segment == pos) {
                    isOccupied = true;
                    break;
                }
            }
            
            if (!isOccupied) {
                availablePositions.push_back(pos);
            }
        }
    }
    
    // 如果没有可用位置，不生成食物
    if (availablePositions.empty()) {
        return;
    }
    
    // 随机选择一个可用位置
    int randomIndex = rand() % availablePositions.size();
    position = availablePositions[randomIndex];
}

pair<int, int> Food::getPosition() const {
    return position;
}

bool Food::isEaten(const pair<int, int>& snakeHead) const {
    return position == snakeHead;
}
