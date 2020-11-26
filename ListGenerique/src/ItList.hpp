

#ifndef ITLIST_GEN_HPP
#define ITLIST_GEN_HPP

#include "Cell.hpp"
#include "List.hpp"

template<typename T>
class List;

template<typename T>
class ItList {
	friend class List<T>;
	private :
		Cell<T> * pCell;
		ItList(Cell<T> *);
	public :
		ItList(ItList<T> const &);
		ItList();
		bool equals(const ItList<T>&) const;
		T & operator*() const;
		T & operator*();
		ItList<T>& operator++();    // version préfixée
		ItList<T>& operator++(int);  // version postfixée
};

template<typename T>
bool operator!=(ItList<T> const &, ItList<T> const &);

#include "ItList.impl.hpp"

#endif