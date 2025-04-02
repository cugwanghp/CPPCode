#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
/*	ofstream	ofs_asc("e:\\1.txt");
	char	strTxt[] = "CUG";
	int		a = 100;
	ofs_asc << strTxt << endl;
	ofs_asc << a << endl;
	ofs_asc.close();

	ofstream	ofs_bin("e:\\1.dat", ios_base::binary);
	ofs_bin.write(strTxt, sizeof(char) * 3);
	ofs_bin.write((const char*)&a, sizeof(a));
	ofs_bin.close();
	return 0;
*/
	ifstream	ifs;
	int			type, b, c, d;
	ifs.open("E:\\data.txt");
	string		strtext;

	if (!ifs.is_open()) {
		cout << "文件打开失败！" << endl;
		exit(-1);
	}
	while (!ifs.eof())
	{
		getline(ifs, strtext);
		istringstream	ss(strtext);

		ss >> type;
		ss.ignore(1);
		switch (type)
		{
		case 0:
			ss >> b;
			ss.ignore(1);
			ss >> c;
			ss.ignore(1);
			ss >> d;
			break;
		case 1: case 4:
			ss >> b;
			ss.ignore(1);
			ss >> c;
			break;
		case 2: case 3:
			ss >> b;
			break;
		default:
			break;
		}
	}

	ifs.close();

	return 0;
}

