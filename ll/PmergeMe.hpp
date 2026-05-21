#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <stdexcept>
#include <utility>

class PmergeMe
{
    private:
        std::vector<int> vct;
        std::deque<int> dq;

    public:
        bool storeInt(const std::string& str);

        std::vector<int> getVector();
        std::deque<int> getDeque();

        template<typename T>
        T splitContainer(T& container);

        template<typename T>
        T mergeContainers(T& a, T& b);

        template<typename T>
        bool checkDuplicate(T& container);

        // template<typename T, typename A>
        // T makePairs(A& a, A& b);

        std::vector <std::pair<int ,int> >  makePairs(std::vector<int>& container);
};


template<typename T>
bool PmergeMe::checkDuplicate(T& container)
{
    typename T::size_type i;
    typename T::size_type j;

    for(i = 0; i < container.size(); ++i)
    {
        for(j = i + 1; j < container.size(); ++j)
        {
            if(container[i] == container[j])
                return true;
        }
    }

    return false;
}


inline std::vector< std::pair<int, int> >
PmergeMe::makePairs(std::vector<int>& container){
    std::vector <std::pair <int,int> > pairs;

    for(size_t i = 0 ; i < container.size() - 1 ; i+=2)
    {
        int a = container[i];
        int b = container[i+1];

        if(a > b)
            std::swap(a,b);
        
        pairs.push_back(std::make_pair(a,b));
    }

    for(size_t i = 0; i < pairs.size(); ++i)
    {
        std::cout << "first  ->" << pairs[i].first  << std::endl;
        std::cout << "second ->" << pairs[i].second << std::endl;
        std::cout << "======" << std::endl;
    }

    return pairs;
}




// template<typename T>
// T PmergeMe::mergeContainers(T& a, T& b)
// {
//     T final;

//     typename T::size_type i = 0;
//     typename T::size_type j = 0;

//     while(i < a.size() && j < b.size())
//     {
//         if(a[i] < b[j])
//         {
//             final.push_back(a[i]);
//             ++i;
//         }
//         else
//         {
//             final.push_back(b[j]);
//             ++j;
//         }
//     }

//     while(i < a.size())
//     {
//         final.push_back(a[i]);
//         ++i;
//     }

//     while(j < b.size())
//     {
//         final.push_back(b[j]);
//         ++j;
//     }

//     return final;
// }



// template<typename T>
// T PmergeMe::splitContainer(T& container)
// {
//     if(container.empty())
//         throw std::runtime_error("Error: empty argument");

//     if(container.size() <= 1)
//         return container;

//     if(checkDuplicate(container))
//         throw std::runtime_error("Error: duplicate detected");

//     T leftPart;
//     T rightPart;

//     typename T::size_type mid = container.size() / 2;

//     for(typename T::size_type i = 0; i < mid; ++i)
//     {
//         leftPart.push_back(container[i]);
//     }

//     for(typename T::size_type j = mid; j < container.size(); ++j)
//     {
//         rightPart.push_back(container[j]);
//     }

//     leftPart = splitContainer(leftPart);
//     rightPart = splitContainer(rightPart);

//     return mergeContainers(leftPart, rightPart);
// }

#endif