#ifndef PMERGEME_VECTOR_HPP
#define PMERGEME_VECTOR_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <ctime>

class PmergeMe
{
    private:

        std::vector<int> vct;
        bool hasStraggler;
        int  straggler;

    public:
        PmergeMe();
        bool                storeInt(const std::string& str);
        std::vector<int>    getVector();
        bool                checkDuplicate(std::vector<int>& container);
        std::vector<int>    mergeChains(std::vector<int>& left,std::vector<int>& right);
        std::vector<int>    splitChain(std::vector<int>& container);
        std::vector< std::pair<int, int> >      makePairs(std::vector<int>& container);
        void                makeChains(std::vector< std::pair<int, int> >& pairs,std::vector<int>& pending,std::vector<int>& mainChain);
        int                 binarySearchPosition(std::vector<int>& chain,int value);
        void                insertPending(std::vector<int>& mainChain,std::vector<int>& pending);
        std::vector<int>    fordJohnson(std::vector<int>& container);
        ~PmergeMe();
};

#endif