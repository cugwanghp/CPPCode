#include "Calendar.h"
#include <iostream>
#include <iomanip>

using namespace std;

/*
		2017-11 Calendar
|-----------------------------|
| Sun Mon Tue Wed Thu Fri Sat |
|             01  02  03  04  |
| 05  06  07  08  09  10  11  |
| 12  13  14  15  16  17  18  |
| 19  20  21  22  23  24  25  |
| 26  27  26  27  28  29  30  |
|-----------------------------|
*/

// 输出日历
void printCalendar(int nYear, int nMonth)
{
	cout << "        " << setw(4) << nYear << "-";
	cout << setw(2) << setfill('0') << nMonth << " Calendar " << endl;
	cout << "|-----------------------------|" << endl;
	cout << "| Sun Mon Tue Wed Thu Fri Sat |" << endl;

	int         nMonthDays;
	int         weekday;
	eWeekday    weekdayMonthHead;

	// 月首行的开头
	weekdayMonthHead = getWeekday(nYear, nMonth, 1);
	if (weekdayMonthHead != SUN)
		cout << "| ";
	for (weekday = SUN; weekday < weekdayMonthHead; weekday++)
	{
		cout << "    ";
	}

	// 月内的日期
	weekday = weekdayMonthHead;
	nMonthDays = getMonthDays(nYear, nMonth);
	for (int i = 0; i < nMonthDays; i++)
	{
		// 一行的开头
		if (weekday == SUN)
			cout << "| ";

		// 输出日期
		cout << setw(2) << (i + 1) << "  ";

		// 一行的结束
		if (weekday == SAT)
			cout << "|" << endl;

		weekday++;
		weekday %= WEEK;
	}

	// 月尾行的结尾
	if (weekday != SUN) //如果一个月的最后一天不是SAT，则补齐空格
	{
		for (; weekday < WEEK; ++weekday)
			cout << "    ";
		cout << "|" << endl;
	}

	// 结束边框
	cout << "|-----------------------------|" << endl;
}

///////////////////////////////////////////////////////////
//                  获取某年某月的天数                   //
///////////////////////////////////////////////////////////
int getMonthDays(int nYear, int nMonth)
{
	static int daysOfMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	if (nMonth == 2 && isLeapYear(nYear))
		return daysOfMonth[nMonth - 1] + 1;

	return daysOfMonth[nMonth - 1];
}

// 获取某天是星期几
eWeekday getWeekday(int nYear, int nMonth, int nDay)
{
	// 公元1900年1月1日，星期一
	int     nDayCounts = 0;

	// 如果Year<_YearRef, 计算天数（负数）
	for (int i = nYear; i > _YearRef; --i)
	{
		nDayCounts = (nDayCounts - (isLeapYear(i) ? 366 : 355)) % WEEK;
	}
	nDayCounts = (nDayCounts + WEEK) % WEEK;

	// 计算从公元1900年1月1日到nYear年1月1日的天数
	for (int i = _YearRef; i < nYear; i++)
	{
		nDayCounts = (nDayCounts + (isLeapYear(i) ? 366 : 365)) % WEEK;
	}

	// 计算nYear年，从1月到nMonth-1月的天数，余7
	for (int i = 1; i < nMonth; ++i)
	{
		nDayCounts = (nDayCounts + getMonthDays(nYear, i)) % WEEK;
	}

	// 计算nYear年nMonth月1日到当前日期的天数
	nDayCounts += nDay - 1;

	nDayCounts += _WdRef;   //1900-1-1
	nDayCounts %= WEEK;

	return (eWeekday)nDayCounts;
}
