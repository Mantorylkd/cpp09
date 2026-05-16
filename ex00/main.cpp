#include "BitcoinExchange.hpp"
#include <iostream>


int main()
{
    try 
    {
        BitcoinExchange b;
        b.loadDataBase();
        b.loadInputfile();
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
