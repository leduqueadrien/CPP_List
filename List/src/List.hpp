
#include <iostream>

class Cell {
    friend class List;
	private:
		double data;
		Cell * next;

	public:
		Cell();
		Cell(double);
		Cell(double, Cell *);
		Cell(Cell const &);
		double getData() const;
		Cell * & getNext();
		void display(std::ostream &) const;
		Cell & operator=(Cell const &);
		~Cell();

};

class ItList;

class List {
	friend class ItList;
	private:
		Cell * first;
	
	public:
		List();
		List(List const &);
		~List();

		bool empty() const;
		void push_back(double);
		void push_front(double);
		Cell * createCell(double);
		Cell & front();
		Cell & back();
		int size() const;
		void display(std::ostream &) const;
		void deleteEndList(Cell **);
		void createCopy(Cell **, Cell * const);

		ItList begin();
		ItList end();

		List & operator=(List const &);

};

class ItList {
	friend class List;
	private :
		Cell * pCell;
		ItList(Cell *);
	public :
		ItList(ItList const &);
		ItList();
		bool equals(const ItList&) const;
		double operator*() const;
		double operator*();
		ItList& operator++();    // version préfixée
		ItList operator++(int);  // version postfixée
};

std::ostream & operator<<(std::ostream &, Cell const &);
std::ostream & operator<<(std::ostream &, List const &);
bool operator!=(ItList const &, ItList const &);