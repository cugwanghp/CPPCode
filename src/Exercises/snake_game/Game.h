/*
 * @Description: 游戏主类定义
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2025-07-15 09:34:00
 */

#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"
#include <chrono>

class Game {
private:
    static const int WIDTH = 20;
    static const int HEIGHT = 20;
    
    Snake snake;
    Food food;
    int score;
    bool isRunning;
    bool isGameOver;
    std::chrono::milliseconds gameSpeed;
    
public:
    Game();
    
    // 游戏主循环
    void run();
    
    // 处理用户输入
    void handleInput();
    
    // 更新游戏状态
    void update();
    
    // 渲染游戏画面
    void render() const;
    
    // 显示开始菜单
    void showMenu() const;
    
    // 显示游戏结束画面
    void showGameOver() const;
    
    // 重置游戏
    void reset();
    
    // 检查游戏是否结束
    bool gameOver() const;
    
    // 获取分数
    int getScore() const;
};

#endif
