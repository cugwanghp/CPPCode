#pragma once

class Date
{
    public:
        Date(int day, int month, int year);
        void print() const;
        int getWeekOfYear() const;
        int getDaysInMonth() const;
        int getWeekOfMonth() const;
        void printMonthCalendar() const;
    private:
        int day;    //day of the month
        int month;  //month of the year
        int year;   //year
};