#include "Array.h"
#include <iostream>
#include <memory>

int** make2DArray(int row, int col) {
		//1. 创建一个row个元素的一维指针数组
		int** ppArray = new int*[row];	//row个元素的数组，元素的数据类型是int*
		for (int i = 0; i < row; i++) {
				ppArray[i] = new int[col];		//int*
		}
		return ppArray;
}
//i,j
void delete2DArray(int** ppArray, int row)
{
		for (int i = 0; i < row; i++) {
				if (ppArray[i] != nullptr) {
						delete[] ppArray[i];		//
				}
		}
		if (ppArray != nullptr) {
				delete[] ppArray;
		}
}

void print2DArray(int** ppArray, int row, int col) {
		for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
						std::cout << ppArray[i][j] << "\t";
				}
				std::cout << std::endl;
		}
}

class vecotr2 {
public:
		vector2(int size);
		void append(int elem);
private:
		int*		m_pdata;
		int			m_size;
		int			m_count;
};

vector2::vector2(int size) : m_size(size), m_count(0) {
		m_pdata = new int[size];
}

void vector2::append(int elem) {
		if (m_count < m_size) {
				m_pdata[m_count] = elem;
				m_count++;
		}
		else {	//full
				//1. new more size
				int*		pNewArray = new int[m_size + 10];

		}
}
int main()
{
		//Add name,....
		std::string	names[1000];
		int	countName = 0;

		// Add 
		std::cin >> names[countName++];

		// 输入数组的行和列数，再输入数组，对输入数组进行转置，输出结果
		int			row, col;				//数组大小是动态的
		std::cin >> row >> col;	//2*3数组，输出3*2数组

		int**		ppArray = make2DArray(row, col);
		int**		ppTransArray = make2DArray(col, row);
		for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
						std::cin >> ppArray[i][j];
				}
		}

		for (int i = 0; i < col; i++) {
				for (int j = 0; j < row; j++) {
						ppTransArray[i][j] = ppArray[j][i];
				}
		}
		std::cout << "Array: \n";
		print2DArray(ppArray, row, col);
		std::cout << "Transposed Array: \n";
		print2DArray(ppTransArray, col, row);
		return 0;
		//1. 把row行col列的二维数组 转换为一个 row*col 个元素的一维数组
		int*		parray = new int[row*col];
		for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
						std::cin >> *(parray + i * col + j);
				}
		}
		int*		pTransArray = new int[col*row];
		for (int i = 0; i < col; i++) {
				for (int j = 0; j < row; j++) {
						*(pTransArray + i * row + j) = *(parray + j * col + i);
				}
		}

		for (int i=0; i<col; i++){		//col 转置后的矩阵的行
				for (int j = 0; j < row; j++) {	//row-转置后的矩阵的列
						std::cout << *(pTransArray + i * row + j) << "\t";
				}
				std::cout << std::endl;
		}

		delete[] parray;
		delete[] pTransArray;
		return 0;

//		Array		a(6);
//		Array		b(a);
//		Array		c(Array(6));
		Array		d = make_array(6);
		return 0;
}

