#include "PmergeMe.hpp"

std::vector<int>    PmergeMe::getContainer()
{
    return vct;
}

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

std::vector<int> PmergeMe::MergeSort(std::vector<int>& a, std::vector<int>& b)
{
    std::vector<int> final;

    unsigned int i = 0;
    unsigned int j = 0;

    while(i < a.size() && j < b.size())
    {
        if(a[i] < b[j])
        {
            final.push_back(a[i]);
            i++;
        }
        else
        {
            final.push_back(b[j]);
            j++;
        }
    }

    while(i < a.size())
    {
        final.push_back(a[i]);
        i++;
    }

    while(j < b.size())
    {
        final.push_back(b[j]);
        j++;
    }

    return final;
}


static bool checkDuplicate(std::vector <int>& vctr)
{
    std::vector<int>::size_type i;
    std::vector<int>::size_type j;

    for(i = 0 ; i < vctr.size() ; ++i)
    {
        for(j = i + 1 ; j < vctr.size() ; ++j)
        {
            if(vctr[i] == vctr[j])
                return true;
        }
    }
    return false;
}


std::vector<int>  PmergeMe::splitVector(std::vector<int>& vctr)
{
    if(vctr.empty())
        throw std::runtime_error("Error : empty arg");

    if(vctr.size() <= 1)
         return vctr;
    
    if(checkDuplicate(vctr))
        throw std::runtime_error("Error : duplication detected !");

    std::vector<int>  leftPart ;
    std::vector <int> rightPart;


    std::vector<int>::size_type mid = vctr.size() / 2;
    
    for(unsigned int i = 0 ; i < mid ; ++i)
    {
        leftPart.push_back(vctr[i]);
    }   

    for (unsigned int j = mid  ; j < vctr.size() ; ++j)
    {
        rightPart.push_back(vctr[j]);
    }

    if(leftPart.size() > 1)
        splitVector(leftPart);

    if(rightPart.size() > 1)
        splitVector(rightPart);

    vctr = MergeSort(leftPart, rightPart);

    return vctr;
}


