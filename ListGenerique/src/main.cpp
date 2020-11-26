
#include <iostream>
#include "List.hpp"
#include "ItList.hpp"

int main(int, char const **)
{
	List<int> l1;
	l1.display(std::cout);
	l1.push_back(1);
	l1.push_front(2);
	l1.push_back(3);
	l1.display(std::cout);

	

	ItList<int> it = l1.begin();
	while (it!=l1.end()) {
		std::cout << *it;
		++it;
	}


	return 0;
}
