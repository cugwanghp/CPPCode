#pragma once

#include <vector>
using std::vector;

class IMAGE;		//前向声明

// 遥感数据排列顺序
enum INTERLEAVE_TYPE { BSQ, BIP, BIL };

// 遥感图像类
class RSEnviImage
{
public:
		typedef unsigned char	DataType;	//类型别名

		// 构造函数和析构函数
		RSEnviImage();
		RSEnviImage(const RSEnviImage& img) = delete;
		~RSEnviImage();

		// Operations
		bool load(const char* lpstrPath);		//加载文件
		void show() const;	//显示图像

protected:
		bool	readMeta(const char* lpstrMetaFilePath);	//读文本文件
		bool	readImage(const char* lpstrImgFilePath);	//读二进制文件
		void	convert2Color(int r, int g, int b, IMAGE& imgColor) const;		//rgb转换为img

protected:
		vector<vector<DataType> >	m_imgData;	//二维数组，channel, lines*samples
		int				m_nBands;							//波段数
		int				m_nLines;							//行
		int				m_nSamples;						//列
		INTERLEAVE_TYPE m_eInterleave;	//数据间隔方式
		short       m_nDataType;				//数据类型（暂未考虑）
};
