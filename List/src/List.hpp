
#include <iostream>

// On peut aussi utiliser l'amitie entre Cell et list
class Cell {
    private:
        double data;
        Cell * svt;

    public:
        Cell();
        Cell(double);
        Cell(double, Cell *);
        Cell * & getSvt();
        void display(std::ostream) const;

};

class List {
    private:
        Cell * debut;
    
    public:
        List();
        bool empty() const;
        void push_back (double);
        void display(std::ostream) const;
        ~List();
};