//11_1.cpp
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void testfstream() {
		ifstream		ifsText("D://pt.txt");
		ifstream		ifsBinary("D://pt.dat",ios_base::binary);
		int			a, b;
		ifsText >> a;		//"123"-->123
		ifsBinary.read((char*)&b, sizeof(b));
		std::cout << std::hex << a << std::endl;
		std::cout << std::hex << b << std::endl;
		ifsText.close();
		ifsBinary.close();
}

int main() {
		testfstream();
		return 0;
	double values[] = { 1.23, 35.36, 653.7, 4358.24 };
	//cout.fill('*');
	for (int i = 0; i < 4; i++) {
		cout.width(10);
		cout << values[i] << endl;
	}
	return 0;
}
