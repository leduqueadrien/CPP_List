
#include <iostream>
#include "List.hpp"

Cell::Cell() : Cell(0, nullptr) {}

Cell::Cell(double reel) : Cell(reel, nullptr) {}

Cell::Cell(double reel, Cell * suivant) : data(reel), svt(suivant) {}

Cell * & Cell::getSvt(){
	return svt;
}

void Cell::display(std::ostream & os) const{
	os << data;
}



List::List() : debut(nullptr) {}

bool List::empty() const{
	return debut == nullptr;
}

void List::push_back (double reel) {
	if (debut == nullptr) {
		debut = new Cell(reel);
	} else {
		Cell * pCell = debut;
		while((*pCell).svt != nullptr)
			pCell = (*pCell).svt;
		(*pCell).svt = new Cell(reel);
	}
}

void List::push_front(double reel) {
	if (debut == nullptr) {
		debut = new Cell(reel);
	} else {
		Cell * tmp = debut;
		debut = new Cell(reel, tmp);
	}
}

Cell & List::front() {
	return *debut;
}

Cell & List::back() {
	if (debut == nullptr) {
		throw std::invalid_argument("");
	} else {
		Cell * pCell = debut;
		while((*pCell).svt != nullptr)
			pCell = (*pCell).svt;
		return *pCell;
	}
}

void List::display(std::ostream & os) const {
	if (debut == nullptr) {
		os << "liste vide" << std::endl;
	} else {
		Cell * pCell = debut;
		while(pCell != nullptr) {
			(*pCell).display(os);
			os << std::endl;
			pCell = (*pCell).svt;
		}
	}
}

List::~List() {
	Cell * pCell = debut;
	while(pCell != nullptr) {
		Cell * tmp = (*pCell).svt;
		delete pCell;
		pCell = tmp;
	}
}
