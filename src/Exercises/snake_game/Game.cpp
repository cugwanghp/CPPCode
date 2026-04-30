/*
 * @Description: 游戏主类实现
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2025-07-15 09:34:46
 */

#include "Game.h"
#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>

using namespace std;

Game::Game() : snake(WIDTH/2, HEIGHT/2), score(0), isRunning(false), isGameOver(false), gameSpeed(200) {
    food.generate(WIDTH, HEIGHT, snake.getBody());
}

void Game::run() {
    showMenu();
    
    char choice;
    cin >> choice;
    
    if (choice != '1' && choice != 's' && choice != 'S') {
        return;
    }
    
    isRunning = true;
    reset();
    
    while (isRunning && !isGameOver) {
        handleInput();
        update();
        render();
        
        this_thread::sleep_for(gameSpeed);
    }
    
    if (isGameOver) {
        showGameOver();
    }
}

void Game::handleInput() {
    if (_kbhit()) {
        char input = _getch();
        
        switch (input) {
            case 'w':
            case 'W':
            case 72: // 上箭头
                snake.changeDirection('w');
                break;
            case 's':
            case 'S':
            case 80: // 下箭头
                snake.changeDirection('s');
                break;
            case 'a':
            case 'A':
            case 75: // 左箭头
                snake.changeDirection('a');
                break;
            case 'd':
            case 'D':
            case 77: // 右箭头
                snake.changeDirection('d');
                break;
            case 27: // ESC键
                isRunning = false;
                break;
        }
    }
}

void Game::update() {
    snake.move();
    
    // 检查是否吃到食物
    if (food.isEaten(snake.getHead())) {
        snake.grow();
        score += 10;
        food.generate(WIDTH, HEIGHT, snake.getBody());
        
        // 增加游戏速度
        if (gameSpeed.count() > 100) {
            gameSpeed = chrono::milliseconds(gameSpeed.count() - 5);
        }
    }
    
    // 检查碰撞
    if (snake.checkWallCollision(WIDTH, HEIGHT) || snake.checkSelfCollision()) {
        isGameOver = true;
    }
}

void Game::render() const {
    system("cls"); // 清屏
    
    // 显示分数
    cout << "贪吃蛇游戏 - 分数: " << score << endl;
    cout << "使用 WASD 或方向键控制，ESC退出" << endl;
    cout << endl;
    
    // 创建游戏区域
    char gameArea[HEIGHT][WIDTH];
    
    // 初始化空白区域
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            gameArea[y][x] = ' ';
        }
    }
    
    // 绘制蛇
    const auto& snakeBody = snake.getBody();
    for (size_t i = 0; i < snakeBody.size(); i++) {
        int x = snakeBody[i].first;
        int y = snakeBody[i].second;
        
        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
            if (i == 0) {
                gameArea[y][x] = '@'; // 蛇头
            } else {
                gameArea[y][x] = 'o'; // 蛇身
            }
        }
    }
    
    // 绘制食物
    pair<int, int> foodPos = food.getPosition();
    if (foodPos.first >= 0 && foodPos.first < WIDTH && 
        foodPos.second >= 0 && foodPos.second < HEIGHT) {
        gameArea[foodPos.second][foodPos.first] = '*';
    }
    
    // 绘制边界
    cout << "+";
    for (int x = 0; x < WIDTH; x++) {
        cout << "-";
    }
    cout << "+" << endl;
    
    // 绘制游戏区域
    for (int y = 0; y < HEIGHT; y++) {
        cout << "|";
        for (int x = 0; x < WIDTH; x++) {
            cout << gameArea[y][x];
        }
        cout << "|" << endl;
    }
    
    // 绘制底部边界
    cout << "+";
    for (int x = 0; x < WIDTH; x++) {
        cout << "-";
    }
    cout << "+" << endl;
}

void Game::showMenu() const {
    system("cls");
    cout << "================================" << endl;
    cout << "        贪吃蛇游戏" << endl;
    cout << "================================" << endl;
    cout << endl;
    cout << "游戏规则：" << endl;
    cout << "- 使用 WASD 或方向键控制蛇的移动" << endl;
    cout << "- 吃到食物(*)可以得分并增长" << endl;
    cout << "- 撞到墙壁或自己会游戏结束" << endl;
    cout << "- ESC键可以随时退出游戏" << endl;
    cout << endl;
    cout << "选择操作：" << endl;
    cout << "1. 开始游戏" << endl;
    cout << "2. 退出" << endl;
    cout << endl;
    cout << "请输入选择: ";
}

void Game::showGameOver() const {
    system("cls");
    cout << "================================" << endl;
    cout << "        游戏结束!" << endl;
    cout << "================================" << endl;
    cout << endl;
    cout << "最终分数: " << score << endl;
    cout << endl;
    cout << "按任意键返回主菜单...";
    _getch();
}

void Game::reset() {
    snake = Snake(WIDTH/2, HEIGHT/2);
    score = 0;
    isGameOver = false;
    gameSpeed = chrono::milliseconds(200);
    food.generate(WIDTH, HEIGHT, snake.getBody());
}

bool Game::gameOver() const {
    return isGameOver;
}

int Game::getScore() const {
    return score;
}
