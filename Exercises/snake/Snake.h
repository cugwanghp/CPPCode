/*
 * @Description: 
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2024-05-31 00:31:20
 * @LastEditors: Wang Hongping
 * @LastEditTime: 2024-05-31 00:38:35
 */
#pragma once

#include<vector>
using namespace std;

//snake大类
class Snake {
public:
	int m_val;//是否有食物
};

//snake子类空对象
class Empty : public Snake {
	friend class Head;
	friend class Map;
public:
	Empty() {
		m_val = 0;
	}
};

//snake子类 蛇头
class Head :public Snake{
	friend class Body;
	friend class Map;
public:
	Head();
    void move(Map& map);
	
	void eat();
	
private:
	int m_x;
	int m_y;
	int m_direction;
	int m_speed;
	Body* m_next;
	
};

//snake子类 蛇身
class Body :public Snake{
	friend class Head;
	friend class Map;
public:
	Body(Body* last, Body* next);
	
	Body(Head* head, Body* next);

	void add();
	Body* findtail();
private:
	int m_x;
	int m_y;
	Head* m_head;
	Body* m_last;
	Body* m_next;
};


//游戏地图
class Map {
	friend class Body;
	friend class Head;
public:
	Map();
	void Fill_map(Head* head);
private:
	vector<vector<Snake>> m_map;
	int m_score;
};
