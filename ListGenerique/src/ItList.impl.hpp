
#include "ItList.hpp"

template<typename T>
ItList<T>::ItList() : ItList(nullptr) {}

template<typename T>
ItList<T>::ItList(Cell<T> * _cell) : pCell(_cell) {}

template<typename T>
ItList<T>::ItList(ItList<T> const & cpItList) : pCell(cpItList.pCell) {}

template<typename T>
bool ItList<T>::equals(ItList const & autre) const{
	return pCell == autre.pCell;
}

template<typename T>
T & ItList<T>::operator*() {
	if (pCell == nullptr)
		throw std::out_of_range("");
	return (*pCell).getData();
}

template<typename T>
T & ItList<T>::operator*() const{
	if (pCell == nullptr)
		throw std::out_of_range("out of range");
	return (*pCell).getData();
}

template<typename T>
ItList<T>& ItList<T>::operator++() {
	pCell = (*pCell).getNext();
	return *this;
}

template<typename T>
ItList<T>& ItList<T>::operator++(int) {
	pCell = (*pCell).getNext();
	return *this;
}

template<typename T>
bool operator!=(ItList<T> const & It1, ItList<T> const & It2) {
	return !It1.equals(It2);
}
