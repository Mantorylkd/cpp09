#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

bool    Db_parsing(std::string& line,std::string& date, float& rate)
{
    int comma = line.find(',');
    if(comma == std::string::npos)
        return false;
    date = line.substr(0, comma);
    std::string Rate = line.substr(comma + 1);

    rate = std::atof(Rate.c_str());

    return true;
}



bool    inputfile_parsing(std::string& line,std::string& date, float& rate)
{
    int seperator = line.find('|');
    if(seperator == std::string::npos)
        return false;
    date = line.substr(0, seperator);
    std::string Rate = line.substr(seperator + 1);

    rate = std::atof(Rate.c_str());

    return true;
}
bool isvalidateformat(std::string& date, float& month, float& day, float& rate)
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
                    std::cout << "this is month " << month << std::endl;
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
                    std::cout << "this is day " << day << std::endl;
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


bool  isvalidateMonth(float& month)
{
    if(month >= 1 && month <= 12)
        return true; 
    return false;
}

bool  isvalidateDay(float& day)
{
    if(day >= 1 && day <= 31)
        return true; 
    return false;
}

bool  isvalidateRate(float& rate)
{
    if(rate >= 0)
        return true; 
    return false;
}




int main()
{
    std::ifstream file("data.csv");
    if(!file.is_open())
        std::cout << "file not found\n";
    std::string line;
    std::string date;
    float month;
    float rate;
    float day;

    while (getline(file,line))
    {
        if(Db_parsing(line,date,rate))
        {
            std::cout << "this is the whole line => "<< line << std::endl;
            std::cout << "date => " << date << std::endl;
            std::cout << "rate => " << rate << std::endl;
        }
    }
    
    if(!isvalidateformat(date, month, day, rate))
        std::cout << "invalid date" << std::endl;

    if(!isvalidateMonth(month))
        std::cout << "invalid month" << std::endl;

    if(!isvalidateDay(day))
        std::cout << "invalid day" << std::endl;

     if(!isvalidateRate(rate))
        std::cout << "invalid rate" << std::endl;
}
