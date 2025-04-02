# Chapter 2 Work Flow

[TOC]



Markdown

## 2-1 Flow Sample

```flow
st=>start
en=>end
op=>operation: OP
in=>inputoutput: in
cond=>condition: cond
sub=>subroutine: sub
st(right)->op(right)->in(bottom)->cond
cond(yes)->sub
cond(no)->en
```

## 2-2 Leap Year
```flow
s=>start
e=>end
year=>inputoutput: year
cond_year=>condition: year>0
cond=>condition: is leap year?
yes=>inputoutput: is a leap year
no=>inputoutput: is not a leap year

s->year->cond_year
cond_year(yes)->cond
cond_year(no)->year
cond(yes)->yes->e
cond(no)->no->e
```

```c++
//2_2.cpp
#include <iostream>
using namespace std;

int main() {
	int year;
	bool isLeapYear;
	
	cout << "Enter the year: ";
	cin >> year;
	isLeapYear = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	
	if (isLeapYear)
		cout << year << " is a leap year" << endl;
	else
		cout << year << " is not a leap year" << endl;

	return 0;
}
```



## 2-3 Compare Numbers

```flow
s=>start: 开始
e=>end: 结束
xy=>inputoutput: 输入x,y
cond1=>condition: x与y相等?
cond2=>condition: x > y?
out1=>inputoutput: 输出 x<y
out2=>inputoutput: 输出 x>y
out3=>inputoutput: 输出 x=y
s->xy->cond1
cond1(yes)->out3->e
cond1(no)->cond2
cond2(yes)->out2->e
cond2(no)->out1->e
```

```c++
//2_3.cpp
#include<iostream>
using namespace std;

int main() {
	int x, y;
	cout << "Enter x and y:";
	cin >> x >> y;

	if (x != y)
		if (x > y)
			cout << "x > y" << endl;
		else
			cout << "x < y" << endl;
	else
		cout << "x = y" << endl;

	return 0;
}
```



## 2-4 Weekday

```flow
s=>start
e=>end
day=>inputoutput: day
cond0=>condition: is equal 0?
cond1=>condition: is equal 1?
cond2=>condition: is equal 2?
cond3=>condition: is equal 3?
cond4=>condition: is equal 4?
cond5=>condition: is equal 5?
cond6=>condition: is equal 6?
out0=>inputoutput: Sunday
out1=>inputoutput: Monday
out2=>inputoutput: Tuesday
out3=>inputoutput: Wednesday
out4=>inputoutput: Thursday
out5=>inputoutput: Friday
out6=>inputoutput: Saturday
out7=>inputoutput: Out of range Sunday ... Saturday

s->day->cond0
cond0(yes)->out0->e
cond0(no)->cond1
cond1(yes)->out1->e
cond1(no)->cond2
cond2(yes)->out2->e
cond2(no)->cond3
cond3(yes)->out3->e
cond3(no)->cond4
cond4(yes)->out4->e
cond4(no)->cond5
cond5(yes)->out5->e
cond5(no)->cond6
cond6(yes)->out6->e
cond6(no)->out7->e
```



```c++
//2_4.cpp
#include <iostream>
using namespace std;

int main() {
	int day;
	
	cin >> day;
	switch (day) {	
	case 0:
		cout << "Sunday" << endl;
		break;
	case 1:
		cout << "Monday" << endl;
		break;
	case 2:
		cout << "Tuesday" << endl;
		break;
	case 3:
		cout << "Wednesday" << endl;
		break;
	case 4:
		cout << "Thursday" << endl;
		break;
	case 5:
		cout << "Friday" << endl;
		break;
	case 6:
		cout << "Saturday" << endl;
		break;
	default:
		cout << "Day out of range Sunday .. Saturday" << endl;
		break;
	}

	return 0;
}
```



## 2-5 Sum with while

```FLOW
s=>start
e=>end
sum=>inputoutput: output sum
cond=>condition: i<=10
op_sum=>operation: sum += i
op_i=>operation: i++

s->cond
cond(yes)->op_sum->op_i(left)->cond
cond(no)->sum->e
```

```C++
//2_5.cpp
#include<iostream>
using namespace std;

int main() {
	int i = 1, sum = 0;
	while (i<=10) {
		sum += i;
		i++;
	}
	cout << "sum = " << sum << endl;
	return 0;
}
```



```flow
s=>start
e=>end
cond=>condition: i>10
op1=>operation: operation
op2=>operation: operation2
op3=>opeartion: operation3
s->op1->cond
cond(yes)->op2->e
cond(no)->op1
```



## 2-6 Reverse order

```flow
s=>start
e=>end
n=>inputoutput: n
cond=>condition: n is not equal zero
op_div=>operation: n = n/10
out_mod=>inputoutput: output n%10
s->n->out_mod->op_div(left)->cond
cond(yes)->out_mod
cond(no)->e
```

```c++
//2_6.cpp
#include <iostream>
using namespace std;

int main() {
	int n, right_digit, newnum = 0; 
	cout << "Enter the number: ";
	cin >> n;
	
	cout << "The number in reverse order is ";
	do {
		right_digit = n % 10;
		cout << right_digit;
		n /= 10;
	} while (n != 0);
	cout << endl;

	return 0;
}
```

## 2-7 Sum with do-while

```flow
s=>start
e=>end
sum=>inputoutput: output sum
cond=>condition: i<=10
op_sum=>operation: sum += i
op_i=>operation: i++

s->op_sum->op_i->cond
cond(yes)->op_sum
cond(no)->sum->e
```



