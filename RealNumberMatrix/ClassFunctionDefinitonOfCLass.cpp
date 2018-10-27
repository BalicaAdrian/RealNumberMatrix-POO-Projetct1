#include "pch.h"
#include "ClassDefinitonOfMatrix.h"
#include<vector>

void Matrix::init()
{
	Matrice.resize(m_rows);
	for (int i = 0; i < m_rows; i++)
		Matrice[i].resize(m_columns);


}

void Matrix::afis()
{
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_columns; j++)
			std::cout << Matrice[i][j] << " ";
		std::cout << "\n";
	}
}

Matrix::Matrix(int rows,int columns)
{
	m_rows = rows;
	m_columns = columns;
	init();
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_columns; j++)
			if (i == j)
				Matrice[i][j] = 1;
}

