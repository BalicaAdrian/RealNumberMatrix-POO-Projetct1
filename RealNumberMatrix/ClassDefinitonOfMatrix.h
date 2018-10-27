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
		void afis();


		




	private:
		int m_rows;
		int m_columns;
		matrix Matrice;
		
};