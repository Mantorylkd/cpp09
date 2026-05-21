#include "PmergeMe.hpp"

bool PmergeMe::storeInt(const std::string& str)
{
    std::stringstream ss(str);

    int number;

    while(ss >> number)
    {
        vct.push_back(number);
        dq.push_back(number);
    }

    if(ss.fail() && !ss.eof())
        return false;

    return true;
}

std::vector<int> PmergeMe::getVector()
{
    return vct;
}

std::deque<int> PmergeMe::getDeque()
{
    return dq;
}