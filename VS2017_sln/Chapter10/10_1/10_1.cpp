//10_1.cpp
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;

template<typename T>
T abs(T x) {
		return x > 0 ? x : -x;
}
template<typename T>
class Abs {
public:
		T operator()(T x);	//运算符()重载
};
template<typename T>
T Abs<T>::operator()(T x){
		return x > 0 ? x : -x;
}
int main() {
	//const int N = 5;
	//vector<int> s(N);	//定义一个大小为N的向量容器
	//从标准输入读入向量容器的内容
	//for (int i = 0; i < N; i++)
	//	cin >> s[i];
	//输出向量容器中每个元素的相反数
	//transform(s.begin(), s.end(), ostream_iterator<int>(cout, " "), negate<int>());
	transform(istream_iterator<int>(cin),
			istream_iterator<int>(),
			ostream_iterator<int>(cout, " "), 
			negate<int>());
	cout << endl;
	copy(istream_iterator<int>(cin),
			istream_iterator<int>(),
			ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}
