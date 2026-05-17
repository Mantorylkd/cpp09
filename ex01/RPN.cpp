#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : container(other.container){}


RPN&   RPN::operator = (const RPN& other)
{
    if(this != &other)
    {
        this->container = other.container;
    }
    return *this;
}

RPN::~RPN(){}


bool RPN::parseInput(const std::string& op)
{
    int i = 0;
    while(op[i])
    {
        if(op[i] == ' ')
        {
            i++;
            continue;
        }

        else if(!std::isdigit(op[i]))
        {
            if(op[i] != '-' && op[i] != '+' && op[i] != '*' && op[i] != '/')
                return false;
            else
            {
                if(container.size() < 2)
                    return false ;
                else
                {
                    int a = container.top();
                    container.pop();
                    
                    int b = container.top();
                    container.pop();
                    
                    int result;

                    if(op[i] == '-')
                        result = b - a;

                    else if(op[i] == '+')
                        result = b + a;

                    else if(op[i] == '*')
                        result = b * a;

                    else if(op[i] == '/')
                    {
                        if(a == 0)
                            return false;
                    
                        result = b / a;
                    }

                    container.push(result);
                    
                    if(op[i + 1] && op[i + 1] != ' ')
                        return false;
                    
                    i++;
                    continue;
                }
            }
        }
        else
        {
            int digit = op[i] - '0';
            container.push(digit);

            if(op[i + 1] && op[i +1] != ' ')
                return false;
            i++;
        }
    }
    return true;
}


std::stack<int , std::vector<int> >   RPN::getContainer()
{
    return container;
} 
