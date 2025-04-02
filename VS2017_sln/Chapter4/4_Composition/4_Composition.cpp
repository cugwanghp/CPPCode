#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int>	v1;
	vector<int*>	v2;

	v2.push_back(new int[10]{ 0,1,2,3 });
	v2.push_back(new int[9]{ 5,6,7,8 });
	cout << v2[0][2] << endl;
}