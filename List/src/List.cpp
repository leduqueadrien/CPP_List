
#include <iostream>
#include "List.hpp"

Cell::Cell() : Cell(0, nullptr) {}

Cell::Cell(double reel) : Cell(reel, nullptr) {}

Cell::Cell(double reel, Cell * suivant) : data(reel), svt(suivant) {}

Cell * & Cell::getSvt(){
    return svt;
}

void Cell::display(std::ostream os) const{
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
        while((*pCell).getSvt() != nullptr)
            pCell = (*pCell).getSvt();
        (*pCell).getSvt() = new Cell(reel);
    }
}

void List::display(std::ostream os) const {
    Cell * pCell = debut;
    while(pCell != nullptr) {
        (*pCell).display(os);
        os << std::endl;
        pCell = (*pCell).getSvt();
    }
}

List::~List() {
    Cell * pCell = debut;
    while(pCell != nullptr) {
        Cell * tmp = (*pCell).getSvt();
        delete pCell;
        pCell = tmp;
    }
}
