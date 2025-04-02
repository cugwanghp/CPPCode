#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string		strFilePath = "C:\\Users\\wanghp\\Desktop\\1.txt";
	ifstream	ifs(strFilePath.c_str());
	strFilePath.append(".bak");
	ofstream	ofs(strFilePath.c_str());
	string		strTxt;
	int			nLen = 0;

	if (ifs.is_open() && ofs.is_open())
	{
		while (!ifs.eof())
		{
			getline(ifs, strTxt);
			ofs << strTxt;
			ofs << ((++nLen) % 3 == 0 ? "\t" : "\n");
		}
	}

	ifs.close();
	ofs.close();

	return 0;
}