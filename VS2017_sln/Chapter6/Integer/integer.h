#pragma once

class Integer
{
public:
	Integer(int val=0); //构造函数
	Integer(const Integer& i); //复制构造函数
	Integer(Integer&& other); //移动构造函数

	Integer& operator=(const Integer& other); //复制赋值运算符
	Integer& operator=(Integer&& other); //移动赋值运算符

	~Integer() = default; //析构函数

	Integer operator+(const Integer& other) const; //加法重载
	Integer operator-(const Integer& other) const; //减法重载
	Integer operator*(const Integer& other) const; //乘法重载
	Integer operator/(const Integer& other) const; //除法重载

	Integer& operator+=(const Integer& other); // +=重载
	Integer& operator-=(const Integer& other); // -=重载
	Integer& operator*=(const Integer& other); // *=重载
	Integer& operator/=(const Integer& other); // /=重载

	//输出流操作符重载
	friend std::ostream& operator<<(std::ostream& os, const Integer& i);

	//输入流操作符重载
	friend std::istream& operator>>(std::istream& os, const Integer& i);

private:
		int m_val;
};

//输出流操作符重载
std::ostream& operator<<(std::ostream& os, const Integer& i);

//输入流操作符重载
std::istream& operator>>(std::istream& os, const Integer& i);