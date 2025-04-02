#include "Calculator.h"
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

void Calculator::enter(double num) {	//将操作数num压入栈
	s.push(num);
}

//连续将两个操作数弹出栈，放在opnd1和opnd2中
//如果栈中没有两个操作数，则返回False 并输出相关信息
bool Calculator::getTwoOperands(double &opnd1, double &opnd2) {
	if (s.isEmpty()) {	//检查栈是否空
		cerr << "Missing operand!" << endl;
		return false;
	}
	opnd1 = s.pop();	//将右操作数弹出栈
	if (s.isEmpty()) {	//检查栈是否空
		cerr << "Missing operand!" << endl;
		return false;
	}
	opnd2 = s.pop();	//将左操作数弹出栈
	return true;
}

void Calculator::compute(char op) {	//执行运算
	double operand1, operand2;
	bool result = getTwoOperands(operand1, operand2);   //将两个操作数弹出栈

	if (result) {	//如果成功，执行运算并将运算结果压入栈
		switch(op) {
		case '+':
			s.push(operand2 + operand1);
			break;
		case '-':
			s.push(operand2 - operand1);
			break;
		case '*':
			s.push(operand2 * operand1);
			break;
		case '/':
			if (operand1 == 0) {	//检查除数是否为0
				cerr << "Divided by 0!" << endl;
				s.clear();	//除数为0时清空栈
			} else
				s.push(operand2 / operand1);
			break;
		case '^':
			s.push(pow(operand2, operand1));
			break;
		default:
			cerr << "Unrecognized operator!" << endl;
			break;
		}
		cout << "= " << s.peek() << " ";	//输出本次运算结果
	} else
		s.clear();	//操作数不够，清空栈
}

//工具函数，用于将字符串转换为实数
inline double stringToDouble(const string &str) {
	istringstream stream(str);	//字符串输入流
	double result;
	stream >> result;
	return result;
}

void Calculator::run() {	//读入并处理后缀表达式
	string str;
	while (cin >> str, str != "q") {
		switch(str[0]) {
		case 'c':
			s.clear();	//遇'c'清空操作数栈
			break;
		case '-':	//遇'-'需判断是减号还是负号
			if (str.size() > 1)	//若字符串长度>1，说明读到的是负数的负号
				enter(stringToDouble(str));	//将字符串转换为整数，压入栈
			else
				compute(str[0]);	//若是减号则执行计算
			break;

		case '+':	//遇到其它操作符时
		case '*':
		case '/':
		case '^':
			compute(str[0]);	//执行计算
			break;

		default:	//若读入的是操作数，转换为整型后压入栈
			enter(stringToDouble(str));
			break;
		}
	}
}

void Calculator::clear() {	//清空操作数栈
	s.clear();
}


/*
*/
/* 运算符优先级
					当前运算符
			   +	-	*	/	^	!
 栈顶运算符  +   >	 >	 <	 <	 <	 <
			-	>	>	<	<	<	<
			*	>	>	>	>	<	<
			/	>	>	>	>	<	<
			^	>	>	>	>	>	<
			!	>	>	>	>	>	>
			(	<	<	<	<	<	<
*/

bool Calculator2::run(const char* exp, double& val)	//运行计算器
{
	if (!checkExp(exp))
	{
		cerr << "Invalidate Calculator Expression." << endl;
		return false;
	}

	transPostexp(exp);
	cout << "post expression: " << m_strPostexpr << endl;
	val = computeValue();

	return true;
}

