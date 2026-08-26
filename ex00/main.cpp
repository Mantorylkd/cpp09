#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./btc input.txt" << std::endl;
        return 1;
    }

    try
    {
        BitcoinExchange b;
        b.loadDataBase();
        b.loadInputfile(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}