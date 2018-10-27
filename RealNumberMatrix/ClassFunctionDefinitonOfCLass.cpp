#include "pch.h"
#include "ClassDefinitonOfMatrix.h"
#include<vector>

void Matrix::init()
{
	Matrice.resize(m_rows);
	for (int i = 0; i < m_rows; i++)
		Matrice[i].resize(m_columns);


}

/*void Matrix::afis()
{
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_columns; j++)
			std::cout << Matrice[i][j] << " ";
		std::cout << "\n";
	}
}*/

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

Matrix::~Matrix() {
	for (int i = 0; i < m_rows; i++)
		Matrice[i].erase(Matrice[i].begin(), Matrice[i].begin()+m_columns);
	Matrice.erase(Matrice.begin(), Matrice.begin() + m_rows);
		
		
}

Matrix Matrix::operator += (Matrix Mat)
{
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_columns; j++)
			Matrice[i][j] += Mat.Matrice[i][j];

	return *this;
}

Matrix Matrix::operator-=(Matrix Mat)
{
	
	
		for (int i = 0; i < m_rows; i++)
			for (int j = 0; j < m_columns; j++)
				Matrice[i][j] -= Mat.Matrice[i][j];

		return *this;
	

	
}


std::istream& operator >> (std::istream& cin, Matrix& Mat)
{
	for (int i=0; i < Mat.m_rows; i++)
		for (int j=0; j < Mat.m_columns; j++)
			std::cin >> Mat.Matrice[i][j];
	return cin;
}

std::ostream& operator << (std::ostream& cout, Matrix& Mat)
{
	for (int i=0; i < Mat.m_rows; i++){
		for (int j=0; j < Mat.m_columns; j++) 
			std::cout << Mat.Matrice[i][j] << " ";
			std::cout << "\n";
		}
			return cout;
}

