#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cctype>


BitcoinExchange::BitcoinExchange()
{
    db[""] = 0;
}


void    BitcoinExchange::loadDataBase()
{   
    std::ifstream dataFile ("data.csv");
    if(!dataFile.is_open())
    {
        std::cout << "file is not found " << std::endl;
        return;
    }
    else
    {
        
    }
}