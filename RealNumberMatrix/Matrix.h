#pragma once

#include "pch.h"
#include<vector>
#include<iostream>



class Matrix{
	 
	public:
   typedef std::vector <std::vector<double>> matrix;
		void get_columns();
		void get_rows();
		void init();
		Matrix(int rows = 1,int columns=1);
		Matrix(Matrix&);
		~Matrix();
		//void afis();
		int getRows();
		int getColumns();
		double getElement(int,int);
		friend std::istream& operator >> (std::istream&, Matrix&);
		friend std::ostream& operator << (std::ostream&, Matrix&);
		friend std::ifstream& operator >> (std::ifstream&, Matrix&);
		friend std::ofstream& operator << (std::ofstream&, Matrix&);
		Matrix& operator += (Matrix&);
		Matrix& operator -= (Matrix&);
		Matrix& operator *= (Matrix&);
		Matrix& operator += (double);
		Matrix& operator -= (double);
		Matrix& operator *= (double);
		Matrix& operator /=(double);
		Matrix operator + ();
		Matrix operator - ();
		friend Matrix operator + (Matrix, Matrix);
		friend Matrix operator + (Matrix, double);
		friend Matrix operator + (double, Matrix);
		friend Matrix operator - (Matrix, Matrix);
		friend Matrix operator - (Matrix, double);
		friend Matrix operator - (double, Matrix);
		friend Matrix operator * (Matrix, Matrix);
		friend Matrix operator * (Matrix, double);
		friend Matrix operator * (double, Matrix);
		friend Matrix operator / (Matrix, double);
		friend Matrix operator / (double, Matrix);
		friend Matrix operator ^ (Matrix,double);
		friend bool operator == (Matrix, Matrix);
		friend bool operator != (Matrix, Matrix);
		Matrix operator [](int);
	private:
		int m_rows;
		int m_columns;
		matrix m_Matrice;
		
};