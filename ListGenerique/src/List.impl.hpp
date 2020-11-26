
#include <iostream>
#include "List.hpp"

template<typename T>
List<T>::List() : first(nullptr) {}

template<typename T>

List<T>::List(List<T> const & listCopy) : first(nullptr) {
	createCopy(&first, listCopy.first);

}

template<typename T>
bool List<T>::empty() const{
	return first == nullptr;
}

template<typename T>
void List<T>::push_back(T const & _data) {
	Cell<T> ** pCell = &first;
	while (*pCell != nullptr)
		pCell = &((**pCell).next);

	try {
		*pCell = new Cell<T>(_data);
	} catch (std::bad_alloc &e) {
		std::cout << e.what() << std::endl;
		throw;
	}
}

template<typename T>
void List<T>::push_front(T const & _data) {
	try {
		first = new Cell<T>(_data, first);
	} catch (std::bad_alloc &e) {
		std::cout << e.what() << std::endl;
		throw;
	}
}


template<typename T>
Cell<T> & List<T>::front() {
	return *first;
}

template<typename T>
Cell<T> & List<T>::back() {
	if (first == nullptr) {
		return *first;
	} else {
		Cell<T>* pCell = first;
		while ((*pCell).next != nullptr)
			pCell = (*pCell).next;
		return *pCell;
	}
}

template<typename T>
int List<T>::size() const {
	int cpt = 0;
	Cell<T>* pCell = first;
	while (pCell != nullptr) {
		pCell = (*pCell).next;
		cpt++;
	}
	return cpt;
}

template<typename T>
void List<T>::display(std::ostream& os) const {
	if (first == nullptr) {
		os << "liste vide" << std::endl;
	} else {
		Cell<T>* pCell = first;
		while (pCell != nullptr)
		{
			(*pCell).display(os);
			os << std::endl;
			pCell = (*pCell).next;
		}
	}
}

template<typename T>
void List<T>::deleteEndList(Cell<T> ** pCell) {
	Cell<T> * cell = *pCell;
	while (cell != nullptr) {
		Cell<T> * tmp = (*cell).next;
		delete cell;
		cell = tmp;
	}
}

template<typename T>
void List<T>::createCopy(Cell<T> ** pStart, Cell<T> * listCopy) {
	Cell<T> * cellCopy = listCopy;
	Cell<T> ** pCell = pStart;
	while(cellCopy != nullptr) {
		try {
			*pCell = new Cell<T>(*cellCopy);
		} catch (std::bad_alloc &e) {
			std::cout << e.what() << std::endl;
			throw;
		}
		pCell = &((**pCell).next);
		cellCopy = (*cellCopy).next;
	}
	*pCell = nullptr;
}

template<typename T>
List<T>::~List() {
	deleteEndList(&first);
}

template<typename T>
List<T> & List<T>::operator=(List<T> const & listCopy) {
	if (&listCopy != this) {
		Cell<T> ** iterPrevList = &first;
		Cell<T> * iterList = first;
		Cell<T> * iterListCopy = listCopy.first;

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

template<typename T>
ItList<T> List<T>::begin() {
	ItList<T> beginItList(first);
	return beginItList;
}

template<typename T>
ItList<T> List<T>::end() {
	ItList<T> endItList(nullptr);
	return endItList;
}

template<typename T>
std::ostream & operator<<(std::ostream & os, List<T> const & list) {
	list.display(os);
	return os;
}

