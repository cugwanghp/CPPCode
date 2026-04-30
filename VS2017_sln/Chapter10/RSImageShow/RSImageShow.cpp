#include <iostream>
#include "RSImage.h"

int main(int argc, char** argv)
{
		char		ch = '\018';

		// ²ÎÊıÎª£ºRSImageShow [image_path]
		if (argc < 2)
		{
				std::cerr << "RSImageShow.exe [image_path]\n";
				return -1;
		}

		RSEnviImage	rsimg;
		if(!rsimg.load(argv[1]))
				std::cerr << "Load image file failed.";
		else
				rsimg.show();

		return 0;
}