/*
 * @Description: 
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2023-03-21 08:53:31
 * @LastEditors: Wang Hongping
 * @LastEditTime: 2023-03-21 09:09:04
 */
#pragma once
#include <iostream>
using namespace std;

class fraction{
public:
    fraction(long numerator=0, long denominator=1);
    fraction(double value);
    fraction(const fraction& f);

	friend ostream& operator<<(ostream& os, const fraction& f);
	friend istream& operator>>(istream& in, fraction& f);	//cin>>f;

	//operator override
	operator double();	//double()
	fraction operator+(const fraction& f2);
	fraction operator-(const fraction& f2);
	fraction operator*(const fraction& f2);
	fraction operator/(const fraction& f2);
private:
    long    m_numerator;    //分子
    long    m_denominator;  //分母

    void reduce();    //约简
};

ostream& operator<<(ostream& os, const fraction& f);
istream& operator>>(istream& in, fraction& f);