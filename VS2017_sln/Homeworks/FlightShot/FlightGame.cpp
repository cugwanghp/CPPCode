#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib,"Winmm.lib")//导入Winmm.lib库,让歌曲可以播放
#include "FlightGame.h"

//图片加载函数
extern int s = 0;//boss选择
extern IMAGE map1, mine[2], map[7], tubiao[10], shuzi[3], shuziyama[3];//声明外部变量
extern Role minePlan;				//定义我方飞机
Ico ico[5], danger;					//danger危险图标，ico图标
Enemy enemyPlan[NUM], boss[2];		//定义敌方飞机
Bullte  bullet[N], enemyBult[N], BossBul[BOSSBUL], developBul[15], shell;	//定义我方和地方子弹、炮弹
extern DWORD t1, t2, t3, t4, t5, t6, t7, t8;
IMAGE enemybul, blood[2], jineng[15], jinengyanma[15], img_developBul[15], boom2[2], boom2yanma[2], cue[2], bomb[2], hudun, relive, war[15], waryanma[15], enemy[10]; //relive提示复活的图片
IMAGE  boom[11], boomyanma[11], zidan, minebit[2];//爆炸、子弹、飞机掩码
extern IMAGE enemy2[5], enemy2yanma[5];//旋转的敌机
int m = 160, BloodWidth = -10, time[7], show = 1;//dazao = 0,
int x = 0, jj = 0, enemy_x = -1, enemy_y = -1, speedx = 2, speedy = 2;//enemy_x确定敌机爆炸的位置，speedx确定升级图标的移动速度
int score = 10;//击杀一定数量的敌机，boss出现,
extern int Num[7], count, img_x, img_y;
int fen = score / 2, num_death_enemy;
int ene_2 = 0, my_2;//my_2飞机图片选择，ene_2旋转敌机图片选择
int px[2], condition = 0;//condition判断无敌状态，px用于地图移动

