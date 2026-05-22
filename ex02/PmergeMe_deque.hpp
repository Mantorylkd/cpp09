#ifndef PMERGEME_DEQUE_HPP
#define PMERGEME_DEQUE_HPP

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

        std::deque<int> dq;
        bool hasStraggler;
        int  straggler;

    public:
        PmergeMe();
        bool                storeInt(const std::string& str);
        std::deque<int>     getDeque();
        bool                checkDuplicate(std::deque<int>& container);
        std::deque<int>    mergeChains(std::deque<int>& left,std::deque<int>& right);
        std::deque<int>    splitChain(std::deque<int>& container);
        std::deque< std::pair<int, int> >      makePairs(std::deque<int>& container);
        void                makeChains(std::deque< std::pair<int, int> >& pairs,std::deque<int>& pending,std::deque<int>& mainChain);
        int                 binarySearchPosition(std::deque<int>& chain,int value);
        void                insertPending(std::deque<int>& mainChain,std::deque<int>& pending);
        std::deque<int>    fordJohnson(std::deque<int>& container);
        ~PmergeMe();
    };

#endif