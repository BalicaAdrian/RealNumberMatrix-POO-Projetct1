

#include "pch.h"
#include <iostream>
#include "ClassDefinitonOfMatrix.h"
#include <fstream>

int main()
{
	double x,element;    // x eeste valaore pentru operatii cu double iar element este pentru preluarea unui element din matrice cu getElement
	int rows, columns;   //Variabile pentru verificare geter
	Matrix m(3, 3),n(3,3),z;
	//Matrix n(m);
	//m.afis();
	/*std::cin >> m;
	std::cout << m << "\n";
	std::cin >> n;
	std::cout << n << "\n";*/
	std::ifstream f("MatriceIn.txt");
	std::ofstream g("MatriceOut.txt");
	
	//f >> x;
	//f>> m;
	//std::cout << n;
	//rows = m.getRows();
	//columns = m.getColumns();
	//element = m.getElement(2, 2);
	//std::cout << rows << " " << columns << " " << element;
	//std::cout << n;
	//std::cout << m << "\n";
	//f>> n;
	/*std::cout << n << "\n";
	m += n;
	std::cout << m << "\n"; 
    m -= n;
	std::cout << m << "\n";;
	m*=n;
	std::cout << m << "\n";*/
	/*g << n << "\n";
	m += n;
	g<< m << "\n";
	m -= n;
	g << m << "\n";;
	m *= n;
	g << m << "\n";
	m += x;
	g << m << "\n";
	m -= x;
	g << m << "\n";
	m *= x;
	g << m << "\n";*/

	f >> x;
	f >> m;
	z = x/m;
	std::cout << z;


	f.close();
	g.close();
    

}

