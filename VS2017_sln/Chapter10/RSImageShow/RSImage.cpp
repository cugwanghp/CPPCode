#include "RSImage.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <graphics.h>
#include <conio.h>		//kbhit
#include <algorithm>
using namespace std;

RSEnviImage::RSEnviImage()
{
		m_nBands = 0;
		m_nLines = 0;
		m_nSamples = 0;
}

RSEnviImage::~RSEnviImage()
{
		m_imgData.clear();
}

// 加载文件
bool	RSEnviImage::load(const char* lpstrPath)
{
		if (NULL == lpstrPath)
				return false;

		// 1. 读元数据文件
		string		strMetaFilePath = lpstrPath;
		int				pos = strMetaFilePath.rfind('.');
		if (pos >= 0)
		{
				strMetaFilePath = strMetaFilePath.substr(0, pos);
		}
		strMetaFilePath.append(".hdr");	//*.img --> *.hdr

		//读元数据文件，获取图像波段，行，列，数据排列方式等
		if (!readMeta(strMetaFilePath.c_str()))	
		{
				cerr << "Read Meta Data Failed." << endl;
				return false;
		}

		// 2. 读图像二进制文件
		if (!readImage(lpstrPath))
		{
				cerr << "Read Image Data Failed." << endl;
				return false;
		}

		return true;
}

/////////////////////////////////////////////////////////////////////
// 读取元数据文件
/////////////////////////////////////////////////////////////////////
bool	RSEnviImage::readMeta(const char* lpstrMetaFilePath)
{
		ifstream    ifs;
		string      strLine;
		string      strSubTxt;
		stringstream    ss;

		// 打开元数据文本文件
		ifs.open(lpstrMetaFilePath, ios_base::in);
		if (!ifs.is_open())
				return false;

		while (!ifs.eof())   //end of file
		{
				std::getline(ifs, strLine);	//读一行

				ss.clear();
				ss.str(strLine);    //"samples = 640"
				ss >> strSubTxt;

				// 解析每一行，根据 key = value 的方式
				if (strSubTxt == "samples")
				{
						ss >> strSubTxt >> m_nSamples;
				}
				else if (strSubTxt == "lines")
				{
						ss >> strSubTxt >> m_nLines;
				}
				else if (strSubTxt == "bands")
				{
						ss >> strSubTxt >> m_nBands;
				}
				else if (strSubTxt == "interleave")
				{
						ss >> strSubTxt >> strSubTxt;
						if (strSubTxt == "bsq")
						{
								m_eInterleave = BSQ;
						}
						else if (strSubTxt == "bip")
						{
								m_eInterleave = BIP;
						}
						else if (strSubTxt == "bil")
						{
								m_eInterleave = BIL;
						}
						else
						{
								// blank
						}
				}
				else if (strSubTxt == "data")
				{
						ss >> strSubTxt;
						if (strSubTxt == "type")
						{
								ss >> strSubTxt >> m_nDataType;
						}
				}
				else
				{
						// blank
				}
		}

		return true;
}

// 读图像二进制文件
bool	RSEnviImage::readImage(const char* lpstrImgFilePath)
{
		bool        bFlag = true;
		int         i, j;
		ifstream    ifs(lpstrImgFilePath, ios::binary);

		if (ifs.is_open())
		{
				// 初始化图像矩阵	，按波段和图像行*图像列来存储
				auto imgData = vector<vector<DataType> >(m_nBands,
						vector<DataType>(m_nLines*m_nSamples, 0));

				switch (m_eInterleave)
				{
				case BSQ:		//按波段来间隔
						for (i = 0; i < m_nBands && !ifs.eof(); i++)
						{
								ifs.read((char*)imgData[i].data(), sizeof(DataType)*m_nLines*m_nSamples);								
						}
						// 文件未读完整
						if (i < m_nBands)
								bFlag = false;
						break;
				case BIL:		//按行来间隔
						for (j = 0; j < m_nLines && !ifs.eof(); j++)		//先读行
						{
								for (i = 0; i < m_nBands && !ifs.eof(); i++)//再读波段
								{
										ifs.read((char*)(imgData[i].data()+j*m_nSamples), sizeof(DataType)*m_nSamples);
								}
						}
						// 数据不完整
						if (j < m_nLines || i < m_nBands)
								bFlag = false;
						break;
				case BIP:		//按像素来间隔
						// unique_ptr 避免动态分配内存忘记释放
						unique_ptr<DataType[]> ptrBuff(new DataType[m_nBands]);
						if (ptrBuff.get() == nullptr)
								bFlag = false;

						for (j = 0; j < m_nSamples*m_nLines && !ifs.eof(); j++)//先像素
						{
								//读每个波段的像素
								ifs.read((char*)(ptrBuff.get()), sizeof(DataType)*m_nBands);

								for (i = 0; i < m_nBands; i++)	//再波段
								{
										imgData[i][j] = ptrBuff[i];
								}
						}
						if (j < m_nSamples*m_nLines)
								bFlag = false;
						break;
				}

				ifs.close();

				// 存放读取的数据
				if (bFlag) {
						m_imgData = imgData;
				}
		}
		return bFlag;
}

// 将r,g,b的波段数据转换未IMAGE
void	RSEnviImage::convert2Color(int r, int g, int b, IMAGE& imgColor) const
{
		DWORD*	pImgBuffer = GetImageBuffer(&imgColor);
		int		i, j;
					
		// 找出每个通道的最小值和最大值
		auto minmax_R = std::minmax_element(m_imgData[r].begin(), m_imgData[r].end());
		auto minmax_G = std::minmax_element(m_imgData[g].begin(), m_imgData[g].end());
		auto minmax_B = std::minmax_element(m_imgData[b].begin(), m_imgData[b].end());

		// 计算拉伸参数
		double scaleR = (*minmax_R.first == *minmax_R.second) ? 1.0 : 255.0 / (*minmax_R.second - *minmax_R.first);
		double scaleG = (*minmax_G.first == *minmax_G.second) ? 1.0 : 255.0 / (*minmax_G.second - *minmax_G.first);
		double scaleB = (*minmax_B.first == *minmax_B.second) ? 1.0 : 255.0 / (*minmax_B.second - *minmax_B.first);

		// 遍历像素，设置像素值
		for (i = 0; i < m_nLines*m_nSamples; i++)
		{
				// BGR线性拉伸每个通道
				pImgBuffer[i] = BGR(RGB(
						static_cast<BYTE>((m_imgData[r][i] - *minmax_R.first)*scaleR),
						static_cast<BYTE>((m_imgData[g][i] - *minmax_G.first)*scaleG),
						static_cast<BYTE>((m_imgData[b][i] - *minmax_B.first)*scaleB)));			
		}
}

// 绘制图像
void RSEnviImage::show() const
{
		initgraph(m_nSamples, m_nLines);

		setbkcolor(WHITE);
		cleardevice();

		int		r, g, b;

		if (m_nBands >= 3) //RGB波段, 若不合法，则用第一个波段作为缺省值
		{
				r = 0;
				g = 1;
				b = 2;
		}	
		else
		{
				r = g = b = 0;
		}

		IMAGE	img(m_nSamples, m_nLines);
		convert2Color(r, g, b,img);

		// 绘制影像
		putimage(0, 0, &img);

		// 等待用户按 ESC，退出显示窗口
		while (!_kbhit())
		{
				if (_getch() == 27)
						break;
		}

		// 关闭绘制窗体
		closegraph();
}