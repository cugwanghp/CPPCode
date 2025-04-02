#include <iostream>
#include "personbook2.h"
#include <vector>
using namespace std;

//forward declaration
void Usage();

int main()
{
	Usage();

	char    cmd;
	bool    bExit = false;
	personbook2	pbook;
	int		index;

	do {
		cin >> cmd;
		switch (cmd)
		{
		case 'A': case 'a':
			if (pbook.add(person2(cin)))
				cout << "add finished" << endl;
			break;
		case 'D': case 'd':
			cin >> index;
			if (pbook.del(index))
				cout << index << " is deleted" << endl;
			break;
		case 'M': case 'm':
			cin >> index;
			if (pbook.mod(index, person2(cin)))
				cout << index << " is modified" << endl;
			break;
		case 'C': case 'c':
			pbook.clear();
			cout << "clear all" << endl;
			break;
		case 'L': case 'l':
			pbook.list();
			break;
		case 'X': case 'x':
			bExit = true;
			break;
		case 'H': case 'h':
			Usage();
			break;
		}
	} while (!bExit);

	return 0;
}

void Usage()
{
	cout << "A [name] [address] - Add one person" << endl;
	cout << "D [ID] - Del one person" << endl;
	cout << "M [ID] [name] [address] - Modi ID's person base 1" << endl;
	cout << "C - clear all the person" << endl;
	cout << "L - list the person" << endl;
	cout << "X - Exit" << endl;
	cout << "H - help" << endl;
}