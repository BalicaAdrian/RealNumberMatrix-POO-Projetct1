#include "pch.h"
#include <iostream>
#include "Matrix.h"
#include <fstream>

int main()
{
	double x,element;    // x eeste valaore pentru operatii cu double iar element este pentru preluarea unui element din matrice cu getElement
	int rows, columns;   //Variabile pentru verificare geter
	Matrix m(3,3),n(3,3),z;
	//Matrix n(m);
	//m.afis();
	/*std::cin >> m;
	std::cout << m << "\n";
	std::cin >> n;
	std::cout << n << "\n";*/
	std::ifstream f("MatriceIn.txt");
	std::ofstream g("MatriceOut.txt");
	
	
	
	f >> m;
	f >> x;
	/*try {
		z = m[0];
	}
	catch (std::runtime_error const e) {
		std::cout << e.what() << "\n";
	}
	std::cout << z <<"\n";
	try {
		z = m ^ 2;
	}
	catch (std::runtime_error const e) {
		std::cout << e.what() << "\n";
	}
	std::cout << z << "\n";

	try {
		z = m / 0;
	}
	catch (std::runtime_error const e) {
		std::cout << e.what() << "\n";
	}
	std::cout << z << "\n";

	/*try {
		n-=m;
	}
	catch (std::runtime_error const e) {
		std::cout << e.what() << "\n";
	}
	std::cout << n << "\n";

	try {
		n += m;
	}
	catch (std::runtime_error const e) {
		std::cout << e.what() << "\n";
	}
	std::cout << n << "\n"; */
	try {
		m/=x;
	}
	catch (std::runtime_error const e) {
		std::cout << e.what() << "\n";
	}
    std::cout << m;


	f.close();
	g.close();
    

}

