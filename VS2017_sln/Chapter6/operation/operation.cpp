// operation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

typedef int(*PTRF)(int, int);		//define function's pointer
PTRF getOperatorFun(char oper); //PTRF --> auto

int compute(int a, int b, PTRF pf)
{
		if (pf)	return pf(a, b);
		return 0;
}

int max(int a, int b) {	return ((a > b) ? a : b); }// 求最大值

int min(int a, int b) {	return ((a < b) ? a : b);}// 求最小值

int add(int a, int b) {	return a + b; }	// 求和

int sub(int a, int b) {	return a - b; }

int mod(int a, int b){ return a % b; }

int mul(int a, int b) { return a * b; }

int	div2(int a, int b) { return a / b; }

int pow(int a, int b)
{
		if (b == 0)
				return 1;
		return a * pow(a, b - 1);
}

int gcd(int a, int b) {
		if (a%b == 0)	return b;
		return(b, a%b);
}

//auto - 推断类型
PTRF getOperatorFun(char oper)	//PTRF --> auto
{
		static char		opers[] = "+-/*%^#$&";
		static PTRF		funs[] = {add, sub, div2, mul, mod, pow, max, min, gcd, nullptr};
		int (*pf)(int, int) = nullptr;
		int			i = 0;

		while (opers[i]) {
				if (opers[i] == oper) {
						pf = funs[i];
						break;
				}
				i++;
		}
		
		return pf;
}


int main()
{
		//1+1,1-2,1*2
		int	a, b;
		char		oper;		//operation
		int	res;
		do {
				std::cout << "请输入运算表达式：";
				auto pf = getOperatorFun(oper);
				if (pf == nullptr)
						std::cerr << "unsupported operator.\n";
				else
						std::cout << a << oper << b << " = " << pf(a,b) << std::endl;
		} while (a!=0);
		
		return 0;
}
