#ifndef RPN_hpp
#define RPN_hpp
#include <iostream>
#include <vector>
#include <stack> 

class RPN
{
    private:
        std::stack<int , std::vector<int> > container;
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator = (const RPN& other);
        ~RPN();
        
        bool    parseInput(const std::string& op);
        std::stack<int , std::vector<int> >   getContainer();
};

#endif