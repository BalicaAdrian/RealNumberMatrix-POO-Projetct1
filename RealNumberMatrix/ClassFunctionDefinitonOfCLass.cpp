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
		throw std::runtime_error("Number of rows isn't equal with the number of columns ");
	
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
		throw std::runtime_error("Number of rows isn't equal with the number of columns ");
		
         for (int i = 0; i < m_rows; i++)
			for (int j = 0; j < m_columns; j++)
				Matrice[i][j] -= Mat.Matrice[i][j];

		return *this;
	

	
}

Matrix Matrix::operator*=(Matrix& Mat)
{
	if ( m_columns != Mat.m_rows)
		throw std::runtime_error( "Number of columns from the first Matrix isn't equal with the numver of rows from the second one");
	
	matrix Mat1;
	
	Mat1.resize(m_rows);
	
	for (int i = 0; i < m_rows; i++)
		Mat1[i].resize(Mat.m_columns);

	Mat1 = Matrice;
	

	
	for (int i = 0; i < m_rows; i++)
		Matrice[i].resize(Mat.m_columns);

	for (int i = 0; i <m_rows; i++)
		for (int j = 0; j < Mat.m_columns; j++)
			Matrice[i][j] = 0;
     
	for (int i = 0; i <m_rows; i++)
		for (int j = 0; j < Mat.m_columns; j++)
			for (int k = 0; k <m_columns; k++)
				Matrice[i][j] += Mat1[i][k] * Mat.Matrice[k][j];
	m_columns = Mat.m_columns;
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
	try {
		Mat3 += Mat2;
	}
	catch (std::runtime_error)
	{
		throw std::runtime_error("Number of rows isn't equal with the number of columns  ");
	}
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
	try {
		Mat3 -= Mat2;
	}
	catch (std::runtime_error)
	{
		throw std::runtime_error("Number of rows isn't equal with the number of columns  ");
	}
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
	try {
		Mat3 *= Mat2;
	}
	catch (std::runtime_error) {
		throw std::runtime_error("Number of columns from the first Matrix isn't equal with the numver of rows from the second one");
	}
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
		throw std::runtime_error("Division to 0 is impossible ");
		
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
			throw std::runtime_error("Division to 0 is impossible ");
			
		
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
			throw std::runtime_error("Number of rows isn't equal with the number of columns ");
		if (x < 0)
			throw std::runtime_error("The number can't be negative ");
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
			return false ;
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

	Matrix Matrix::operator [] (int x)
	{
		if (x<0 || x>=m_rows)
			throw std::runtime_error("The row does not exist \n");

		if (m_rows == 1)
		{
			Matrix Mat;
			Mat.Matrice[0][0] = Matrice[0][x];
			return Mat;
		}

		if (m_columns == 1)
		{
			Matrix Mat;
			Mat.Matrice[0][0] = Matrice[x][0];
			return Mat;
		}
			Matrix Mat(1, m_columns);
			for (int j = 0; j < m_columns; j++)
				Mat.Matrice[0][j] = Matrice[x][j];
		return Mat;
	}