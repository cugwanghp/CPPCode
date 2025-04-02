# simple calculator

## 需求分析

> 输入计算表达式，支持 +-*/^! 的运算符，暂不支持()。

- 需要注意的几点：
  - 运算符的优先级
  - 单目运算符(!)和双目运算符(+-*/^)的区别

- 关键步骤：
  - 解析表达式，将表达式拆分为两个数组，分别存放 操作数 和 操作符
  - 运算符优先级的比较，每次从操作符数组中选择优先级最大的运算符先运算
  - 某个操作符对应的操作数，完成中间计算
  - 用新计算的值替换已有操作数的位置

## 流程图

主要步骤如下：

- 解析表达式到操作数和操作符数组
- 遍历操作符数组，取出一个优先级最大的操作符
- 找到该操作符对应的操作数在操作数数组中的位置
- 计算当前操作符的计算结果 
- 将该操作符的操作数用计算结果覆盖，并将操作符从操作符数组中删除
- 遍历循环，直到操作符的个数为0
- 返回最后的结果

```flow
beg=>start: 开始
end=>end: 结束
expr=>inputoutput: 输入表达式
parse=>operation: 解析表达式
oper_num=>inputoutput: 操作数和操作符数组
is_oper_empty=>condition: 操作符数组是否为空
op_maxpriority=>operation: 取出优先级最高的操作符
op_get_operand=>operation: 取出某个操作符的操作数
op_calc_expr=>operation: 计算单个表达式值
op_update_oper_num=>operation: 更新操作数和操作符数组
output_res=>inputoutput: 操作数最后一个值即为结果
beg(right)->expr(right)->parse->oper_num->is_oper_empty
is_oper_empty(no,left)->op_maxpriority->op_get_operand->op_calc_expr->op_update_oper_num(left)->is_oper_empty
is_oper_empty(yes)->output_res->end
```



## 类的设计

### 数据成员

- 操作符数组+存储个数
- 操作数数组+存储个数

### 函数声明

- 解析表达式
- 计算表达式
  - 获取最大优先级的操作符
  - 获取指定操作符的操作数，返回其在操作数数组中的位置
  - 计算单个表达式
  - 更新操作符数组和操作数数组

### 类的声明

```c++
#pragma once

#include <string>
using namespace std;

class calculator
{
public:
	int run(const string& strExpr);     //运算表达式的结果

private:
	bool parse(const string& strExpr);    //解析表达式，分离操作符和操作数
	int calc(); //计算表达式的值
	int getMaxPriorityOperIndex() const;	//优先级最高的操作符索引
    
	// 与表达式运算相关的函数
	static int getOperPriority(char oper);	//返回操作数的优先级
	static int calcExpr(char oper, int n1, int n2 = 0);	//计算表达式的值
	static int fact(int n);	//n!
	
	constexpr static size_t MAX_LEN = 100;	//数组分配的长度
	int m_num[MAX_LEN] = {}; // 目前只学到数组，100个操作数数组
	size_t m_szNumCount = 0;	// 表达式中操作数的个数
	char m_oper[MAX_LEN] = {};   //100个操作符的数组
	size_t m_szOperCount = 0;	// 操作符的个数
};
```

## 主函数

```c++
#include <iostream>
#include <string>
#include "calculator.h"
using namespace std;

int main()
{
	calculator  calc;

	string      strExpr;
	getline(cin, strExpr);	// 输入表达式

	cout << calc.run(strExpr) << endl;

	return 0;
}
```

## 类的实现

```c++
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
int getMaxPriorityOperIndex() const
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
```



