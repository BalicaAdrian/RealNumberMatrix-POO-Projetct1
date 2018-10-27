#include "pch.h"
#include "ClassDefinitonOfMatrix.h"
#include<vector>
#include<fstream>

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
	if (m_rows != Mat.m_rows || m_columns != Mat.m_columns)
	{
		std::cout << "Numarul de coloane sau de linii nu este acelas, deci adunarea nu poate fi realizata";
		return *this;
	}
for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_columns; j++)
			Matrice[i][j] += Mat.Matrice[i][j];

	return *this;
}

Matrix Matrix::operator += (double x) 
{
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_columns; j++)
			Matrice[i][j] +=x;

	return *this;
}

Matrix Matrix::operator -= (double x)
{
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_columns; j++)
			Matrice[i][j] -= x;

	return *this;
}

Matrix Matrix::operator*=(double x)
{
	
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_columns; j++)

			Matrice[i][j] = Matrice[i][j] * x;
	return *this;
}


Matrix Matrix::operator-=(Matrix Mat)
{
	if (m_rows != Mat.m_rows || m_columns != Mat.m_columns)
	{
		std::cout << "Numarul de coloane sau de linii nu este acelas, deci scaderea nu poate fi realizata";
		return *this;
	}
	
		for (int i = 0; i < m_rows; i++)
			for (int j = 0; j < m_columns; j++)
				Matrice[i][j] -= Mat.Matrice[i][j];

		return *this;
	

	
}

Matrix Matrix::operator*=(Matrix Mat)
{
	if ( m_columns != Mat.m_rows)
	{
		std::cout << "Numarul de coloane snu este acelas cu numarul de linii din a doua matrice, deci inmultiera  nu poate fi realizata";
		return *this;
	}
	matrix m;
	m.resize(m_rows);
	for (int i = 0; i < m_rows; i++)
		m[i].resize(m_columns);
	m = Matrice;
	
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_columns; j++)
			Matrice[i][j] = 0;
     
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < Mat.m_columns; j++)
			for (int k = 0; k <m_columns; k++)
				Matrice[i][j] += m[i][k] * Mat.Matrice[i][k];
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

std::ifstream& operator >> (std::ifstream& f, Matrix& Mat) {
	
	for (int i = 0; i < Mat.m_rows; i++)
		for (int j = 0; j < Mat.m_columns; j++)
			f>>Mat.Matrice[i][j];
	
	return f;

}
std::ofstream& operator <<(std::ofstream& g, Matrix& Mat) {
	
	for (int i = 0; i < Mat.m_rows; i++) {
		for (int j = 0; j < Mat.m_columns; j++)
			g << Mat.Matrice[i][j] << " ";
		g << "\n";
	}
	return g;
}

