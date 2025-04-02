/*
 * File		caclulatro.h
 * Author:	Wanghp
 * Date:	20230401
 * Description: 简单的运算器类，支持单目和多目运算符的计算，暂不支持()改变优先级，支持1+2*3!/4
*/
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
	int getMaxPriorityOperIndex() const;	//获取优先级最高的操作符数组

	// 与表达式运算相关的函数
	static int getOperPriority(char oper);	//返回操作数的优先级
	static int calcExpr(char oper, int n1, int n2 = 0);	//计算表达式的值
	static int fact(int n);	//n!
	
	constexpr static size_t MAX_LEN = 100;
	int m_num[MAX_LEN] = {}; // 目前只学到数组，100个操作数数组
	size_t m_szNumCount = 0;	// 表达式中操作数的个数
	char m_oper[MAX_LEN] = {};   //100个操作符的数组
	size_t m_szOperCount = 0;	// 操作符的个数
};