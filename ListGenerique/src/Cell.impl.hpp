
#include "Cell.hpp"

template<typename T>
Cell<T>::Cell(T _data) : Cell(_data, nullptr) {}

template<typename T>
Cell<T>::Cell(T _data, Cell<T>* suivant) : data(_data), next(suivant) {}

template<typename T>
Cell<T>::Cell(Cell<T> const& cellCopy) : data(cellCopy.data), next(cellCopy.next) {}

template<typename T>
Cell<T>*& Cell<T>::getNext() {
	return next;
}

template<typename T>
void Cell<T>::display(std::ostream& os) const{
	os << data;
}

template<typename T>
Cell<T>::~Cell() {}

template<typename T>
Cell<T> & Cell<T>::operator=(Cell<T> const & cellCopy) {
	if (&cellCopy != this) {
		data = cellCopy.data;
	}
	return *this;
}

template<typename T>
T & Cell<T>::getData() {
	return data;
}

template<typename T>
std::ostream & operator<<(std::ostream & os, Cell<T> const & cell) {
	os << cell.getData();
	return os;
}

