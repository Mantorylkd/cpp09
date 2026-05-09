#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cctype>


std::string s_trim(std::string &s)
{
    size_t start = s.find_first_not_of(" \t");
    size_t end = s.find_last_not_of(" \t");

    if(start == std::string::npos)
        return "" ;
    
    return (s.substr(start, end - start + 1));
}

bool isNumericValue(const std::string& val)
{
    int dotCount = 0;
    if (val.empty())
        return false;

    for (size_t i = 0; i < val.length(); i++)
    {
        if (val[i] == '.')
        {
            dotCount++;

            if (dotCount > 1)
                return false;
        }
        else if (!std::isdigit(val[i]))
            return false;
    }
    if (val == ".")
        return false;
    return true;
}

bool  isvalideDay(float& day, float& month)
{
    if(month == 2)
    {
        if(day >= 1 && day <= 28)
            return true;
        else
        {
            std::cout << "Error : invalid February day : ";
            return false;
        }
    }
    else
    {
        if(day >= 1 && day <= 31)
            return true;
    }
    return false;
}

bool  isvalideMonth(float& month )
{
    if(month >= 1 && month <= 12)
        return true;
    else
    {
        std::cout << "invalid month : ";
        return false;
    }
}


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

bool    inputfile_parsing(std::string& line ,std::string& date, float& value)
{
    int sepfind = 0;
    std::string val;
    int seperator = line.find('|');
    if(seperator == std::string::npos)
    {
        std::cout << "error : missing seperator '|' : ";
        return false;
    }
    
    for (int i = seperator+1 ; i < line.length() ; i++)
    {
        if(line[i] == '|')
            sepfind = 1;
    }
    if(sepfind == 1)
    {
        std::cout << "error : found nore than one '|' seperator : ";
        return false;
    }
    
    date = line.substr(0, seperator);
    date = s_trim(date);

    int end = line.find_last_not_of(" \t");

    val = line.substr(seperator + 1 , end);
    val = s_trim(val);
    
    if(!isNumericValue(val))
    {
        std::cout << "error : missing value : ";
        return false;
    }
    value = std::atof(val.c_str());
    return true;
}


bool isvalideFormat(std::string& date, float& year, float& month, float& day)
{
    int underscoreFound = 0;
    int i = 0;
    std::string monthPart;
    std::string dayPart;
    std::string yearPart;

    while (date[i])
    {   
        if(date.length() != 10)
            return false;
        yearPart = date.substr(0,4);
        year = std::atof(yearPart.c_str());
        
        for(int j = 0; j < yearPart.length(); j++)
        {
            if(!isdigit(yearPart[j]))
            {
                std::cout << "invalid year format" << std::endl;
                return false;
            }
        }
        if (date[i] == '-')
        {
            if (underscoreFound == 0)
            {
                if(i == 4)
                {
                    underscoreFound = 1;
                    monthPart = date.substr(i+1, 2);
                    month = std::atof(monthPart.c_str());
                    if(!isvalideMonth(month))
                        return false;
                }
                else
                {
                    std::cout << "bad emplacement of '-' "<< std::endl;
                    return false;
                }
            }
            else if (underscoreFound == 1)
            {
                if(i == 7)
                {
                    underscoreFound = 2;
                    dayPart = date.substr(i+1, 2);
                    day = std::atof(dayPart.c_str());
                    if(!isvalideDay(day, month))
                        return false;
                }
                else
                {
                    std::cout << "bad emplacement of '-' "<< std::endl;
                    return false;
                }
            }
        }
        i++;
    }
    if(underscoreFound == 2)
        return true;
    return false;
}

int main()
{
    
    std::ifstream input("input.txt"); 
    
    if (!input.is_open())
        std::cout << "input file not found\n";

    std::string line;
    std::string date;
    
    float month;
    float day;
    float year;
    
    float value;
    
    getline(input , line);
    while(std::getline(input,line))
    {
        if(inputfile_parsing(line , date, value))
        {
            if(!isvalideFormat(date, year, month , day))
                std::cout << "invalid date" << std::endl;
            else
            {
                std::cout << "date => "  << date << std::endl;
                std::cout << "value => " << value << std::endl;
            }
        }
        else
            std::cout << " invalid syntax"<< std::endl;
    }
}

