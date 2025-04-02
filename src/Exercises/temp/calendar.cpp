#include<iostream>
//设计一个显示日历的程序，输入年、月，输出对应的日历。输出的日历如表2.1所示：
bool isLeapYear(int year) {             //判断是否为闰年
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int getDaysOfMonth(int year, int month) {
    static int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month == 2 && isLeapYear(year)) {           //闰年的二月为29天
        return 29;
    }
    return days[month-1];                        //返回不是闰年时候的每月天数数组
}

int getWeekdayOfMonth(int year, int month) {         
    int totalDays = 0;                             // 累加前面年份的天数
    for (int i = 1900; i < year; i++) {
        totalDays += isLeapYear(i) ? 2 : 1;            //判断当年是否为闰年,366%7=2,365%7=1
    }                                        
    for (int i = 1; i < month; i++) {
        totalDays += getDaysOfMonth(year, i);
    }                                           
    return (totalDays+1) % 7; // 1900年1月1日是星期一,这里加1后取余7
}

void printCalendar(int year, int month) {
    std::cout << "   Sun   Mon   Tue   Wed   Thu   Fri   Sat" << std::endl;
    int firstday = getWeekdayOfMonth(year, month);                   //判断每月一号是星期几
    int days = getDaysOfMonth(year, month);             //每月第几天

    for (int i = 0; i < firstday; ++i) {
        std::cout.width(6);                                   //空格
        std::cout << " ";
    }

    for (int i = 0; i < days; ++i) {
        std::cout.width(6);
        std::cout << i+1;
        if ((firstday + i) % 7 == 6) {                //要换行了
            std::cout << std::endl;
        }
    }                                                     //在这里退出循环
    std::cout << std::endl;
}

int main() {
    int year;
    int month;
    std::cout << "请依次输入年份-月份" << std::endl;
    std::cin >> year >> month;
    printCalendar(year, month);
    return 0;
}
