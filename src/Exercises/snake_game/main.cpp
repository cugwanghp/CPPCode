/*
 * @Description: 贪吃蛇游戏主程序
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2025-07-15 09:37:30
 */

#include "Game.h"
#include <iostream>

using namespace std;

int main() {
    cout << "启动贪吃蛇游戏..." << endl;
    
    Game game;
    
    // 主游戏循环
    while (true) {
        game.run();
        
        // 询问是否继续游戏
        cout << endl;
        cout << "是否继续游戏？" << endl;
        cout << "1. 重新开始" << endl;
        cout << "2. 退出" << endl;
        cout << "请输入选择: ";
        
        char choice;
        cin >> choice;
        
        if (choice != '1' && choice != 'y' && choice != 'Y') {
            break;
        }
    }
    
    cout << "感谢游戏！再见！" << endl;
    
    return 0;
}
