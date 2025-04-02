#include <iostream>
#include <string>
using namespace std;

int add(const string& strStuName)
{
	//
	static int sStuID = 11322000;

	return ++sStuID;
}
int main()
{
	int			nStuID;
	string		strName = "Wang";
	nStuID = add(strName);
	cout << nStuID << "\t" << strName << endl;

	strName = "Zhang";
	nStuID = add(strName);
	cout << nStuID << "\t" << strName << endl;

	strName = "Lee";
	nStuID = add(strName);
	cout << nStuID << "\t" << strName << endl;
	return 0;
}