
#include <iostream>
#include "List.hpp"

Cell::Cell() : Cell(0, nullptr) {}

Cell::Cell(double reel) : Cell(reel, nullptr) {}

Cell::Cell(double reel, Cell* suivant) : data(reel), next(suivant) {}

Cell::Cell(Cell const& cellCopy) : data(cellCopy.data), next(cellCopy.next) {}

Cell*& Cell::getNext() {
	return next;
}

void Cell::display(std::ostream& os) const{
	os << data;
}

Cell::~Cell() {}

Cell & Cell::operator=(Cell const & cellCopy) {
	if (&cellCopy != this) {
		data = cellCopy.data;
	}
	return *this;
}
		
double Cell::getData() const{
	return data;
}

std::ostream & operator<<(std::ostream & os, Cell const & cell) {
	os << cell.getData();
	return os;
}






List::List() : first(nullptr) {}

List::List(List const & listCopy) : first(nullptr) {
	createCopy(&first, listCopy.first);

}

bool List::empty() const{
	return first == nullptr;
}

void List::push_back(double reel) {
	Cell ** pCell = &first;
	while (*pCell != nullptr)
		pCell = &((**pCell).next);

	try {
		*pCell = new Cell(reel);
	} catch (std::bad_alloc &e) {
		std::cout << e.what() << std::endl;
		throw;
	}
}

void List::push_front(double reel) {
	try {
		first = new Cell(reel, first);
	} catch (std::bad_alloc &e) {
		std::cout << e.what() << std::endl;
		throw;
	}
}


Cell & List::front() {
	return *first;
}

Cell & List::back() {
	if (first == nullptr) {
		return *first;
	} else {
		Cell* pCell = first;
		while ((*pCell).next != nullptr)
			pCell = (*pCell).next;
		return *pCell;
	}
}

int List::size() const {
	int cpt = 0;
	Cell* pCell = first;
	while (pCell != nullptr) {
		pCell = (*pCell).next;
		cpt++;
	}
	return cpt;
}

void List::display(std::ostream& os) const {
	if (first == nullptr) {
		os << "liste vide" << std::endl;
	} else {
		Cell* pCell = first;
		while (pCell != nullptr)
		{
			(*pCell).display(os);
			os << std::endl;
			pCell = (*pCell).next;
		}
	}
}

void List::deleteEndList(Cell ** pCell) {
	Cell * cell = *pCell;
	while (cell != nullptr) {
		Cell * tmp = (*cell).next;
		delete cell;
		cell = tmp;
	}
}

void List::createCopy(Cell ** pStart, Cell * listCopy) {
	Cell * cellCopy = listCopy;
	Cell ** pCell = pStart;
	while(cellCopy != nullptr) {
		try {
			*pCell = new Cell(*cellCopy);
		} catch (std::bad_alloc &e) {
			std::cout << e.what() << std::endl;
			throw;
		}
		pCell = &((**pCell).next);
		cellCopy = (*cellCopy).next;
	}
	*pCell = nullptr;
}

List::~List() {
	deleteEndList(&first);
}

List & List::operator=(List const & listCopy) {
	if (&listCopy != this) {
		Cell ** iterPrevList = &first;
		Cell * iterList = first;
		Cell * iterListCopy = listCopy.first;

		while (iterList != nullptr && iterListCopy != nullptr) {
			(*iterList).data = (*iterListCopy).data;
			iterPrevList = &((*iterList).next);
			iterList = (*iterList).next;
			iterListCopy = (*iterListCopy).next;
		}

		if (iterListCopy == nullptr && iterList != nullptr) {
			deleteEndList(&((*iterList).next));
		} else if (iterList == nullptr && iterListCopy != nullptr) {
			createCopy(iterPrevList, iterListCopy);
		}
	}
	return *this;
}

ItList List::begin() {
	ItList beginItList(first);
	return beginItList;
}

ItList List::end() {
	ItList endItList;
	return endItList;
}

std::ostream & operator<<(std::ostream & os, List const & list) {
	list.display(os);
	return os;
}


ItList::ItList() : ItList(nullptr) {}

ItList::ItList(Cell * _cell) : pCell(_cell) {}

ItList::ItList(ItList const & cpItList) : pCell(cpItList.pCell) {}

bool ItList::equals(const ItList& autre) const{
	return pCell == autre.pCell;
}

double ItList::operator*() {
	if (pCell == nullptr)
		throw std::out_of_range("");
	return (*pCell).getData();
}
double ItList::operator*() const{
	if (pCell == nullptr)
		throw std::out_of_range("");
	return (*pCell).getData();
}

ItList& ItList::operator++() {
	pCell = (*pCell).getNext();
	return *this;
}
ItList ItList::operator++(int) {
	pCell = (*pCell).getNext();
	return *this;
}

bool operator!=(ItList const & It1, ItList const & It2) {
	return It1.equals(It2);
}

