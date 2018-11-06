#include "pch.h"
#include "Matrix.h"
#include<vector>
#include<fstream>

void Matrix::init()
{
	m_Matrice.resize(m_rows);
	for (int i = 0; i < m_rows; i++)
		m_Matrice[i].resize(m_columns);


}

/*void Matrix::afis()
{
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_columns; j++)
			std::cout << m_Matrice[i][j] << " ";
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
				m_Matrice[i][j] = 1;
}
//Destructor
Matrix::~Matrix() {
	
	for (int i = 0; i < m_rows; i++)
		m_Matrice[i].erase(m_Matrice[i].begin(), m_Matrice[i].begin()+m_columns);
	m_Matrice.erase(m_Matrice.begin(), m_Matrice.begin() + m_rows);
		
		
}

//Constructor de copiere
Matrix::Matrix(Matrix& NewObject) 
{
	m_rows = NewObject.m_rows;
	m_columns = NewObject.m_columns;
	init();
	m_Matrice = NewObject.m_Matrice;

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
	return m_Matrice[i][j];
}
//Overloaded Operators
Matrix& Matrix::operator += (Matrix&  NewObject)
{
	if (m_rows != NewObject.m_rows || m_columns != NewObject.m_columns)
		throw std::runtime_error("Number of rows isn't equal with the number of columns ");
	
for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_columns; j++)
			m_Matrice[i][j] += NewObject.m_Matrice[i][j];

	return *this;
}



Matrix& Matrix::operator += (double number)
{
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_columns; j++)
			m_Matrice[i][j] += number;

	return *this;
}

Matrix& Matrix::operator -= (double number)
{
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_columns; j++)
			m_Matrice[i][j] -= number;

	return *this;
}

Matrix& Matrix::operator*=(double number)
{
	
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_columns; j++)

			m_Matrice[i][j] = m_Matrice[i][j] * number;
	return *this;
}
Matrix & Matrix::operator/=(double number)
{
	if (number == 0)
		throw std::runtime_error("Division to 0 is impossible ");
	else
		for (int i = 0; i < m_rows; i++)
			for (int j = 0; j < m_columns; j++)

				m_Matrice[i][j] = m_Matrice[i][j] / number;
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



Matrix& Matrix::operator-=(Matrix&  NewObject)
{
	if (m_rows != NewObject.m_rows || m_columns != NewObject.m_columns)
		throw std::runtime_error("Number of rows isn't equal with the number of columns ");
		
         for (int i = 0; i < m_rows; i++)
			for (int j = 0; j < m_columns; j++)
				m_Matrice[i][j] -= NewObject.m_Matrice[i][j];

		return *this;
	

	
}

Matrix& Matrix::operator*=(Matrix&  NewObject)
{
	if ( m_columns !=  NewObject.m_rows)
		throw std::runtime_error( "Number of columns from the first Matrix isn't equal with the numver of rows from the second one");
	
	matrix  NewMatrix;
	
	NewMatrix.resize(m_rows);
	
	for (int i = 0; i < m_rows; i++)
		NewMatrix[i].resize( NewObject.m_columns);

	NewMatrix = m_Matrice;
	

	
	for (int i = 0; i < m_rows; i++)
		m_Matrice[i].resize( NewObject.m_columns);

	for (int i = 0; i <m_rows; i++)
		for (int j = 0; j < NewObject.m_columns; j++)
			m_Matrice[i][j] = 0;
     
	for (int i = 0; i <m_rows; i++)
		for (int j = 0; j < NewObject.m_columns; j++)
			for (int k = 0; k <m_columns; k++)
				m_Matrice[i][j] += NewMatrix[i][k] * NewObject.m_Matrice[k][j];
	m_columns = NewObject.m_columns;
	return *this;
}


//Read and write operators
std::istream& operator >> (std::istream& stream, Matrix& Object)
{
	for (int i=0; i < Object.m_rows; i++)
		for (int j=0; j < Object.m_columns; j++)
			stream >> Object.m_Matrice[i][j];
	return stream;
}

std::ostream& operator << (std::ostream& stream, Matrix& Object)
{
	for (int i=0; i < Object.m_rows; i++){
		for (int j=0; j < Object.m_columns; j++)
			stream << Object.m_Matrice[i][j] << " ";
			stream << "\n";
		}
			return stream;
}

std::ifstream& operator >> (std::ifstream& stream, Matrix& Object) {
	
	for (int i = 0; i < Object.m_rows; i++)
		for (int j = 0; j < Object.m_columns; j++)
			stream>> Object.m_Matrice[i][j];
	
	return stream;

}
std::ofstream& operator <<(std::ofstream& stream, Matrix& Object) {
	
	for (int i = 0; i < Object.m_rows; i++) {
		for (int j = 0; j < Object.m_columns; j++)
			stream << Object.m_Matrice[i][j] << " ";
		stream << "\n";
	}
	return stream;
}

//Binary operators
Matrix operator + (Matrix  Object1, Matrix Object2)
{
	Matrix Result(Object1);
	try {
		Result += Object2;
	}
	catch (std::runtime_error)
	{
		throw std::runtime_error("Number of rows isn't equal with the number of columns  ");
	}
	return  Result;
}

Matrix operator + (Matrix Object, double number)
{
	Matrix  Result(Object);
	Result += number;
	return  Result;

}

Matrix operator + (double number, Matrix Object)
{
	Matrix Result(Object);
	Result += number;
	return  Result;

}


Matrix operator - (Matrix  Object1, Matrix Object2)
{
	Matrix Result(Object1);
	try {
		Result -= Object2;
	}
	catch (std::runtime_error)
	{
		throw std::runtime_error("Number of rows isn't equal with the number of columns  ");
	}
			return  Result;
}

Matrix operator - (Matrix Object, double number)
{
	Matrix Result(Object);
	Result -= number;
	return Result;

}

Matrix operator - (double number, Matrix Object1)
{
	Matrix  Result(Object1);
	Result -= number;
	return  Result;

}


Matrix operator * (Matrix  Object1, Matrix Object2)
{
	Matrix  Result(Object1);
	try {
		Result *= Object2;
	}
	catch (std::runtime_error) {
		throw std::runtime_error("Number of columns from the first Matrix isn't equal with the numver of rows from the second one");
	}
	return Result;
}

Matrix operator * (Matrix Object, double number)
{
	Matrix  Result(Object);
	Result *= number;
	return  Result;

}

Matrix operator * (double number, Matrix Object)
{
	Matrix  Result(Object);
	Result *= number;
	return  Result;

}

Matrix operator / (Matrix Object, double number)
{ 
	if (number == 0)
		throw std::runtime_error("Division to 0 is impossible ");
		
	else
	{
		Matrix  Result(Object);
		for (int i = 0; i < Object.m_rows; i++)
			for (int j = 0; j < Object.m_columns; j++)
				Result.m_Matrice[i][j] = Result.m_Matrice[i][j] / number;
		return  Result;
	}
}

	Matrix operator / (double number, Matrix Object)
	{
		if (number == 0)
			throw std::runtime_error("Division to 0 is impossible ");
			
		
		else
		{
			Matrix  Result(Object);
			for (int i = 0; i < Object.m_rows; i++)
				for (int j = 0; j < Object.m_columns; j++)
					Result.m_Matrice[i][j] = Result.m_Matrice[i][j] / number;
			return  Result;
		}
	}

	Matrix operator ^ (Matrix Object,double number)
	{
		if (Object.m_rows != Object.m_columns)
			throw std::runtime_error("Number of rows isn't equal with the number of columns ");
		if (number < 0)
			throw std::runtime_error("The number can't be negative ");
		if (number == 0)
		{
			Matrix  Result1;
			return  Result1;
		}
		else if (number == 1)
		{
			return Object;
		}
		else 
		{
			Matrix  Result(Object);
			for (int i = 2; i <= number; i++)
				Result *= Object;
			
			return  Result;

		}
	}

	bool operator == (Matrix Object1, Matrix Object2) 
	{
		if (Object1.m_rows != Object2.m_rows || Object1.m_columns != Object2.m_columns)
			return false ;
		for (int i = 0; i < Object1.m_rows; i++)
			for (int j = 0; j < Object1.m_columns; j++)
				if (Object1.m_Matrice[i][j] != Object2.m_Matrice[i][j])
					return 0;
		return 1;
	}

	bool operator != (Matrix Object1, Matrix Object2)
	{
		if(Object1==Object2)
					return 0;
		return 1;
	}

	Matrix Matrix::operator [] (int number)
	{
		if (number<0 || number>=m_rows)
			throw std::runtime_error("The row does not exist \n");

		if (m_rows == 1)
		{
			Matrix Result;
			Result.m_Matrice[0][0] = m_Matrice[0][number];
			return Result;
		}

		if (m_columns == 1)
		{
			Matrix Result;
			Result.m_Matrice[0][0] = m_Matrice[number][0];
			return Result;
		}
			Matrix Result(1, m_columns);
			for (int j = 0; j < m_columns; j++)
				Result.m_Matrice[0][j] = m_Matrice[number][j];
		return Result;
	}