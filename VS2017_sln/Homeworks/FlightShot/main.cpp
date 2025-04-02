
#include "FlightGame.h"
//定义图片变量
IMAGE map1, mine[2], map[7], tubiao[10], shuzi[3], shuziyama[3];
Role minePlan;//定义我方飞机
DWORD t1, t2, t3, t4, t5, t6, t7, t8;//什么变量
IMAGE enemy2[5], enemy2yanma[5];
int img_x, img_y;
//IMAGE tu[2];
int Num[7], count = 0;

int MainMenu()
{
	MOUSEMSG m, m2, m3, m4;//定义鼠标变量
	while (1)//主菜单操作
	{
		putimage(0, 0, &map[0]);
		FlushBatchDraw();
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//当鼠标左键按下
		{
			if (m.x > 230 && m.x < 371 && m.y>46 && m.y < 83)//选择角色
			{
				putimage(0, 0, &map[5]);//角色选择界面
				FlushBatchDraw();
				while (1)
				{
					m3 = GetMouseMsg();
					if (m3.uMsg == WM_LBUTTONDOWN)//当鼠标左键按下
					{
						if (m3.x < 147 && m3.x>57 && m3.y > 210 && m3.y < 291)//1号机
						{
							minePlan.kind = 1;
							break;
						}
						if (m3.x < 537 && m3.x>449 && m3.y > 210 && m3.y < 291)//2号机
						{
							minePlan.kind = 2;
							break;
						}
					}
				}
			}
			if (m.x > 230 && m.x < 371 && m.y>154 && m.y < 193)//开始游戏
			{
				break;
			}
			if (m.x > 230 && m.x < 371 && m.y>270 && m.y < 306)//退出游戏
			{
				DataConserve();
				return 0;
			}
			if (m.x > 230 && m.x < 371 && m.y>381 && m.y < 421)//游戏记录
			{
				putimage(0, 0, &map[6]);//显示历史最高纪录
				putimage(0, 0, &tubiao[0], NOTSRCERASE);
				putimage(0, 0, &tubiao[1], SRCINVERT);
				int score = Datadir();
				//输出位置
				img_x = 196;
				img_y = 275;
				count = 0;//数组下标归零
				if (score == -1)
					OutScore(0);
				else
					OutScore(score);
				FlushBatchDraw();
				while (1)
				{
					m4 = GetMouseMsg();
					if (m4.uMsg == WM_LBUTTONDOWN)//当鼠标左键按下
					{
						if (m4.x < 50 && m4.x>0 && m4.y > 0 && m4.y < 50)
						{
							break;
						}
					}
				}
			}
			if (m.x > 230 && m.x < 371 && m.y>484 && m.y < 3524)//游戏帮助
			{
				putimage(0, 0, &map[1]);//显示游戏操作说明
				putimage(0, 0, &tubiao[0], NOTSRCERASE);
				putimage(0, 0, &tubiao[1], SRCINVERT);
				FlushBatchDraw();
				while (1)
				{
					m2 = GetMouseMsg();
					if (m2.uMsg == WM_LBUTTONDOWN)//当鼠标左键按下
					{
						if (m2.x < 50 && m2.x>0 && m2.y > 0 && m2.y < 50)
						{
							break;
						}
					}
				}
			}
		}

	}
}

int main()
{
	minePlan.kind = 1;//默认为1号机
D://返回主菜单
	t1 = t2 = t3 = t4 = t5 = t6 = t7 = t8 = GetTickCount();//获取系统开机到当前所经过的毫秒数
	//图形化窗口
	initgraph(WIDTH, HEIGHT);
	//地图
	image(&map1, &minePlan);
	mciSendString("open startMusic.mp3 alias start", NULL, 0, NULL);//alias 起别为 mymusic;
	mciSendString("play start repeat", NULL, 0, NULL);
	putimage(0, 0, &map[0]);
	FlushBatchDraw();
	//主菜单
	if (MainMenu() == 0)//在主菜单中选择退出游戏时，结束游戏
		return 0;
R://游戏重新开始
	image(&map1, &minePlan);
	mciSendString("close start ", NULL, 0, NULL);
	mciSendString("close time ", NULL, 0, NULL);
	mciSendString("open 倒计时.wav alias time", NULL, 0, NULL);//倒计时音乐
	mciSendString("play time ", NULL, 0, NULL);
	int jishu = 3;
	while (jishu > 0)//游戏开始倒计时
	{
		putimage(0, 0, &map1);
		putimage(300, 350, 17, 22, &shuziyama[0], jishu * 17, 0, NOTSRCERASE);
		putimage(300, 350, 17, 22, &shuzi[0], jishu * 17, 0, SRCINVERT);
		FlushBatchDraw();
		Sleep(1000);
		jishu--;
	}
	putimage(280, 350, &tubiao[5], NOTSRCERASE);
	putimage(280, 350, &tubiao[4], SRCINVERT);
	FlushBatchDraw();
	Sleep(1000);
	mciSendString("close start ", NULL, 0, NULL);
	mciSendString("open ll.mp3 alias mymusic", NULL, 0, NULL);//alias 起别为 mymusic;
	mciSendString("play mymusic repeat", NULL, 0, NULL);
	while (1)
	{
		BeginBatchDraw();//开启双缓冲绘图，在内存中画好，再显示出来
		int b = keyDown(&map1, 10);
		drowGame();	//更新当前的地图，飞机，子弹,重复执行子弹移动的函数，实现子弹的移动
		if (b == 1)//退出游戏
		{
			mciSendString("stop mymusic", NULL, 0, NULL);//关掉背景音乐
			PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//关掉子弹音效
			break;
		}
		else if (b == 2)//暂停
		{
			if (timeout() == 1)//返回1,代表返回主菜单
			{
				mciSendString("stop mymusic", NULL, 0, NULL);//关掉背景音乐
				goto D;
			}
		}
		else if (b == 3)//我方死亡，boss死亡
		{
			mciSendString("stop mymusic", NULL, 0, NULL);//关掉背景音乐
			PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//关掉子弹音效
			break;
		}
		FlushBatchDraw();
		Sleep(20);//延时函数
	}
	//判断游戏结束后的选择
	DataConserve();//每次退出游戏界面后保存数据
	char how;
	how = GameOver();//游戏结束结束界面的选择
	if (how == 'D')
		goto D;
	else if (how == 'R')
		goto R;
	return 0;
}