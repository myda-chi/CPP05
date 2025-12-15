#include "Bureaucrat.hpp"

int main()
{
    try{
        Bureaucrat *yda = new Bureaucrat("mydachi", 2);
        std::cout << *yda;
        yda->decrementGrade();
        std::cout << *yda;
        yda->decrementGrade();
        std::cout << *yda;
        delete yda;
    }
    catch (std::exception& b)
    {
        std::cout << b.what();
    }
}