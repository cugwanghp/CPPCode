/*
成绩管理系统
需求：模拟成绩信息管理系统，在控制台模拟成绩信息的菜单，完成相应的指令
A - Add a score 添加一个成绩
D - Del a score  删除一个成绩
L - List All scores and count 列出所有成绩
M - Minimum of scores 成绩最小值及索引
N - Average of scores    成绩均值
P - Maximum of scores  成绩最大值及索引
T - Standard derivation of scores 成绩标准方差
S - Save scores to file 保存成绩到文件 (选做）
O - Open scores from file 从文件加载成绩（选做）
X - Exit 退出程序
提示：成绩用数组存放，每个功能用函数实现。
*/

#include"management.h"
//#include <string>

int main()
{
	char cmd;
	int index;
	Scorebook	scbook;
	score		s;
	do
	{
		cin >> cmd;
		switch (cmd)
		{
		case'A':case'a':
			cin >> s.m_index >> s.m_score;
			if(scbook.add(s))
			{
				cout << "add finished."<<endl;
			}
			break;
		case'D':case'd':
			cin >> index;
			if (scbook.del(index))
			{
				cout << "delete finished."<<endl;
			}
			break;
		case'L':case'l':
			scbook.list();
			break;
		case'M':case'm':
			scbook.min();
			break;
		case'P':case'p':
			scbook.max();
			break;
		case'N':case'n':
			scbook.averageScore();
			break;
		case'T':case't':
			scbook.StadScore();
			break;
		default:
			break;
		}

	} while (cmd != 'X' && cmd != 'x');
	return 0;
}