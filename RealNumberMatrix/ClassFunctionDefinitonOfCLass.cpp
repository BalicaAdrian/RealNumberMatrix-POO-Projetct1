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
//Constructor Parametrizat
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
//Destructor
Matrix::~Matrix() {
	
	for (int i = 0; i < m_rows; i++)
		Matrice[i].erase(Matrice[i].begin(), Matrice[i].begin()+m_columns);
	Matrice.erase(Matrice.begin(), Matrice.begin() + m_rows);
		
		
}

//Constructor de copiere
Matrix::Matrix(Matrix& Mat) 
{
	m_rows = Mat.m_rows;
	m_columns = Mat.m_columns;
	init();
	Matrice = Mat.Matrice;

}

int Matrix::getRows()
{
	return m_rows;
}

int Matrix::getColumns()
{
	return m_columns;
}

double Matrix::getElement(int i, int j)
{
	return Matrice[i][j];
}
//Overloaded Operators
Matrix Matrix::operator += (Matrix& Mat)
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
//Unary operators overloaded
Matrix Matrix::operator+()
{
	return *this;
}

Matrix Matrix::operator-()
{
	return *this;
}



Matrix Matrix::operator-=(Matrix& Mat)
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

Matrix Matrix::operator*=(Matrix& Mat)
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


//Read and write operators
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

//Binary operators
Matrix operator + (Matrix  Mat1, Matrix Mat2)
{
	Matrix Mat3(Mat1);
	Mat3 += Mat2;
	return Mat3;
}

Matrix operator + (Matrix Mat1, double x)
{
	Matrix Mat2(Mat1);
	Mat2 += x;
	return Mat2;

}

Matrix operator + (double x, Matrix Mat1)
{
	Matrix Mat2(Mat1);
	Mat2 += x;
	return Mat2;

}


Matrix operator - (Matrix  Mat1, Matrix Mat2)
{
	Matrix Mat3(Mat1);
	Mat3 -= Mat2;
	return Mat3;
}

Matrix operator - (Matrix Mat1, double x)
{
	Matrix Mat2(Mat1);
	Mat2 -= x;
	return Mat2;

}

Matrix operator - (double x, Matrix Mat1)
{
	Matrix Mat2(Mat1);
	Mat2 -= x;
	return Mat2;

}


Matrix operator * (Matrix  Mat1, Matrix Mat2)
{
	Matrix Mat3(Mat1);
	Mat3 *= Mat2;
	return Mat3;
}

Matrix operator * (Matrix Mat1, double x)
{
	Matrix Mat2(Mat1);
	Mat2 *= x;
	return Mat2;

}

Matrix operator * (double x, Matrix Mat1)
{
	Matrix Mat2(Mat1);
	Mat2 *= x;
	return Mat2;

}

Matrix operator / (Matrix Mat1, double x)
{ 
	if (x == 0)
	{
		std::cout << "Impartirea este imposibila la 0";
		
		Matrix Mat2(Mat1);

		return Mat2;
	}
	else
	{
		Matrix Mat2(Mat1);
		for (int i = 0; i < Mat1.m_rows; i++)
			for (int j = 0; j < Mat1.m_columns; j++)
				Mat2.Matrice[i][j] = Mat2.Matrice[i][j] / x;
		return Mat2;
	}
}

	Matrix operator / (double x, Matrix Mat1)
	{
		if (x == 0)
		{
			std::cout << "Impartirea este imposibila la 0";
			
			Matrix Mat2(Mat1);

			return Mat2;
		}
		else
		{
			Matrix Mat2(Mat1);
			for (int i = 0; i < Mat1.m_rows; i++)
				for (int j = 0; j < Mat1.m_columns; j++)
					Mat2.Matrice[i][j] = Mat2.Matrice[i][j] / x;
			return Mat2;
		}
	}

	Matrix operator ^ (Matrix Mat1,double x)
	{
		if (Mat1.m_rows != Mat1.m_columns)
			throw std::exception();
		if (x < 0)
			throw std::exception();
		if (x == 0)
		{
			Matrix Mat2;
			return Mat2;
		}
		else if (x == 1)
		{
			return Mat1;
		}
		else 
		{
			Matrix Mat2(Mat1);
			for (int i = 2; i <= x; i++)
				Mat2 *= Mat1;
			
			return Mat2;

		}
	}

	bool operator == (Matrix Mat1, Matrix Mat2) 
	{
		if (Mat1.m_rows != Mat2.m_rows || Mat1.m_columns != Mat2.m_columns)
			return -1;
		for (int i = 0; i < Mat1.m_rows; i++)
			for (int j = 0; j < Mat1.m_columns; j++)
				if (Mat1.Matrice[i][j] != Mat2.Matrice[i][j])
					return 0;
		return 1;
	}

	bool operator != (Matrix Mat1, Matrix Mat2)
	{
		if(Mat1==Mat2)
					return 0;
		return 1;
	}