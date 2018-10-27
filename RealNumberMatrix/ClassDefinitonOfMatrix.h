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
		Matrix(int rows = 0,int columns=0);
		~Matrix();
		//void afis();

		friend std::istream& operator >> (std::istream&, Matrix&);
		friend std::ostream& operator << (std::ostream&, Matrix&);
		Matrix operator += (Matrix);
		Matrix operator -= (Matrix);
		Matrix operator *= (Matrix);




	private:
		int m_rows;
		int m_columns;
		matrix Matrice;
		
};