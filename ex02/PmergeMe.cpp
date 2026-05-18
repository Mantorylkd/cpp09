#include "PmergeMe.hpp"

std::vector<int>    PmergeMe::getContainer()
{
    return vct;
}


int   getMin(std::vector<int>& a , std::vector<int>& b)
{
    if(a < b)
        return a[0];
    return b[0];
}

int   getMax(std::vector<int>& a , std::vector<int>& b)
{
    if(a > b)
        return a[0];
    return b[0];
}


bool    PmergeMe::storeInt(const std::string& a)
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

    std::cout << "this is our container" << std::endl;
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


std::vector<int>&   MergeSort(std::vector<int>& a , std::vector<int>& b)
{
    std::vector<int> final;
    
    int min = getMin(a, b);
    int max = getMax(a, b);
    
    final.push_back(min);
    final.push_back(max);

    std::vector<int>::iterator it2;
    std::cout << "this is final sorted container "<< std::endl;
    for(it2 = final.begin() ; it2 != final.end() ; ++it2)
    {
        std::cout << *it2 << std::endl;
    }
    
    return final;
}


bool  splitVector(std::vector<int>& vctr)
{
    if(vctr.size() <= 1)
        return true;
    std::vector<int>  leftPart ;
    std::vector <int> rightPart;


    std::vector<int>::iterator it;
    std::vector<int>::size_type mid = vctr.size() / 2;
    
    std::cout << "___________________\n";
    std::cout << "this is the left part" << std::endl;
    for(unsigned int i = 0 ; i < mid ; ++i)
    {
        leftPart.push_back(vctr[i]);
        std::cout << leftPart[i] << std::endl;
    }   

    std::cout << "___________________\n";
    std::cout << "this is the right part" << std::endl;
    for (unsigned int j = mid  ; j < vctr.size() ; ++j)
    {
        rightPart.push_back(vctr[j]);
        std::cout << rightPart.back() << std::endl;
    }

    if(leftPart.size() > 1)
        splitVector(leftPart);

    if(rightPart.size() > 1)
        splitVector(rightPart);

    vctr = MergeSort(leftPart, rightPart);
    
    return true;
}


