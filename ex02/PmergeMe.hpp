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
        bool    storeInt(const std::string& a);
        std::vector<int>    getContainer();
        
    };

bool    splitVector(std::vector<int>& containr);
int    getMin(std::vector<int>& a , std::vector<int>& b);
int    getMax(std::vector<int>& a , std::vector<int>& b);
std::vector<int>&    MergeSort(std::vector<int>& a , std::vector<int>& b);
#endif