```c++
//2_7.cpp
#include <iostream>
using namespace std;

int main() {
	int i = 1, sum = 0;
	do {
		sum += i;
		i++;
	} while (i <= 10);
	cout << "sum = " << sum << endl;

	return 0;
}
```



## 2-8 Factor

```flow
s=>start: 开始
e=>end: 结束
input_n=>inputoutput: 输入正整数 n
op_init_k=>operation: k=1
output_factor=>inputoutput: 输出因子
cond_less_n=>condition: k小于等于n
cond_k=>condition: k是n的因子吗
op_k++=>operation: k++
s->input_n->op_init_k->cond_less_n
cond_less_n(yes)->cond_k
cond_less_n(no)->e
cond_k(yes)->output_factor->op_k++(left)->cond_less_n
```



```c++
//2_8.cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	
	cout << "Enter a positive integer: ";
	cin >> n;
	cout << "Number  " << n << "   Factors  ";

	for (int k = 1; k <= n; k++)
		if (n % k == 0)
			cout << k << "  ";
	cout << endl;

	return 0;
}
```



## 2-9 Output Pattern

```c++
//2_9.cpp
#include <iostream>
using namespace std;

int main() {
	const int N = 4;
	for (int i = 1; i <= N; i++) {	//输出前4行图案
		for (int j = 1; j <= 30; j++)
			cout << ' ';	//在图案左侧空30列
		for (int j = 1; j <= 8 - 2 * i; j++)
			cout << ' ';
		for (int j = 1; j <= 2 * i - 1; j++)
			cout << '*';
		cout << endl;
	}
	for (int i = 1; i <= N - 1; i++) {	//输出后3行图案
		for (int j = 1; j <= 30; j++)
			cout << ' ';	//在图案左侧空30列
		for (int j = 1; j <= 7 - 2 * i ;j++)
			cout << '*';
		cout << endl;
	}
	return 0;
}
```



## 2-10 Positive & negative Count

```flow
s=>start
e=>end
input_n=>inputoutput: 输入整数（0退出）:
cond_n=>condition: n != 0
cond_n>0=>condition: n > 0
op_pos=>operation: pos_count++
op_neg=>operation: neg_count++

s->input_n->cond_n
cond_n(yes)->cond_n>0
cond_n(no)->e
cond_n>0(yes)->op_pos(left)->input_n
cond_n>0(no)->op_neg(right)->input_n
```



```c++
//2_10.cpp
#include <iostream>
using namespace std;

int main() {
	int i = 0, j = 0, n;
	cout << "Enter some integers please (enter 0 to quit):" << endl;
	cin >> n;
	while (n != 0) {
		if (n > 0) i += 1;
		if (n < 0) j += 1;
		cin >> n;
	}
	cout << "Count of positive integers: " << i << endl;
	cout << "Count of negative integers: " << j << endl;
	return 0;
}
```



## 2-11 Game Result



```c++
//2_11.cpp
#include <iostream>
using namespace std;

enum GameResult { WIN, LOSE, TIE, CANCEL };

int main() {
	GameResult result;                  //声明变量时,可以不写关键字enum
	enum GameResult omit = CANCEL;      //也可以在类型名前写enum

	for (int count = WIN ; count <= CANCEL ; count++) {	//隐含类型转换
		result = GameResult(count);		//显式类型转换
		if (result == omit) 
			cout << "The game was cancelled" << endl;
		else {
			cout << "The game was played ";
			if (result == WIN)
				cout << "and we won!";
			if (result == LOSE)
				cout << "and we lost.";
			cout << endl;
		}
	}
	return 0;
}
```

## 2-12 Guess Number

```FLOW
s=>start
e=>end
in_guessnum=>inputoutput: 输入数
cond_less=>condition: 输入数偏小
out_less=>inputoutput: guess number is less than number
cond_more=>condition: 输入数偏大
out_more=>inputoutput: guess number is more than number
op_times=>operation: times++
cond_times=>condition: 所猜次数达到最大
cond_equal=>condition: 输入数相等
game_win=>inputoutput: You are win.
game_lose=>inputoutput: You are lose.
s->in_guessnum->cond_less
cond_less(yes)->out_less->op_times
cond_less(no)->cond_more
cond_more(yes)->out_more->op_times
cond_more(no)->cond_equal
op_times->cond_times
cond_times(yes)->in_guessnum
cond_times(no)->cond_equal
cond_equal(yes)->game_win->e
cond_equal(no)->game_lose->e
```



```c++
#include <iostream>
#include <cstdlib>
#include <ctime>

enum GameResult {WIN, LOSE, TIE, CANCEL}

int main()
{
	srand(time(0));				//按时间设置随机数种子
	int		num = rand()%100;	//
	int		guessNum;
	int		times = 0;
	const int	maxGuessTimes = 6;

	do {
		std::cout << "Guess an integer in 0-99: ";
		std::cin >> guessNum;
		if (guessNum < num)
			std::cout << "less than number." << std::endl;
		else if (guessNum > num)
			std::cout << "more than number." << std::endl;
		else
			break;
		times++;
	} while (times < maxGuessTimes);

	if (guessNum == num)
	{
		std::cout << "You are WIN." << std::endl;
	}
	else
	{
		std::cout << "You are Lose." << std::endl;
	}
	
	return 0;
}
```

