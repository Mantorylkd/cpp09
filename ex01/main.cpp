#include "RPN.hpp"

int main(int ac , char **av)
{
    if(ac != 2)
    {
        std::cout << "required example : ./ex01 \"3 2 + 4*\" " << std::endl;
        return 1;
    }
    
    
    RPN r;
    
    if(!r.parseInput(av[1]))
    {
        std::cout << "Error" << std::endl;
        return 1;
    }
    
    std::stack<int , std::vector<int> > c = r.getContainer();
    
    if(c.size() != 1)
    {
        std::cout << "Error" << std::endl;
        return 1;
    } 
    
    std::cout << c.top() << std::endl;
}
