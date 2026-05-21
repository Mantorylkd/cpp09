#ifndef PmergeMe_hpp
#define PmergeMe_hpp
#include <vector>
#include <deque>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>

class PmergeMe
{
    private:
        std::vector<int> vct;
        std::deque <int> dq;
    
    public :
        bool    storeInt(const std::string& a);
        std::vector<int>    getContainer();
        std::vector<int>    splitVector(std::vector<int>& containr);
        std::vector<int>    MergeSort(std::vector<int>& a , std::vector<int>& b);
        std::vector< std::pair<int, int> > makePairs(std::vector<int>& container);
        std::vector<int>    makeChains(std::vector <std::pair<int, int> > & pairs , std::vector <int> first , std::vector <int> second);
};

#endif