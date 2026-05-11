#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

BitcoinExchange::BitcoinExchange()
{
    db[""] = 0;
}  

bool  BitcoinExchange::Db_parsing(std::string& line ,std::string& date, float& rate)
{
    int seperator = line.find(',');
    if(seperator == std::string::npos)
        return false;
    date = line.substr(0, seperator);
    std::string Rate = line.substr(seperator + 1);

    rate = std::atof(Rate.c_str());

    return true;
}

bool BitcoinExchange::isvalidFormat(std::string& date, float& month, float& day, float& rate)
{
    int underscoreFound = 0;
    int i = 0;
    std::string monthPart;
    std::string dayPart;
    std::string ratePart;

    while (date[i])
    {   
        if(date.length() != 10)
            return false;
        if (date[i] == '-')
        {
            if (underscoreFound == 0)
            {
                if(i == 4)
                {
                    underscoreFound = 1;
                    monthPart = date.substr(i+1, 2);
                    month = std::atof(monthPart.c_str());
                }
                else
                    return false;
            }
            else if (underscoreFound == 1)
            {
                if(i == 7)
                {
                    underscoreFound = 2;
                    dayPart = date.substr(i+1, 2);
                    day = std::atof(dayPart.c_str());
                }
                else
                    return false;
            }
        }
        i++;
        ratePart = std::atof(ratePart.c_str());
    }
    if(underscoreFound == 2)
        return true;
    return false;
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
        std::string line;
        std::string date;

        float month;
        float day;
        float rate;

        getline(dataFile, line);
        
        
        while(std::getline(dataFile,line))
        {
            if(Db_parsing(line , date, rate))
            {
                if(isvalidFormat(date, month, day , rate))
                {
                    db[date] = rate;
                }
            }
        }

        it = db.begin();
        std::advance(it,1);
        
        for(it ; it != db.end() ; ++it)
        {
            std::cout << it->first << " =>"<< it->second << std::endl;
        }
    }
}

int main()
{
    BitcoinExchange b;
    b.loadDataBase();
    
}