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


std::vector<int>  PmergeMe::splitChain(std::vector<int>& vctr)
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
        splitChain(leftPart);

    if(rightPart.size() > 1)
        splitChain(rightPart);

    vctr = MergeSort(leftPart, rightPart);

    return vctr;
}


std::vector< std::pair<int, int> > PmergeMe::makePairs(std::vector<int>& container)
{
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


std::vector<int>   PmergeMe::makeChains(std::vector <std::pair<int, int> > & pairs , std::vector <int> first , std::vector <int> second)
{
    for(size_t i = 0 ; i < pairs.size(); i++)
    {
        first.push_back(pairs[i].first);
        second.push_back(pairs[i].second);
    }
        
    std::cout << "pending chain" << std::endl;
    for(size_t j = 0; j < first.size(); ++j)
    {
        std::cout << first[j] << std::endl;
    }
    
    std::cout << "main chain" << std::endl;
    for(size_t a = 0; a < second.size(); ++a)
    {
        std::cout << second[a] << std::endl;
    }


    std::cout << "======================= "<< std::endl;
    std::cout << "after sorting" << std::endl;
    std::cout << "======================= "<< std::endl;


    first = splitChain(second);
    
    std::cout << "main chain" << std::endl;
    for(size_t a = 0; a < second.size(); ++a)
    {
        std::cout << a << "-> " << second[a] << std::endl;
    }

    return first;
}