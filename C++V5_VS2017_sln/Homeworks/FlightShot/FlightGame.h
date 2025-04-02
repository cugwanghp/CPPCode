#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>//文件操作的头文件sprintf()函数
#include<stdlib.h>
#include<conio.h>#include<windows.h> //GetKeyState()函数需要
#include<mmsystem.h>//playSound()函数需要.包含多媒体设备接口库
#include<math.h>//rand()随机函数需要#pragma 
comment(lib, "Winmm.lib")//导入Winmm.lib库,让歌曲可以播放
#include<graphics.h>//easyx图形库的头文件
#include<process.h>

#define NUM 20 //敌机数组数量
#define WIDTH 600	//地图宽600  
#define HEIGHT 700	//高700		
#define N  15//子弹数量
#define BOSSBUL 100//boss子弹量
#undef UNICODE //解决loadimage()的加载出问题的问题 

//定义我方飞机和敌方飞机坐标血量，子弹等...
typedef struct role//我方飞机
{
	int x;	//确定在图中的坐标	
	int y;
	int type;	//我方飞机子弹等级	
	int kind;	//我方飞机种类	
	int live;	//飞机是否存活	
	int score; //存储分数
}Role;

typedef struct enemy  //敌机
{
	int x;	//确定在图中的坐标	
	int y;
	int type;	//敌机飞机种类.	
	int live;	//飞机是否存活	
	int HP;		//血量
	char shot;	//表示飞机是否发射过子弹
}Enemy;
typedef struct _bullte //子弹
{
	int x;	//确定在图中的坐标	
	int y;
	int live;	//子弹是否存活	
	char shot;	//导弹是否发射
}Bullte;
typedef struct ico	//图标
{
	int x;	//确定在图中的坐标	
	int y;
	int live;	//飞机、子弹是否存活	
}Ico;
char PlayKeyboard(char c);
void texiao();
void image(IMAGE *map1, Role *minePlan);//图片加载//飞机移动
int keyDown(IMAGE* map1, int speed);//画出飞机移动后的地图
void drowGame();
void planMove(char c, IMAGE *mine);
char GameOver();//游戏结束后 
void DataConserve();//保存数据并退出 
void  OutScore(int number);//输出数字图片 
int timeout();//暂停函数 
int  Datadir();//记录查看