void image(IMAGE* map1, Role* minePlan)
{
	loadimage(&map[0], "feng.jpg", WIDTH, HEIGHT);//封面图片
	loadimage(&mine[0], "mp.JPG", 50, 50);//自身飞机
	loadimage(&minebit[0], "mpbit.jpg", 50, 50);
	loadimage(&minebit[1], "minePlan22.png");//二号飞机
	loadimage(&mine[1], "minePlan2.png");
	loadimage(map1, "map1.jpg", 600, 700);//地图1
	loadimage(&map[1], "map22.jpg", 600, 700);
	loadimage(&map[2], "gameEnd.jpg", 600, 700);
	loadimage(&map[3], "map3.jpg", 600, 1140);
	loadimage(&map[4], "map3.jpg", 600, 1140);
	loadimage(&map[5], "型号.png");
	loadimage(&map[6], "jilu.jpg");
	loadimage(&zidan, "zidan1.png", 40, 50);//子弹
	loadimage(&enemybul, "enemyBul.png", 20, 50);//敌军子弹
	loadimage(&enemy[0], "enemy1.jpg", 60, 60);//敌机掩码图
	loadimage(&enemy[1], "enemy1_1.jpg", 60, 60);
	loadimage(&enemy[2], "diji2.png", 70, 50);
	loadimage(&enemy[3], "diji22.png", 70, 50);//敌机掩码
	loadimage(&enemy[4], "diji1.png", 200, 150);//boss
	loadimage(&enemy[5], "diji11.png", 200, 150);//boss掩码
	loadimage(&enemy[6], "diji4.png", 60, 60);
	//炸弹
	loadimage(&bomb[0], "enemy\\paodan1.png");
	loadimage(&bomb[1], "enemy\\paodan11.png");

	loadimage(&img_developBul[0], "updata11.png", 20, 60);//升级子弹掩码
	loadimage(&img_developBul[1], "updata.png", 20, 60);
	//暂停提示图片
	loadimage(&cue[0], "zanting.png", 600, 700);
	//获取图标
	loadimage(&tubiao[0], "fanhui11.png", 50, 50);//掩码图，返回图标
	loadimage(&tubiao[1], "fanhui.png", 50, 50);
	loadimage(&tubiao[2], "12531.png", 50, 30);//掩码,升级图标
	loadimage(&tubiao[3], "1253.png", 50, 30);

	loadimage(&relive, "tishi.png");

	loadimage(&tubiao[6], "enemy\\weixian11.png", 50, 50);//危险图标掩码
	loadimage(&tubiao[7], "enemy\\weixian1.png", 50, 50);
	//护盾
	loadimage(&hudun, "didang.png", 90, 90);
	//技能效果
	for (int i = 0; i < 6; i++)//这种方式可以获取多张图片，减少代码量
	{
		char str[50] = "";
		sprintf_s(str, "texiao\\dian%d.jpg", i + 1);
		loadimage(&war[i], str, 60, 700);
		sprintf_s(str, "texiao\\dian1%d.jpg", i + 1);
		loadimage(&waryanma[i], str, 60, 700);
	}
	//敌人2
	loadimage(&enemy2yanma[0], "enemy\\speed_enemy11.png");
	loadimage(&enemy2[0], "enemy\\speed_enemy.png");

	loadimage(&blood[0], "blood1.png", 300, 20);//boss血量
	loadimage(&blood[1], "blood2.png", 300, 20);

	//获取数字
	loadimage(&shuzi[0], "shuzi.png");
	loadimage(&shuziyama[0], "shuzi11.png");
	loadimage(&tubiao[4], "kaishi.png", 70, 30);
	loadimage(&tubiao[5], "kaishi11.png", 70, 30);
	//爆炸图片
	for (int i = 0; i < 11; i++)
	{
		char str[50] = "";
		sprintf_s(str, "texiao\\bbb%d.png", i + 1);
		loadimage(&boom[i], str, 100, 100);
		sprintf_s(str, "texiao\\bbby%d.png", i + 1);
		loadimage(&boomyanma[i], str, 100, 100);
	}
	//爆炸2
	loadimage(&boom2[0], "texiao\\爆炸11.png", 600, 600);//boss爆炸
	loadimage(&boom2yanma[0], "texiao\\爆炸111.png", 600, 600);
	loadimage(&boom2[1], "texiao\\爆炸11.png");//我方飞机爆炸
	loadimage(&boom2yanma[1], "texiao\\爆炸111.png");

	loadimage(&jineng[0], "jineng.png", 40, 30);//技能
	loadimage(&jineng[1], "hudun.png", 70, 70);

	BloodWidth = -10;
	//初始图标不存在
	ico[0].live = 0;
	//初始化自身位置
	minePlan->x = WIDTH / 2;
	minePlan->y = 500;
	minePlan->live = 1;
	minePlan->type = 1;//子弹种类
	minePlan->score = 0;
	//初始化一部分数据
	time[0] = -1;
	time[1] = 0;
	time[2] = 0;
	time[3] = 0;
	show = 1;
	//初始化升级图标出现的时候
	num_death_enemy = 0;//击杀敌方飞机数量
	fen = score / 2;
	m = 160;//boss移动
	count = 0;//初始化存数字的数组下标
	condition = 0;//初始护盾不存在
	//初始化炮弹数据
	shell.live = 0;//初始炮弹不存在
	shell.shot = 0;
	shell.y = 0;
	//初始化子弹数据
	for (int i = 0; i < N; i++)
	{
		developBul[i].live = 0;//表示没有子弹
		bullet[i].live = 0;//表示没有子弹
	}
	//初始化敌军子弹
	for (int i = 0; i < N; i++)
	{
		enemyBult[i].live = 2;//给所有子弹上塘，所有敌军共用一个子弹库
		enemyBult[i].y = -50;
		enemyBult[i].x = 0;
	}
	//多个敌军是，可以单独写个函数，传递参数i,根据概率产生敌军的种类，默认越厉害，概率越低
	for (int i = 0; i < NUM; i++)
	{
		enemyPlan[i].live = 0;//所有不存活
		enemyPlan[i].HP = 1;
		enemyPlan[i].shot = 'N';//表示敌机未曾发射过子弹；
	}
	//初始化boss数据；
	boss[s].HP = 100;
	boss[s].type = 3;
	boss[s].live = 1;
	boss[s].x = 50;
	boss[s].y = 0;
	//初始boss子弹库
	for (int i = 0; i < BOSSBUL; i++)
		BossBul[i].live = 1;//表示有子弹，2表示子弹已发射
}
//创建线程执行的代码函数       // CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)BOOM, NULL, NULL, 0);//调用线程
DWORD WINAPI BOOM(LPVOID arg)//爆炸音效线程 //DWORD是无符号整，相当于C中的数据类型//一个返回DWORD 的API函数//
{
	mciSendString("close boom", 0, 0, 0);
	mciSendString("open Bomb.wav alias boom", 0, 0, 0);
	mciSendString("play boom", 0, 0, 0);
	return 0;
}
DWORD WINAPI tttt(LPVOID arg)//大招音效释放线程
{
	mciSendString("open dazao123.mp3 alias jineng", 0, 0, 0);
	mciSendString("play jineng ", 0, 0, 0);
	return 0;
}
//多线程爆炸动画，有闪烁的问题，暂未使用
DWORD WINAPI planBoom(LPVOID arg)//爆炸效果线程
{
	while (x < 11)
	{
		putimage(enemy_x, enemy_y, &boomyanma[x], NOTSRCERASE);
		putimage(enemy_x, enemy_y, &boom[x], SRCINVERT);
		FlushBatchDraw();
		Sleep(200);
		x++;
		if (x == 11)
		{
			x = 7;
			break;
		}
	}
	return 0;
}
//图标升级
void up()
{
	ico[0].x = enemy_x;//图标的位置等于爆炸的飞机的坐标
	ico[0].y = enemy_y;
	ico[0].live = 1;
}
int  Datadir()
{
	FILE* fp;
	if ((fp = fopen("GameData\\data.text", "r")) == NULL)
	{
		return -1;
	}
	char str[10];
	fgets(str, 9, fp);//获取历史记录
	int num_str;
	num_str = atoi(str);//将字符串转为整型
	fclose(fp);
	return num_str;
}
void showEnemy2(int enemyPlan_x, int enemyPlan_y)//打印旋转敌机
{
	switch (ene_2)
	{
	case 0:
		putimage(enemyPlan_x, enemyPlan_y, 47, 58, &enemy2yanma[0], 2, 0, NOTSRCERASE);
		putimage(enemyPlan_x, enemyPlan_y, 47, 58, &enemy2[0], 2, 0, SRCINVERT);
		break;
	case 1:
		putimage(enemyPlan_x, enemyPlan_y, 38, 58, &enemy2yanma[0], 49, 0, NOTSRCERASE);
		putimage(enemyPlan_x, enemyPlan_y, 38, 58, &enemy2[0], 49, 0, SRCINVERT);
		break;
	case 2:
		putimage(enemyPlan_x, enemyPlan_y, 20, 58, &enemy2yanma[0], 88, 0, NOTSRCERASE);
		putimage(enemyPlan_x, enemyPlan_y, 20, 58, &enemy2[0], 88, 0, SRCINVERT);
		break;
	case 3:
		putimage(enemyPlan_x, enemyPlan_y, 20, 58, &enemy2yanma[0], 108, 0, NOTSRCERASE);
		putimage(enemyPlan_x, enemyPlan_y, 20, 58, &enemy2[0], 108, 0, SRCINVERT);
		break;
	case 4:
		putimage(enemyPlan_x, enemyPlan_y, 40, 58, &enemy2yanma[0], 128, 0, NOTSRCERASE);
		putimage(enemyPlan_x, enemyPlan_y, 40, 58, &enemy2[0], 128, 0, SRCINVERT);
		break;
	}
}
void showMyPlan(int my_x, int my_y)//自身飞机二号
{
	switch (my_2)
	{
	case 0:
		putimage(my_x, my_y, 53, 87, &minebit[1], 0, 0, NOTSRCERASE);
		putimage(my_x, my_y, 53, 87, &mine[1], 0, 0, SRCINVERT);
		break;
	case 1:
		putimage(my_x, my_y, 65, 87, &minebit[1], 53, 0, NOTSRCERASE);
		putimage(my_x, my_y, 65, 87, &mine[1], 53, 0, SRCINVERT);
		break;
	case 2:
		putimage(my_x, my_y, 78, 87, &minebit[1], 118, 0, NOTSRCERASE);
		putimage(my_x, my_y, 78, 87, &mine[1], 118, 0, SRCINVERT);
		break;
	case 3:
		putimage(my_x, my_y, 67, 87, &minebit[1], 196, 0, NOTSRCERASE);
		putimage(my_x, my_y, 67, 87, &mine[1], 196, 0, SRCINVERT);
		break;
	case 4:
		putimage(my_x, my_y, 55, 87, &minebit[1], 263, 0, NOTSRCERASE);
		putimage(my_x, my_y, 55, 87, &mine[1], 263, 0, SRCINVERT);
		break;
	}
}
//创建子弹,给子弹补给
void createbullet()
{	//循环给子弹赋值，及充满子弹
	if (time[0] >= 5000 || time[0] == -1)//当技能释放完打印子弹,或者未释放技能时
	{
		for (int i = 0; i < N; i++)
		{
			if (bullet[i].live == 0)
			{
				bullet[i].live = 1;//表示有子弹，未发射；每调用一次只会产生一个子弹
				//获取当前飞机的位置，把值赋值给子弹
				if (minePlan.kind == 1)//飞机1
					bullet[i].x = minePlan.x + 6;
				else                    //飞机2
					bullet[i].x = minePlan.x + 20;
				bullet[i].y = minePlan.y;
				break;//一次只发射一颗子弹；所以break结束循环
			}
		}
		if (minePlan.type == 2)
		{
			if (time[3] == 40)
			{
				for (int i = 0; i < N; i += 2)//创建副武器子弹
				{
					if (developBul[i].live == 0 && i + 2 <= 15)//子弹不存在，
					{
						developBul[i].live = 1;
						developBul[i + 1].live = 1;
						developBul[i].x = minePlan.x - 20;
						developBul[i].y = minePlan.y;
						if (minePlan.kind == 2)
							developBul[i + 1].x = minePlan.x + 70;
						else
							developBul[i + 1].x = minePlan.x + 50;
						developBul[i + 1].y = minePlan.y;
						break;
					}
				}
			}
			time[3] += 20;
			if (time[3] > 40)
			{
				time[3] = 0;
			}
		}
	}
	//实时获取存在的敌军的位置，将位置赋值给敌军子弹
	//先创建子弹，及敌军还未产生，所有子弹均为1；而当产生第一架敌机，所有的
	for (int i = 0; i < NUM; i++)
	{
		if (enemyPlan[i].live == 1 && enemyPlan[i].shot == 'N')
		{
			for (int j = 0; j < N; j++)
			{
				if (enemyBult[j].live == 2)//若果子弹库还有子弹。给改存活的敌军发射一颗子弹，每架飞机只发射一个
				{
					enemyBult[j].x = enemyPlan[i].x + 15;
					enemyBult[j].y = enemyPlan[i].y + 45;
					enemyBult[j].live = 1;
					enemyPlan[i].shot = 'Y';
					break;
				}
			}
		}
	}
	//补充敌军子弹库
	for (int i = 0; i < N; i++)
	{
		if (enemyBult[i].y > HEIGHT)
		{
			enemyBult[i].live = 2;
		}
	}
	//产生boss子弹
	if (num_death_enemy >= score)//当大于100时进行子弹的填充
	{
		for (int i = 0; i < BOSSBUL; i = i + 4)
		{
			if (BossBul[i].live == 1)
			{
				BossBul[i].live = 2;
				BossBul[i + 1].live = 2;
				BossBul[i + 2].live = 2;
				BossBul[i + 3].live = 2;
				BossBul[i].y = boss[s].y + 100;//当前boss[s].y=50，所以加上100才是飞机的顶端
				BossBul[i + 1].y = boss[s].y + 100;//将最新的飞机坐标给子弹
				BossBul[i + 2].y = boss[s].y + 100;
				BossBul[i + 3].y = boss[s].y + 100;
				BossBul[i].x = boss[s].x + 60;
				BossBul[i + 1].x = boss[s].x + 80;
				BossBul[i + 2].x = boss[s].x + 100;
				BossBul[i + 3].x = boss[s].x + 120;
				break;
			}
		}
	}
	//创建炮弹
	if (rand() % 10 < 1 && shell.live == 0 && num_death_enemy >= 10)
	{
		shell.live = 1;
		shell.shot = 0;
		shell.y = -150;//防止在出现危险警告时，导弹在屏幕上未显示，但存在，使飞机碰到死亡
	}
}
//产生敌机
void createEnemy()
{
	if (num_death_enemy >= score)//boss出现
	{
		for (int i = 0; i < NUM; i++)//将所有敌军变为0；
		{
			if (enemyPlan[i].live == 1)
			{
				enemyPlan[i].live = 0;
			}
		}
	}
	else
	{
		for (int i = 0; i < NUM; i++)
		{	//第一个敌机一定能产生出来
			if (enemyPlan[0].live == 0)
			{
				enemyPlan[0].live = 1;//将敌机创造出来
				enemyPlan[0].x = rand() % (WIDTH - 70);//x位置随机在0-530、width=600
				enemyPlan[0].y = 0;
				enemyPlan[0].HP = 1;
				enemyPlan[0].type = 1;
				break;
			}//当第一个敌机存在时，开始判断下一个敌机												
			else if (enemyPlan[i + 1].live == 0 && (i + 1) < NUM && (rand() % 10 < 7))//(i+1)<NUM不让行索超过最大值,当下一个没有产生敌军时，就结束循环												
			{
				if (rand() % 10 < 4)//创造成功的概率只创建一个敌机，种类一
				{
					enemyPlan[i + 1].live = 1;//将敌机创造出来
					enemyPlan[i + 1].x = rand() % (WIDTH - 70);
					enemyPlan[i + 1].y = 0;
					enemyPlan[i + 1].HP = 1;
					enemyPlan[i + 1].type = 1;
					break;
				}
				else if (rand() % 10 < 2)//敌机种类二
				{
					enemyPlan[i + 1].live = 1;//将敌机创造出来
					enemyPlan[i + 1].x = rand() % (WIDTH - 70);//x坐标
					enemyPlan[i + 1].y = 0;
					enemyPlan[i + 1].HP = 5;
					enemyPlan[i + 1].type = 2;
					break;
				}
				else if (rand() % 10 < 5)//第三种敌机
				{
					enemyPlan[i + 1].live = 1;//将敌机创造出来
					enemyPlan[i + 1].x = rand() % (WIDTH - 70);//x坐标
					enemyPlan[i + 1].y = 0;
					enemyPlan[i + 1].HP = 3;
					enemyPlan[i + 1].type = 3;
					break;
				}
				break;
			}
		}
	}
}
void enemyMove(int speed)
{
	//boss的移动
	if (num_death_enemy >= score)
	{	//进行自由的左右来回移动。先想右移动一段距离，再向左移动同样的距离实现，来回移动
		if (boss[s].y < 50)
		{
			boss[s].y += 2;
		}
		if (m > 0 && m <= 160)//m代表移动的次数，向左移动
		{
			boss[s].x += 2;
			m--;
		}
		if (m <= 0)//向右移动。
		{
			boss[s].x -= 2;
			m--;
			if (m == -160)//当移动了与左移动相同的距离，再变回右移动的条件
				m = 160;
		}
	}
	else
	{
		for (int i = 0; i < NUM; i++)
		{
			if (enemyPlan[i].live == 1)//遍历数组，寻找存活的敌军
			{
				if (enemyPlan[i].type == 1) //判断类型，改变不同的速度
				{
					enemyPlan[i].y += speed;	//只需要垂直移动
				}
				else if (enemyPlan[i].type == 2)
				{
					enemyPlan[i].y += speed + 2;
				}
				else if (enemyPlan[i].type == 3)
				{
					enemyPlan[i].y += speed + 1;
				}
				if (enemyPlan[i].y > HEIGHT)//当敌机超过地图时，将live变为0,在创造时，就可以继续使用
				{
					enemyPlan[i].live = 0;
					enemyPlan[i].shot = 'N';//是否发射子弹
				}
			}
		}
	}
}
//子弹发射原理，定义数组，给数组的第一个开始赋予子弹，每按一次，给一颗。通过判定数组是否有子弹进行移动，每个子弹的位置都不一样

