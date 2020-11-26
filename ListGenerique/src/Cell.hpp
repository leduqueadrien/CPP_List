

#ifndef CELL_GEN_HPP
#define CELL_GEN_HPP

#include <iostream>
#include "List.hpp"

template<typename T>
class List;

template<typename T>
class Cell {
    friend class List<T>;
	private:
		T data;
		Cell<T> * next;

	public:
		Cell(T);
		Cell(T, Cell<T> *);
		Cell(Cell<T> const &);
		T & getData();
		Cell<T> * & getNext();
		void display(std::ostream &) const;
		Cell<T> & operator=(Cell<T> const &);
		~Cell();
};

template<typename T>
std::ostream & operator<<(std::ostream &, Cell<T> const &);

#include "Cell.impl.hpp"

#endif