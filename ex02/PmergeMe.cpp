#include "PmergeMe.hpp"


bool    PmergeMe::StoreInt(const std::string& a)
{
    int i = 0;
    while(a[i])
    {
        if(a[i] == ' ')
        {
            i++;
            continue;
        }
        if(!std::isdigit(a[i]))
        {
            return false;
        }
        else
        {
            int number = a[i] - '0';
            vct.push_back(number);
            dq.push_back(number);
            i++;
        }
    }
    
    std::vector<int>::iterator vector_it;
    // std::deque<int>::iterator deque_it;


    for(vector_it = vct.begin() ; vector_it != vct.end(); ++vector_it)
    {
        std::cout << *vector_it << std::endl;
    }

    // for(deque_it = dq.begin() ; deque_it != dq.end(); ++deque_it)
    // {
    //     std::cout << *deque_it << std::endl;
    // }
    return true;
}
