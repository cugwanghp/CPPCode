#pragma once

#include <iostream>

class Matrix {
public:
		Matrix(int row, int col);
		Matrix(const Matrix& ary);
		Matrix(Matrix&& ary);
		
		~Matrix();

		Matrix& operator=(const Matrix& ary);
		Matrix& operator=(Matrix&& ary);

		inline int row() const { return m_row; }
		inline int col() const { return m_col; }
		int* operator[](int row);
		const int* operator[](int row) const;

		void print(std::ostream& os);

		Matrix transpose() const;
private:
		int**		m_ppData;		//二维数组的行指针数组
		int			m_row;			//行
		int			m_col;			//列
};