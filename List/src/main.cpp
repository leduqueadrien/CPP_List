
#include <iostream>
#include "List.hpp"

int main(int, char const **)
{
	List l;
	std::cout << "taille : " << l.size() << std::endl;
	l.display(std::cout);
	l.push_back(1);
	l.push_back(2);
	std::cout << "taille : " << l.size() << std::endl;
	std::cout << l;
	std::cout <<std::endl;
	l.push_front(0);
	std::cout << "taille : " << l.size() << std::endl;
	l.display(std::cout);
	std::cout <<std::endl;
	
	List lCopy(l);
	std::cout <<std::endl;
	std::cout << "taille : " << lCopy.size() << std::endl;
	lCopy.display(std::cout);
	std::cout <<std::endl;

	l.push_back(3);
	lCopy = l;

	std::cout <<std::endl;
	std::cout << "taille : " << lCopy.size() << std::endl;
	lCopy.display(std::cout);
	std::cout <<std::endl;

	return 0;
}
