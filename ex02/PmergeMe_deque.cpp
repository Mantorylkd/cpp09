#include "PmergeMe_deque.hpp"


PmergeMe::PmergeMe()
{
    hasStraggler = false;
}


PmergeMe::~PmergeMe(){}

std::deque<int> PmergeMe::getDeque()
{
    return dq;
}


bool PmergeMe::storeInt(const std::string& str)
{
    std::stringstream ss(str);

    int number;

    while (ss >> number)
    {
        if (number < 0)
            return false;

        dq.push_back(number);
    }

    if (ss.fail() && !ss.eof())
        return false;

    return true;
}


bool PmergeMe::checkDuplicate(std::deque<int>& container)
{
    for (size_t i = 0; i < container.size(); ++i)
    {
        for (size_t j = i + 1; j < container.size(); ++j)
        {
            if (container[i] == container[j])
                return true;
        }
    }

    return false;
}


std::deque<int>    PmergeMe::mergeChains(std::deque<int>& left,std::deque<int>& right)
{
    std::deque<int> final;

    size_t i = 0;
    size_t j = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            final.push_back(left[i]);
            ++i;
        }
        else
        {
            final.push_back(right[j]);
            ++j;
        }
    }

    while (i < left.size())
    {
        final.push_back(left[i]);
        ++i;
    }

    while (j < right.size())
    {
        final.push_back(right[j]);
        ++j;
    }

    return final;
}


std::deque<int> PmergeMe::splitChain(std::deque<int>& container)
{
    if (container.size() <= 1)
        return container;

    std::deque<int> leftPart;
    std::deque<int> rightPart;

    size_t mid = container.size() / 2;

    for (size_t i = 0; i < mid; ++i)
        leftPart.push_back(container[i]);

    for (size_t i = mid; i < container.size(); ++i)
        rightPart.push_back(container[i]);

    leftPart = splitChain(leftPart);

    rightPart = splitChain(rightPart);

    return mergeChains(leftPart, rightPart);
}


std::deque< std::pair<int, int> >PmergeMe::makePairs(std::deque<int>& container)
{
    std::deque< std::pair<int, int> > pairs;

    for (size_t i = 0; i + 1 < container.size(); i += 2)
    {
        int a = container[i];
        int b = container[i + 1];
        
        if (a > b)
        std::swap(a, b);

        pairs.push_back(std::make_pair(a, b));
    }
    
    
    if (container.size() % 2 != 0)
    {
        straggler = container.back();
        hasStraggler = true;
    }

    return pairs;
}


void PmergeMe::makeChains(std::deque< std::pair<int, int> >& pairs,std::deque<int>& pending,std::deque<int>& mainChain)
{
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        pending.push_back(pairs[i].first);

        mainChain.push_back(pairs[i].second);
    }

    mainChain = splitChain(mainChain);
}


int PmergeMe::binarySearchPosition(std::deque<int>& chain,int value)
{
    int left = 0;
    int right = chain.size();

    while (left < right)
    {
        int mid = (left + right) / 2;

        if (chain[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}


void PmergeMe::insertPending(std::deque<int>& mainChain,std::deque<int>& pending)
{
    for (size_t i = 0; i < pending.size(); ++i)
    {
        int pos = binarySearchPosition(mainChain, pending[i]);

        mainChain.insert(mainChain.begin() + pos,
                         pending[i]);
    }
}


std::deque<int>PmergeMe::fordJohnson(std::deque<int>& container)
{
    if (container.empty())
        throw std::runtime_error("Error: empty input");

    if (checkDuplicate(container))
        throw std::runtime_error("Error: duplicate detected");

    std::deque< std::pair<int, int> > pairs;
    std::deque<int> pending;
    std::deque<int> mainChain;

    pairs = makePairs(container);
    makeChains(pairs, pending, mainChain);
    insertPending(mainChain, pending);

    if (hasStraggler)
    {
        int pos = binarySearchPosition(mainChain,straggler);

        mainChain.insert(mainChain.begin() + pos,straggler);
    }
    return mainChain;
}