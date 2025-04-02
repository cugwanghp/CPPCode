#include "calculator.h"
#include <string>
#include <sstream>
using namespace std;

//运算表达式的结果
int calculator::run(const string& strExpr)
{
	if (parse(strExpr))
	{
		// 计算表达式的值
		return calc();
	}

	return 0;
}

//解析表达式，分离操作符和操作数
bool calculator::parse(const string& strExpr)
{
	istringstream   iss(strExpr);

	m_szNumCount = m_szOperCount = 0;

	iss >> m_num[m_szNumCount++];    //先读入1个操作数
	while (iss.rdbuf()->in_avail() > 0)
	{
		iss >> m_oper[m_szOperCount]; //再读入1个操作符
		if (m_oper[m_szOperCount++] == '!') // ! 是单目操作符，跳过第2个操作数
			continue;
		iss >> m_num[m_szNumCount++];  //读入第2个操作数
	}

	return true;  // 以字符流的状态标识表达式是否合法?? 未实现
}

// 遍历操作符数组，取出一个优先级最大的操作符
// 找到该操作符对应的操作数在操作数数组中的位置
// 计算当前操作符的计算结果
// 将该操作符的操作数用计算结果覆盖，并将操作符从操作符数组中删除
// 遍历循环，直到操作符的个数为0
// 返回最后的结果
int calculator::calc()
{
	while (m_szOperCount > 0)
	{
		// 1. 优先级最高的运算符
		int		nIdxPriority = getMaxPriorityOperIndex();

		// 2. 优先级高的运算符所对应的操作数位置
		int	nPosNum = 0;
		for (int i = 0; i < nIdxPriority; ++i)
		{
			nPosNum += m_oper[i] != '!' ? 1 : 0;
		}

		// 3. 计算表达式，单目和双目分开
		if (m_oper[nIdxPriority] != '!')	//双目运算符，删除一个操作数
		{
			m_num[nPosNum] = calcExpr(m_oper[nIdxPriority], m_num[nPosNum], m_num[nPosNum + 1]);
			for (int i = nPosNum+1; i < m_szNumCount - 1; ++i)
			{
				m_num[i] = m_num[i + 1];
			}
			--m_szNumCount;	//操作数-1
		}
		else  //单目运算符，替换已有位置的操作数
		{
			m_num[nPosNum] = calcExpr(m_oper[nIdxPriority], m_num[nPosNum]);
		}
		
		// 删除当前计算后的操作符，操作符个数-1
		for (int i = nIdxPriority; i < m_szOperCount - 1; ++i)
		{
			m_oper[i] = m_oper[i + 1];
		}
		--m_szOperCount;
	}

	return m_num[0];
}

// 获取优先级最高的操作符数组
int calculator::getMaxPriorityOperIndex() const
{
	int		nIdxMaxPriority = 0;
	for (int i = 1; i < m_szOperCount; ++i)
	{
		if (getOperPriority(m_oper[i]) > getOperPriority(m_oper[nIdxMaxPriority]))
		{
			nIdxMaxPriority = i;
		}
	}

	return nIdxMaxPriority;
}

//返回操作数的优先级
int calculator::getOperPriority(char oper)
{
	switch (oper)
	{
	case '+': case '-':	return 1;
	case '*': case '/':	return 2;
	case '^': return 3;
	case '!': return 4;
	default:	return 0;
	}
}

// 表达式计算
int calculator::calcExpr(char oper, int n1, int n2)
{
	switch (oper)
	{
	case '+': return n1 + n2;
	case '-': return n1 - n2;
	case '*': return n1 * n2;
	case '/': return n1 / n2;
	case '^': return n1 ^ n2;
	case '!': return fact(n1);
	default:  return 0;
	}
}

// 阶乘计算
int calculator::fact(int n)	//n!
{
	int	res = 1;
	for (int i = 2; i < n + 1; ++i)
	{
		res *= i;
	}
	return res;
}