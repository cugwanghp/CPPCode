#include "Date.h"
#include <iostream>

int main()
{
    Date date(15, 8, 2021);
    date.print();
    std::cout << "\nWeek of the year: " << date.getWeekOfYear();
    std::cout << "\nDays in month: " << date.getDaysInMonth();
    std::cout << "\nWeek of the month: " << date.getWeekOfMonth() << std::endl;

    return 0;
}

