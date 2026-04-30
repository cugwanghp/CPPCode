#include <iostream>

class Rational {
private:
		int num; // 分子
		int den; // 分母

		// 辅助函数：约分
		void simplify();

public:
		// 构造函数
		Rational(int n = 0, int d = 1);

		// --- 1. 赋值运算符 (必须是成员函数) ---
		Rational& operator=(const Rational& rhs);
		// --- 2. 复合赋值运算符 (建议成员函数) ---
		Rational& operator+=(const Rational& rhs);

		// --- 3. 自增/自减运算符 ---
		// 前置 ++ (如 ++r)
		Rational& operator++();

		// 后置 ++ (如 r++)
		Rational operator++(int);

		// --- 4. 算术运算符 (全局函数实现，支持对称性) ---
		friend Rational operator+(Rational lhs, const Rational& rhs);
		friend Rational operator-(Rational lhs, const Rational& rhs);
		friend Rational operator*(const Rational& lhs, const Rational& rhs);

		// --- 5. 关系运算符 ---
		friend bool operator==(const Rational& lhs, const Rational& rhs);
		friend bool operator<(const Rational& lhs, const Rational& rhs);

		// --- 6. 类型转换运算符 ---
		explicit operator double() const;

		friend std::ostream& operator<<(std::ostream& os, const Rational& r);
		friend std::istream& operator>>(std::istream& is, Rational& r);
};

// --- 4. 算术运算符 (全局函数实现，支持对称性) ---
Rational operator+(Rational lhs, const Rational& rhs);
Rational operator-(Rational lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);

// --- 5. 关系运算符 ---
bool operator==(const Rational& lhs, const Rational& rhs);
bool operator<(const Rational& lhs, const Rational& rhs);

// --- 7. 输入输出流 (必须全局) ---
std::ostream& operator<<(std::ostream& os, const Rational& r);
std::istream& operator>>(std::istream& is, Rational& r);
