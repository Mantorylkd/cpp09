#ifndef PmergeMe_hpp
#define PmergeMe_hpp
#include <vector>
#include <deque>
#include <iostream>
#include <cstdlib>

class PmergeMe
{
    private:
        std::vector<int> vct;
        std::deque <int> dq;
    public :
        bool   StoreInt(const std::string& a);

};
#endif