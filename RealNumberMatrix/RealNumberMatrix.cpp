

#include "pch.h"
#include <iostream>
#include "ClassDefinitonOfMatrix.h"


int main()
{
    Matrix m(3, 3),n(3,3);
	//m.afis();
	std::cin >> m;
	std::cout << m << "\n";
	std::cin >> n;
	std::cout << n << "\n";
	m += n;
	std::cout << m << "\n"; 
    m -= n;
	std::cout << m << "\n";;
	m*=n;
	std::cout << m << "\n";;
    

}

