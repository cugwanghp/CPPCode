/*
 * @Description: 食物类定义
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2025-07-15 09:32:35
 */

#ifndef FOOD_H
#define FOOD_H

#include <utility>
#include <vector>

using namespace std;

class Food {
private:
    pair<int, int> position;
    
public:
    Food();
    
    // 生成新食物
    void generate(int width, int height, const vector<pair<int, int>>& snakeBody);
    
    // 获取食物位置
    pair<int, int> getPosition() const;
    
    // 检查是否与蛇头位置相同
    bool isEaten(const pair<int, int>& snakeHead) const;
};

#endif
