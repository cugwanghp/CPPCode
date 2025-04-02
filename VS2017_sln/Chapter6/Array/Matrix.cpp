#include "Matrix.h"

Matrix::Matrix(int row, int col) : m_row(row), m_col(col){
		//1. 创建一个row个元素的一维指针数组
		int** m_ppArray = new int*[m_row];	//row个元素的数组，元素的数据类型是int*
		for (int i = 0; i < m_row; i++) {
				m_ppData[i] = new int[m_col];		//int*
		}
}

// 拷贝构造函数
Matrix::Matrix(const Matrix& ary) : m_row(ary.m_row), m_col(ary.m_col) {
		//1. 创建一个row个元素的一维指针数组
		m_ppData = new int*[m_row];	//row个元素的数组，元素的数据类型是int*
		if (m_ppData == nullptr)
				throw(std::bad_alloc());

		for (int i = 0; i < m_row; i++) {
				m_ppData[i] = new int[m_col];		//int*
				if (m_ppData[i] == nullptr)
						throw(std::bad_alloc());

				for (int j = 0; j < m_col; j++) {
						m_ppData[i][j] = ary.m_ppData[i][j];
				}
		}
}

// 移动构造函数
Matrix::Matrix(Matrix&& ary) : m_row(ary.m_row), m_col(ary.m_col) {
		m_ppData = ary.m_ppData;
		ary.m_ppData = nullptr;
}

// 析构函数
Matrix::~Matrix()
{
		for (int i = 0; i < m_row; i++) {
				if (m_ppData[i] != nullptr) {
						delete[] m_ppData[i];		//
				}
		}
		if (m_ppData != nullptr) {
				delete[] m_ppData;
		}
}

int* //重载[]操作符
Matrix::operator[](int row)
{
		if (m_ppData && row >= 0 && row < m_row)
				return m_ppData[row];
		return nullptr;
}

const int* //重载[]操作符
Matrix::operator[](int row) const
{
		if (m_ppData && row >= 0 && row < m_row)
				return m_ppData[row];
		return nullptr;
}

void //输出矩阵
Matrix::print(std::ostream& os) {
		for (int i = 0; i < m_row; i++) {
				for (int j = 0; j < m_col; j++) {
						os << m_ppData[i][j] << "\t";
				}
				os << std::endl;
		}
}


Matrix	//矩阵转置
Matrix::transpose() const
{
		Matrix	transMatrix(m_col, m_row);
		for (int i = 0; i < transMatrix.row(); i++) {
				for (int j = 0; j < transMatrix.col(); j++) {
						transMatrix[i][j] = m_ppData[i][j];
				}
		}
		return transMatrix;
}