void bulletMove(int speed)//speed为子弹的移动速度  
{
	for (int i = 0; i < N; i++)//我方子弹移动
	{
		if (bullet[i].live == 1)//子弹存在  一次只有一个子弹有，只移动一次
		{
			bullet[i].y -= speed;//子弹坐标的移动
			if (bullet[i].y <= 0)//当子弹超出范围时又将其值设置为0,补充我军子弹
			{
				bullet[i].live = 0;
			}
		}
		if (developBul[i].live == 1)//副武器
		{
			developBul[i].y -= 8;
			if (developBul[i].y <= 0)//超出屏幕回收
			{
				developBul[i].live = 0;

			}
		}
	}
	if (num_death_enemy < score)//boss未出现
	{
		//敌军子弹的移动，每次移动10个像素
		for (int i = 0; i < N; i++)
		{
			if (enemyBult[i].live == 1)
			{
				enemyBult[i].y += 10;
			}
		}
	}

	//boss子弹的移动
	for (int i = 0; i < BOSSBUL; i++)
	{
		if (BossBul[i].live == 2)
		{
			BossBul[i].y += 7;
		}
		if (BossBul[i].y > HEIGHT)//超过屏幕将子弹回收
		{
			BossBul[i].live = 1;
		}
	}
	//当飞机吃到图标时
	if (ico[0].live == 1)
	{
		if ((minePlan.kind == 1 && ico[0].x - minePlan.x > -20 && ico[0].x - minePlan.x < 40 && ico[0].y - minePlan.y<25 && ico[0].y - minePlan.y>-40)
			|| (minePlan.kind == 2 && ico[0].y > minePlan.y + 20 && ico[0].y < minePlan.y + 50 && ico[0].x<minePlan.x + 60 && ico[0].x > minePlan.x))
		{
			//当飞机1号吃到图标，图标消失，飞机子弹增加副武器
			ico[0].live = 0;
			minePlan.type = 2;
		}
	}
	//图标的移动
	if (ico[0].live == 1)
	{
		ico[0].x += speedx;//移动慢一点
		ico[0].y += speedy;//移动慢一点
		if (ico[0].x <= 0 || ico[0].x >= 570)
			speedx = -speedx;
		if (ico[0].y >= 670 || ico[0].y <= 0)
			speedy = -speedy;
	}
	//炮弹移动
	if (shell.live == 1 && shell.shot == 1)//存在且发射出去才移动
	{
		shell.y += 15;
		if (shell.y > 700)
		{
			shell.live = 0;
			shell.shot = 0;
			shell.y = -150;
		}
	}
}
int minePlayDeath()
{
	mciSendString("pause mymusic", NULL, 0, NULL);//暂停背景音乐
	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)BOOM, NULL, NULL, 0);//播放爆炸
	mciSendString("close death ", NULL, 0, NULL);//死亡音效
	mciSendString("open 死亡.mp3 alias death", NULL, 0, NULL);
	mciSendString("play death ", NULL, 0, NULL);
	minePlan.live = 0;//飞机死亡
	for (int i = 0; i < 4; i++)//通过二维数组来实现爆炸效果
	{
		for (int j = 0; j < 4; j++)
		{
			drowGame();
			putimage(minePlan.x, minePlan.y, 64, 64, &boom2yanma[1], j * 64, i * 64, NOTSRCERASE);
			putimage(minePlan.x, minePlan.y, 64, 64, &boom2[1], j * 64, i * 64, SRCINVERT);
			FlushBatchDraw();
			Sleep(100);
		}
	}
	putimage(126, 312, &relive, SRCPAINT);
	FlushBatchDraw();
	system("pause");
	while (1)//选择死亡后是否复活
	{
		if (_getch() == 'x')//按下键复活
		{
			mciSendString("resume mymusic", NULL, 0, NULL);
			minePlan.x = WIDTH / 2;
			minePlan.y = 500;
			minePlan.live = 1;
			condition = 1;
			return 1;
		}
		else
		{
			minePlan.live = 0;
			return 0;
		}
	}
	//return 0;
}
int bossDeath()
{
	boss[s].live = 0;
	for (int i = 0; i < BOSSBUL; i++)
	{
		BossBul[i].live = 0;
	}
	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//关闭子弹音效
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)BOOM, NULL, NULL, 0);//播放爆炸
	mciSendString("close victory ", NULL, 0, NULL);				//胜利音效
	mciSendString("open 胜利.mp3 alias victory", NULL, 0, NULL);
	mciSendString("play victory ", NULL, 0, NULL);
	for (int i = 0; i < 4; i++)//通过二维数组来实现爆炸效果
	{
		for (int j = 0; j < 4; j++)
		{
			drowGame();//刷新地图中的其他图片
			putimage(boss[s].x, boss[s].y, 150, 150, &boom2yanma[0], j * 150, i * 150, NOTSRCERASE);
			putimage(boss[s].x, boss[s].y, 150, 150, &boom2[0], j * 150, i * 150, SRCINVERT);
			FlushBatchDraw();
			Sleep(150);
		}
	}
	return 0;
}
void Score(int i)
{
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)BOOM, NULL, NULL, 0);//敌机爆炸音效线程
	enemy_x = enemyPlan[i].x;//记录敌机爆炸的位置，给敌机爆炸效果定位
	enemy_y = enemyPlan[i].y;
	enemyPlan[i].shot = 'N';
	enemyPlan[i].live = 0;//敌人死亡
	num_death_enemy++;//统计死亡敌机数
	if (enemyPlan[i].type == 1)//判断敌机类型增加分数
		minePlan.score += 10;
	else if (enemyPlan[i].type == 2)
		minePlan.score += 30;
	else if (enemyPlan[i].type == 3)
		minePlan.score += 20;
}
int deadth()//判断死亡
{
	if (num_death_enemy >= score)//boss出现
	{
		//打中boss的判断
		for (int i = 0; i < N; i++)
		{
			if (bullet[i].live == 1)//表示已发射的子弹
			{
				if (bullet[i].x - boss[s].x > 0 && bullet[i].x - boss[s].x < 170 && bullet[i].y - boss[s].y < 130 && bullet[i].y - boss[s].y>5)
				{
					bullet[i].live = 0;
					boss[s].HP -= 1;
					BloodWidth -= 3;//boss血量条图片的宽度减少
					if (boss[s].HP <= 0)//boss血量为小于0时
					{
						return bossDeath();
					}
				}
			}
			//副武器判断
			if (developBul[i].live == 1)
			{
				if (developBul[i].x - boss[s].x > 50 && developBul[i].x - boss[s].x < 170 && developBul[i].y - boss[s].y < 130 && developBul[i].y - boss[s].y>5)
				{
					boss[s].HP -= 2;
					BloodWidth -= 6;
					developBul[i].live = 0;
					if (boss[s].HP <= 0)//boss血量为0时
						return bossDeath();
				}
			}
		}
		//boss子弹击中我方
		if (condition != 1)//为1飞机处于无敌状态
		{
			for (int i = 0; i < BOSSBUL; i++)
			{
				if (BossBul[i].live == 2)//已发射的子弹
				{
					if ((minePlan.kind == 1 && BossBul[i].x - minePlan.x > -5 && BossBul[i].x - minePlan.x < 45 && BossBul[i].y - minePlan.y>5 && BossBul[i].y - minePlan.y < 50)
						|| (minePlan.kind == 2 && BossBul[i].x - minePlan.x > -5 && BossBul[i].x - minePlan.x < 65 && BossBul[i].y - minePlan.y>15 && BossBul[i].y - minePlan.y < 70))//被boss子弹击中
					{

						return minePlayDeath();
					}
				}
			}
		}
		//我方与boss碰撞
		if ((minePlan.kind == 1 && boss[s].x < minePlan.x - 20 && boss[s].x + 200 > minePlan.x - 50 && boss[s].y + 100 > minePlan.y && boss[s].y + 20 < minePlan.y)
			|| (minePlan.kind == 2 && boss[s].x < minePlan.x - 30 && boss[s].x + 200 > minePlan.x - 50 && boss[s].y + 100 > minePlan.y&& boss[s].y + 20 < minePlan.y))//被boss子弹击中)
		{
			return minePlayDeath();
		}
	}
	else//boss未出现
	{
		for (int i = 0; i < NUM; i++)
		{
			if (enemyPlan[i].live == 1)//寻找存活的敌机
			{
				for (int j = 0; j < N; j++)//遍历子弹，判断子弹是否命中该存活敌机
				{	//子弹击中敌机，子弹归0，PH=0敌机死亡；
					if (bullet[j].live == 1)//若果子弹已发射
					{
						if (bullet[j].x - enemyPlan[i].x > -15 && bullet[j].x - enemyPlan[i].x < 40 && bullet[j].y - enemyPlan[i].y < 45 && bullet[j].y - enemyPlan[i].y>5)
						{
							enemyPlan[i].HP = enemyPlan[i].HP - 1;
							bullet[j].live = 0;
							if (enemyPlan[i].HP <= 0)
							{
								Score(i);//播放敌机爆炸音效并记录分数
							}
						}
					}
				}
				for (int j = 0; j < N; j++)//副武器打中敌机
				{
					if (developBul[j].live == 1)//已发射的子弹
					{
						if (developBul[j].x - enemyPlan[i].x > -5 && developBul[j].x - enemyPlan[i].x < 45 && developBul[j].y - enemyPlan[i].y>5 && developBul[j].y - enemyPlan[i].y < 45)//被boss子弹击中
						{
							enemyPlan[i].HP = enemyPlan[i].HP - 2;
							developBul[j].live = 0;
							if (enemyPlan[i].HP <= 0)
							{
								Score(i);
							}
						}
					}
				}

				if (condition != 1)
				{		//当己方飞机碰到敌方飞机时死亡
					if ((minePlan.kind == 1 && abs(minePlan.x - enemyPlan[i].x) < 40 && abs(minePlan.y - enemyPlan[i].y) < 40)
						|| (minePlan.kind == 2 && enemyPlan[i].y > minePlan.y&& enemyPlan[i].y < minePlan.y + 60 && enemyPlan[i].x > minePlan.x - 20 && enemyPlan[i].x < minePlan.x + 65))//abs取整数绝对值
					{
						//outtextxy(minePlan.x, minePlan.y, "双击x复活，按z结束游戏")
						return minePlayDeath();

					}
				}

			}

		}

		//我方被敌方子弹击中死亡
		if (condition != 1)
		{
			for (int i = 0; i < N; i++)//遍历敌方子弹判断是否存活
			{
				if (enemyBult[i].live == 1)
				{
					if ((minePlan.kind == 1 && enemyBult[i].x - minePlan.x > 5 && enemyBult[i].x - minePlan.x < 30 && enemyBult[i].y - minePlan.y>5 && enemyBult[i].y < minePlan.y + 40)
						|| (minePlan.kind == 2 && enemyBult[i].x - minePlan.x > -5 && enemyBult[i].x - minePlan.x < 65 && enemyBult[i].y - minePlan.y>15 && enemyBult[i].y - minePlan.y < 70))
					{//子弹击中我方时
						//enemyBult[i].live = 0;
						//enemyBult[i].y = -50;
						return  minePlayDeath();
					}
				}
			}

		}
	}
	if (time[0] < 5000 && time[0] >= 0)//技能正在释放的时候
	{
		for (int i = 0; i < NUM; i++)//判断敌机是否有存活的
		{
			if (enemyPlan[i].live == 1)
			{
				if (minePlan.x - enemyPlan[i].x < 40 && minePlan.x - enemyPlan[i].x > -50 && minePlan.y > enemyPlan[i].y)//技能击中敌机
				{
					enemyPlan[i].HP -= 3;//血量减三
					if (enemyPlan[i].HP <= 0)
					{
						Score(i);
					}
				}
			}
		}
		if (num_death_enemy >= score)
		{
			if (minePlan.x - boss[s].x < 175 && minePlan.x - boss[s].x > -75 && minePlan.y > boss[s].y)//技能击中敌机
			{
				boss[s].HP -= 1;
				BloodWidth -= 3;//boss血量条图片的宽度减少
				if (boss[s].HP <= 0)//boss血量为0时
				{
					return bossDeath();
				}
			}
		}
	}
	if (num_death_enemy == fen)//当敌机死亡数达到指定时 //调用产生图标的函数
	{
		up();
		fen -= 1;//若果不减，并且敌机死亡数不增加，则图标不会移动
	}
	//炮弹撞上飞机
	if (condition != 1)
	{
		if ((minePlan.kind == 1 && shell.x > minePlan.x - 50 && shell.x<minePlan.x + 30 && shell.y>minePlan.y - 110 && shell.y < minePlan.y + 20)
			|| (minePlan.kind == 2 && shell.x > minePlan.x - 50 && shell.x<minePlan.x + 45 && shell.y > minePlan.y - 110 && shell.y < minePlan.y + 60))
		{
			return  minePlayDeath();
		}
	}
	return 1;
}
char GameOver()//游戏结束后
{
	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//停止子弹音乐
	mciSendString("pause mymusic", NULL, 0, NULL);//停止背景音乐
	count = 0;//数组下标初始化为零
	putimage(0, 0, &map[2]);//打印图片
	img_x = 210;
	img_y = 275;
	OutScore(minePlan.score);//输出分数
	img_x = 210;
	img_y = 155;
	OutScore(num_death_enemy);//输出击杀数量
	FlushBatchDraw();
	MOUSEMSG end_mouse;
	while (1)
	{
		end_mouse = GetMouseMsg();
		if (end_mouse.uMsg == WM_LBUTTONDOWN)//左键点下
		{
			if (end_mouse.x > 146 && end_mouse.x < 435 && end_mouse.y < 626 && end_mouse.y>550)//返回主菜单
			{
				return 'D';
			}
			if (end_mouse.x > 146 && end_mouse.x < 435 && end_mouse.y < 466 && end_mouse.y>390)//重新开始游戏
			{
				return 'R';
			}
		}
	}
	return 0;
}
int timeout()//暂停
{
	//putimage(140, 165, &cue[0]);
	putimage(0, 0, &cue[0]);
	FlushBatchDraw();
	mciSendString("pause mymusic", NULL, 0, NULL);//暂停背景音乐
	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//暂停子弹音效
	MOUSEMSG n;//定义鼠标变量
	while (1)
	{
		while (MouseHit())
		{
			n = GetMouseMsg();
			if (n.uMsg == WM_LBUTTONDOWN)
			{
				if (n.x > 190 && n.x < 410 && n.y> 243 && n.y < 320)//点击继续
				{
					mciSendString("resume mymusic", NULL, 0, NULL);
					return 0;
				}
				else if (n.x > 190 && n.x < 410 && n.y> 400 && n.y < 481)//点击退出,返回主菜单
				{
					return 1;
				}
			}
		}
	}
}
//保存游戏数据，保存数据并退出
void DataConserve()
{
	FILE* fp1;
	FILE* fp;//定义文件指针
	char str[10];
	int num_str;
	if ((fp1 = fopen("GameData\\data.text", "r")) == NULL);
	else
	{
		fgets(str, 9, fp1);//获取历史记录
		num_str = atoi(str);//将字符串转为整型
	}
	fclose(fp1);
	if ((fp = fopen("GameData\\data.text", "w+")) == NULL)//打开或创建文件失败时，fopen会返回NULL，成功则返回文件的首地址
	{
		exit(1);//退出程序
	}
	_itoa_s(minePlan.score > num_str ? minePlan.score : num_str, str, 10);//后面的10是装换的进制数，不能跨平台，跨平台需使用sprintf_s();
	fputs(str, fp);//将数据保存
	fclose(fp);//关闭文件指针
}
void OutScore(int number)//在指定地方输出数字图片
{
	if (number / 10 != 0)//不是个位数
	{
		OutScore(number / 10);
		Num[count++] = number % 10;
	}
	else//是各位数，每次输出只会执行一次，开始为个位数或者分解到最后运行一次，
	{
		Num[count++] = number;
	}
	putimage(img_x, img_y, 17, 22, &shuziyama[0], Num[count - 1] * 17, 0, NOTSRCERASE);
	putimage(img_x, img_y, 17, 22, &shuzi[0], Num[count - 1] * 17, 0, SRCINVERT);
	img_x += 17;//改变图片的x坐标
}
//画出游戏图片
void drowGame()
{
	putimage(0, 0, &map1);//打印出地图
	//putimage(0, 0, 600, 700, &map[3], 0, px[0]++);//动态地图
	//if (px[0] >= 440)
		// = 0;
	//putimage(0, 700 - (px[0] - 400), 600, 700, &map[3], 0, 0);
	if (minePlan.kind == 1 && minePlan.live == 1)//判断飞机类型打印相应的图片
	{
		putimage(minePlan.x, minePlan.y, &minebit[0], NOTSRCERASE);
		putimage(minePlan.x, minePlan.y, &mine[0], SRCINVERT);
	}
	else if (minePlan.kind == 2 && minePlan.live == 1)
	{
		if (GetKeyState(VK_LEFT) < 0)//判断移动的方向打印图片
			my_2 = 3;
		else if (GetKeyState(VK_RIGHT) < 0)
			my_2 = 1;
		else
			my_2 = 2;
		showMyPlan(minePlan.x, minePlan.y);//飞机2号
	}

	//打印子弹
	if (time[0] >= 5000 || time[0] == -1)//当技能释放完打印子弹,或者未释放技能时
	{
		if (time[1] >= 1500 || time[1] == 0)//
		{
			for (int i = 0; i < N; i++)
			{
				if (bullet[i].live == 1)
				{
					putimage(bullet[i].x, bullet[i].y, &zidan, SRCPAINT);
				}
			}
		}
	}

	//打印分数
	//char k[15];
	//_itoa_s(minePlan.score, k, 10);//将数字转为字符串
	//outtextxy(400, 50, k );//打印int类型有问题，打印字符串没问题
	count = 0;
	img_x = 456;
	img_y = 20;
	OutScore(minePlan.score);
	if (num_death_enemy >= score && boss[s].live == 1)//打印boss,和boss子弹
	{
		//BloodWidth = BloodWidth + 20;
		putimage(boss[s].x, boss[s].y, &enemy[5], NOTSRCERASE);
		putimage(boss[s].x, boss[s].y, &enemy[4], SRCINVERT);
		for (int i = 0; i < BOSSBUL; i++)
		{
			if (BossBul[i].live == 2)
			{
				putimage(BossBul[i].x, BossBul[i].y, &enemybul, SRCPAINT);
				putimage(BossBul[i].x, BossBul[i].y, &enemybul, SRCPAINT);
				putimage(BossBul[i].x, BossBul[i].y, &enemybul, SRCPAINT);
				putimage(BossBul[i].x, BossBul[i].y, &enemybul, SRCPAINT);
			}
		}
		putimage(-10, 20, &blood[0], SRCPAINT);
		putimage(BloodWidth, 20, &blood[1], SRCPAINT);

	}
	else
	{
		//打印敌机
		for (int i = 0; i < NUM; i++)
		{//遍历敌机数组，判断哪些为存活就输出
			if (enemyPlan[i].live == 1)
			{
				if (enemyPlan[i].type == 1)
				{
					putimage(enemyPlan[i].x, enemyPlan[i].y, &enemy[0], NOTSRCERASE);//掩码图
					putimage(enemyPlan[i].x, enemyPlan[i].y, &enemy[1], SRCINVERT);
				}
				else if (enemyPlan[i].type == 2)
				{
					putimage(enemyPlan[i].x, enemyPlan[i].y, &enemy[3], NOTSRCERASE);;//掩码图
					putimage(enemyPlan[i].x, enemyPlan[i].y, &enemy[2], SRCINVERT);
				}
				else if (enemyPlan[i].type == 3)
				{
					showEnemy2(enemyPlan[i].x, enemyPlan[i].y);
					time[4] += 20;
					if (time[4] > 100)
					{
						ene_2 += 1;
						time[4] = 0;
					}
					if (ene_2 >= 5)
						ene_2 = 0;
				}
			}
		}
		//打印敌机子弹
		int num = 0;
		for (int i = 0; i < N; i++)
		{//子弹发射后，live值变为1；表示以发射
			if (enemyBult[i].live == 1)
			{
				putimage(enemyBult[i].x, enemyBult[i].y, &enemybul, SRCPAINT);
			}
		}
	}
	//time[0]用于计算技能释放的时间，time[1]用于计算道具冷却的时间，show用于判断道具是否使用及显示
	//技能释放动画
	if (time[0] < 5000 && time[0] >= 0)//按下技能键，释放技能的时间5秒
	{
		if (t7 - t8 > 50)//多久切换一张图片
		{
			t8 = t7;//t7为当前最新的时间
			jj++;
			if (jj >= 6)//当图片输完时,变成第一张循环绘制
			{
				jj = 0;
			}
		}
		t7 = GetTickCount();
		if (minePlan.kind == 1)//判断飞机的种类，计算技能释放的位置
		{
			putimage(minePlan.x - 7, minePlan.y - 700, &waryanma[0], NOTSRCERASE);
			putimage(minePlan.x - 7, minePlan.y - 700, &war[jj], SRCINVERT);
		}
		else
		{
			putimage(minePlan.x + 8, minePlan.y - 700, &waryanma[0], NOTSRCERASE);
			putimage(minePlan.x + 8, minePlan.y - 700, &war[jj], SRCINVERT);
		}
		FlushBatchDraw();
		time[0] += 20;//计算技能释放的时间；
		time[1] += 20;//计算技能能却的时间
	}
	else if (time[0] >= 5000 && time[0] < 15000)//技能冷却的时间10秒
	{
		time[1] += 20;//计算恢复的时间
	}
	if (time[1] > 15000)//技能冷却完成
	{
		time[1] = 0;
		time[0] = -1;
		show = 1;
	}
	if (show == 1)//展示技能图标
	{
		putimage(10, 500, &jineng[0], SRCPAINT);
	}
	//武器升级1
	for (int i = 0; i < N; i++)
	{
		if (developBul[i].live == 1)//子弹存在才发射
		{
			putimage(developBul[i].x, developBul[i].y, &img_developBul[0], NOTSRCERASE);//掩码
			putimage(developBul[i].x, developBul[i].y, &img_developBul[1], SRCINVERT);
		}
	}

	//敌机爆炸效果动画
	if (enemy_x >= 0)
	{
		putimage(enemy_x, enemy_y, &boomyanma[x], NOTSRCERASE);
		putimage(enemy_x, enemy_y, &boom[x], SRCINVERT);
	}
	//控制图片切换的时间
	if (t5 - t6 > 50)
	{
		t6 = t5;
		x++;
		if (x >= 11)//到最后一张后循环
		{
			x = 7;
			enemy_x = -1;//初始坐标为负值
			enemy_x = -1;
		}
	}
	t5 = GetTickCount();

	//显示升级图标
	if (ico[0].live == 1)
	{
		putimage(ico[0].x, ico[0].y, &tubiao[2], NOTSRCERASE);
		putimage(ico[0].x, ico[0].y, &tubiao[3], SRCINVERT);
	}
	//画出危险图标
	if (shell.live == 1 && shell.shot == 0)
	{
		putimage(minePlan.x, 0, &tubiao[6], NOTSRCERASE);
		putimage(minePlan.x, 0, &tubiao[7], SRCINVERT);
		time[5] += 20;
		if (time[5] >= 2000)//控制危险图标持续的时间
		{
			time[5] = 0;
			shell.shot = 1;
			shell.x = minePlan.x;
		}
	}
	//画出炸弹
	if (shell.shot == 1)//判断导弹是否发射
	{
		putimage(shell.x, shell.y, &bomb[1], NOTSRCERASE);
		putimage(shell.x, shell.y, &bomb[0], SRCINVERT);
	}
	//打印护盾
	if (condition == 1)
	{
		if (minePlan.kind == 1)
			putimage(minePlan.x - 20, minePlan.y - 20, &hudun, SRCPAINT);
		else if (minePlan.kind == 2)
			putimage(minePlan.x - 7, minePlan.y, &hudun, SRCPAINT);
		time[6] += 20;
		if (time[6] > 5000)
		{
			condition = 0;
			time[6] = 0;
		}
	}
}
int keyDown(IMAGE* map1, int speed)//操作按键判断
{
	//a = GetKeyState(VK_UP);//该函数通过获取虚键来判断键盘是否按下
	srand(GetTickCount());//随机数种子
	if (GetKeyState(VK_UP) < 0 && minePlan.y > 0)//minePlan.y>0，限制飞机的移动范围
	{
		minePlan.y -= speed;
	}
	else if (GetKeyState(VK_LEFT) < 0 && minePlan.x > -15)
	{
		minePlan.x -= speed;
	}
	else if (GetKeyState(VK_RIGHT) < 0 && minePlan.x < WIDTH - 36)
	{
		minePlan.x += speed;
	}
	else if (GetKeyState(VK_DOWN) < 0 && minePlan.y < HEIGHT - 50)
	{
		minePlan.y += speed;
	}
	else if (GetKeyState(VK_ESCAPE) < 0)
	{
		return 1;
	}
	else if (GetKeyState(VK_SPACE) < 0)
	{
		return 2;
	}
	else if (GetKeyState('H') < 0 && show == 1)//按下H键释放技能
	{
		show = 0;//表示技能使用了，技能图标不再显示
		time[0] = 0;
	}
	if ((t4 - t3) > (rand() % 500 + 800))//控制敌机产生的时间 间隔
	{
		createEnemy();
		t3 = t4;
	}
	t4 = GetTickCount();
	enemyMove(3);//敌机的产生和移动，同样每次只产生一个通过循环使用移动函数，实现移动
	if (t2 - t1 > 200)//后面为判定多久时间发射一枚子弹获取当前系统的运行时间GetKeyState(VK_CONTROL) < 0
	{
		t1 = t2;
		createbullet();//当按下攻击键时，给子弹填充一个，下面的bulletMove()函数才会有效果
		//播放子弹发射的音效，播放之后需要关掉，才能重新播放
		//mciSendString("close gun", 0, 0, 0);
		//mciSendString("open ./Beam.wav alias gun", 0, 0, 0);
		//mciSendString("play gun", 0, 0, 0);
		//time[3] += 20;
		if (time[0] >= 5000 || time[0] == -1)
		{
			PlaySound(TEXT("Beam.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		}
		else//当释放技能时不播放子弹的声音
		{
			PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC | SND_PURGE);
			PlaySound(TEXT("baozou.wav"), NULL, SND_FILENAME | SND_ASYNC);
			//PlaySound(TEXT("laser shot.mp3"), NULL, SND_FILENAME | SND_ASYNC);
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)tttt, NULL, NULL, 0);//调用线程，被其他什么东西占用了，暂停时可以播放完整的
		}
	}
	t2 = GetTickCount();
	bulletMove(10); //发射子弹 //重复执行该函数
	if (deadth() == 0)
		return 3;
	return 0;
}