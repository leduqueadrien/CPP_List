

#ifndef LIST_GEN_HPP
#define LIST_GEN_HPP

#include <iostream>
#include "Cell.hpp"
#include "ItList.hpp"

template<typename T>
class ItList;

template<typename T>
class List {
	friend class ItList<T>;
	private:
		Cell<T> * first;
	
	public:
		List();
		List(List<T> const &);
		~List();

		bool empty() const;
		void push_back(T const &);
		void push_front(T const &);
		Cell<T> & front();
		Cell<T> & back();
		int size() const;
		void display(std::ostream &) const;
		void deleteEndList(Cell<T> **);
		void createCopy(Cell<T> **, Cell<T> * const);

		ItList<T> begin();
		ItList<T> end();

		List<T> & operator=(List<T> const &);

};

template<typename T>
std::ostream & operator<<(std::ostream &, List<T> const &);

#include "List.impl.hpp"

#endif
