

#include "pch.h"
#include <iostream>
#include "ClassDefinitonOfMatrix.h"
#include <fstream>

int main()
{
	double x;
    Matrix m(3, 3),n(3,3);
	//m.afis();
	/*std::cin >> m;
	std::cout << m << "\n";
	std::cin >> n;
	std::cout << n << "\n";*/
	std::ifstream f("MatriceIn.txt");
	std::ofstream g("MatriceOut.txt");
	f >> x;
	f>> m;
	//std::cout << m << "\n";
	f>> n;
	/*std::cout << n << "\n";
	m += n;
	std::cout << m << "\n"; 
    m -= n;
	std::cout << m << "\n";;
	m*=n;
	std::cout << m << "\n";*/
	g << n << "\n";
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
	g << m << "\n";


	f.close();
	g.close();
    

}