// 将中缀表达式转换成后缀表达式
void Calculator2::transPostexp(const char *exp)
{
	int i = 0;
	char e;
	Stack<char> s_optr; //初始化操作符栈，为存储后缀表达式做准备

	m_strPostexpr.clear();	//clear post expression

	while (*exp != '\0') // 对每个字符进行判断处理
	{
		switch (*exp)
		{
			//单独处理括号
			//如果是左括号，直接入栈
		case '(':
			s_optr.push(*exp);
			exp++;
			break;
			//如果为右括号，一直出栈操作，直到将 ( 也出栈
		case ')':
			e = s_optr.pop();
			while (e != '(')
			{
				m_strPostexpr.push_back(e);
				e = s_optr.pop();
			}
			exp++;
			break;
			// + - 优先级相同，当做同一种情况处理
		case '+':
		case '-':
			//由于 + - 的优先级只比 ( 大，所有只要栈顶字符不为 ( 就一直出栈；反之，则将 + - 入栈。
			while (!s_optr.isEmpty())
			{
				e = s_optr.peek();
				if (e == '(')
					break;
				else
				{
					m_strPostexpr.push_back(e);
					e = s_optr.pop();
				}
			}
			//最后将 + - 入栈
			s_optr.push(*exp);
			exp++;
			break;
		case '*':
		case '/':
			// * / 优先级比 * / ^ ! 小，所有如果栈顶运算符是它们，就出栈；反之就将 * / 入栈
			while (!s_optr.isEmpty())
			{
				e = s_optr.peek();
				if (e == '/' || e == '*' || e == '^' || e == '!') // * / 的优先级仅仅低于它前面的 * /，高于前面的 + -，所以要将前面的 * / 弹出栈；+ - 保留，因为新的 * / 会放在栈低，优先级高。
				{
					m_strPostexpr.push_back(e);
					e = s_optr.pop();
				}
				else
					break; // 其他情况（ + - 左括号 ）退出，
			}
			//最后将 / * 入栈
			s_optr.push(*exp++);
			break;
		case '^':
			// ^ 优先级仅比 ^ ! 小，如果栈顶运算符是它们，则出栈；反之将 ^ 入栈
			while (!s_optr.isEmpty())
			{
				e = s_optr.peek();
				if (e == '^' || e == '!')
				{
					m_strPostexpr.push_back(e);
					e = s_optr.pop();
				}
				else
					break; // 其他情况（ + - * / ( ）退出，
			}
			s_optr.push(*exp++);    //最后将 ^ 入栈
			break;
		case '!':
			// ! 优先级仅比 ! 小，所有如果栈顶运算符为 !,则将其出栈；反之，将 ! 入栈
			while (!s_optr.isEmpty())
			{
				e = s_optr.peek();
				if (e == '!')
				{
					m_strPostexpr.push_back(e);
					e = s_optr.pop();
				}
				else
					break; // 其他情况（ + - * / ^ ( ）退出，
			}
			//最后将 ! 入栈
			s_optr.push(*exp++);
			break;
		default:
			while ((*exp > '0' && *exp < '9') || *exp=='.' || *exp=='-') //循环判断是否为数字字符，如果是则保存到postexp，循环判断是因为可能是多位数字
			{
				m_strPostexpr.push_back(*exp);
				exp++;
			}
			//以#分隔各个数字字符
			m_strPostexpr.push_back('#');
		}
	}
	while (!s_optr.isEmpty()) //扫描完exp后，操作符栈可能还有操作符，将其存到postexp
	{
		m_strPostexpr.push_back(s_optr.pop());
	}
}

//计算后缀表达式的值
double Calculator2::computeValue()
{
	Stack<double>  s_num;

	int i = 1;
	double result;
	double a, b;
	double c;
	double d;
	const char* postexp = m_strPostexpr.c_str();

	while (*postexp != '\0')
	{
		switch (*postexp)
		{
		case '+':
			a = s_num.pop();
			b = s_num.pop();
			//计算 b+a 的值
			s_num.push(b + a);
			break;
		case '-':
			//计算 b-a 的值
			a = s_num.pop();
			b = s_num.pop();
			s_num.push(b - a);
			break;
		case '*':
			a = s_num.pop();
			b = s_num.pop();
			//计算 b*a 的值
			s_num.push(b*a);
			break;
		case '/':
			a = s_num.pop();
			b = s_num.pop();
			//计算 b/a 的值
			if (a != 0)
			{
				s_num.push(b / a);
			}
			else
			{
				printf("除0错误！\n");
				exit(0);
			}
			break;
		case '^':
			a = s_num.pop(); // a是指数
			b = s_num.pop();
			//计算 b^a 的值
			if (a != 0)
			{
				i = 1;
				c = 1;
				while (i <= a) {
					c = c * b;
					i++;
				}
			}
			else if (b != 0)
			{
				c = 1;
			}
			else {
				c = 0;
			}
			s_num.push(c);
			break;
		case '!':
			a = s_num.pop();
			//计算 a! 的值
			c = 1;
			i = a;
			while (i != 0) {
				c = c * i;
				i--;
			}
			s_num.push(c);
			break;
		default:
			//如果不是运算符，就只能是字符形式的数字，将其转换成对应的整数
			d = 0;
			while (*postexp >= '0' && *postexp <= '9')
			{
				d = 10 * d + (*postexp - '0');
				postexp++;
			}
			s_num.push(d);
		}
		postexp++; //继续下一个字符
	}
	result = s_num.pop();
	return result;
}

//检查用户输入的表达式的正误
bool Calculator2::checkExp(const char *exp)
{
	int i = 0;
	Stack<char> s;
	char e;
	//判断是否包含非法字符
	for (; exp[i] != '\0'; i++)
	{
		if (!((exp[i] >= '0' && exp[i] <= '9') || exp[i]=='.' || exp[i] == '!' || exp[i] == '^' || exp[i] == '+' || exp[i] == '-' || \
			exp[i] == '*' || exp[i] == '/' || exp[i] == '(' || exp[i] == ')'))

			return false;
	}
	//如果表达式中包含括号，验证括号的完整性
	for (i = 0; exp[i] != '\0'; i++)
	{
		switch (exp[i])
		{
		case '(':
			s.push(exp[i]);
			break;
		case ')':
			if (!s.isEmpty())
			{
				e = s.pop();
				if (exp[i] == ')' && e == '(')
					return true;
				else
					return false;
			}
			else
				return false;
			break;
		}
	}
	//栈为空表示括号匹配成功
	if (!s.isEmpty())
		return false;
	else
		return true;
	return true;
}