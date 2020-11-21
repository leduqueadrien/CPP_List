
#include "List.hpp"

int main(int, char const **)
{
    List l;
    l.display(std::cout);
    l.push_back(1);
    l.push_back(2);
    l.display(std::cout);
    std::cout <<std::endl;
    l.push_front(0);
    l.display(std::cout);
    std::cout <<std::endl;
    return 0;
}
