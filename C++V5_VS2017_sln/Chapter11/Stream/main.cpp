/*
* 文件流读写的示例代码
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>	//io format

int main()
{
		std::string	strTextFilePath = "D:\\test.txt";
		std::string strBinaryFilePath = "D:\\test.dat";

		int			n = 100;
		std::string	strText = "Hello world";

		// write text file
		std::ofstream		ofs_text(strTextFilePath.c_str());	//默认按文本文件打开
		ofs_text << n << std::endl;	//写入100的ASCII码'1','0','0'，即0x31,0x30,0x30
		ofs_text << strText << std::endl;		//写入"Hello world"的ASCII码，注意换行与后面字符分隔开
		for (int i = 1; i < 10; ++i)
		{
				for (int j = i; j < 10; ++j)
				{
						ofs_text << i << "*" << j << "=" << std::setw(2) << i * j << " ";
				}
				ofs_text << std::endl;
		}
		ofs_text.close();		//关闭文件，切记！！！

		// write binary file
		std::ofstream		ofs_bin(strBinaryFilePath.c_str(), std::ios_base::binary);//按binary打开
		ofs_bin.write((const char*)(&n), sizeof(n));		//写入变量二进制，按首地址和字节长度写入
		ofs_bin.write(strText.c_str(), strText.size());	//写入字符串二进制，按首地址和字节长度写入
		ofs_bin.close();		//关闭文件，切记！！！

		// read text file
		std::ifstream		ifs_text(strTextFilePath.c_str());	//默认按文本文件打开
		while (!ifs_text.eof())	//end of file 检测是否到文件末尾
		{
				int	n;
				std::string			str;		//字符串变量
				ifs_text >> n >> str;
				std::getline(ifs_text, str);		//读取一行字符串，如果要转换为int变量，需要使用stringstream
				std::cout << str << std::endl;
		}
		ifs_text.close();		//关闭文件

		// read binary file
		std::ifstream		ifs_bin(strBinaryFilePath.c_str(), std::ios_base::binary);	//按binary打开
		ifs_bin.read((char*)&n, sizeof(n));	//读4个字节的二进制值到变量n
		std::cout << n << std::endl;

		char		text[12]{};
		ifs_bin.read(text, 11);	//读11个字节的二进制到字符数组text
		std::cout << text;	//
		ifs_bin.close();		//关闭文件

		//
		// 思考：字符（字符串）按文本文件写入 和 二进制写入的值 有无相同之处。
		//


		return 0;
}
