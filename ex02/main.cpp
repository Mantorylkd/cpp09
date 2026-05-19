#include "PmergeMe.hpp"


int main(int ac , char **av)
{
    if(ac != 2)
    {
        std::cerr << "Error : insuffisant" << std::endl;
        return 1;
    }
    PmergeMe p;
    
    p.storeInt(av[1]);
    std::vector<int> vct = p.getContainer() ;
    std::vector<int>::iterator it ;
    
    
    try
    {
        clock_t start = clock();
        std::vector<int> final =  p.splitVector(vct);
        clock_t end = clock();
        
        for(it = final.begin() ; it != final.end(); ++it)
        {
            std::cout << *it << std::endl;
        }

        double us = (double)(end - start) * 1000000 / CLOCKS_PER_SEC;
        std::cout << "time consumed = " << us << std::endl;
    }
    catch(const std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }
}
