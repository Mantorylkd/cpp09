#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

BitcoinExchange::BitcoinExchange() {}  

bool  BitcoinExchange::Db_parsing(std::string& line ,std::string& date, float& rate)
{
    std::string::size_type separator = line.find(',');
    if(separator == std::string::npos)
        return false;
    date = line.substr(0, separator);
    std::string Rate = line.substr(separator + 1);

    rate = std::atof(Rate.c_str());

    return true;
}


std::string s_trim(std::string &s)
{
    std::string::size_type start = s.find_first_not_of(" \t");
    std::string::size_type end = s.find_last_not_of(" \t");

    if(start == std::string::npos)
        return "" ;
    
    return (s.substr(start, end - start + 1));
}

bool    nonDigitCheck(std::string value)
{
    for(size_t i = 0 ; i < value.length() ; ++i)
    {
        if(!isdigit(value[i]))
            return true;
    }
    return false;
}

bool isNumericValue(const std::string& val)
{
    int dotCount = 0;
    if (val.empty())
    {
        std::cout << "Error: missing value" << std::endl;
        return false;
    }

    for (size_t i = 0; i < val.length(); i++)
    {
        if(val[i] == '-' && i == 0)
            continue;
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

bool isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

bool  isValidDay(int& day, int& month, int& year)
{
    if(month == 2)
    {
        if(day >= 1 && day <= 28)
            return true;
        else if(day == 29 && isLeapYear(year))
            return true ;
        
        std::cout << "Error: invalid February day" << std::endl;
        return false;
    }
   else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day >= 1 && day <= 30)
            return true;

        std::cout << "Error: invalid day" << std::endl;
        return false;
    }
    else
    {
        if(day >= 1 && day <= 31)
            return true;
        
        std::cout << "Error: invalid day" << std::endl;
        return false;
    }
    return false;
}

bool  isValidMonth(int& month )
{
    if(month >= 1 && month <= 12)
        return true;
    else
    {
        std::cout << "Error: invalid month" << std::endl;
        return false;
    }
}


bool BitcoinExchange::inputFile_parsing(std::string& line ,std::string& date, float& value)
{
    if(line.empty())
        return false;
    int sepfind = 0;
    std::string val;
    std::string::size_type seperator = line.find('|');
    if(seperator == std::string::npos)
    {
        std::cout << "Error: missing separator '|' " << std::endl;
        return false;
    }
    
    for(std::string::size_type i = seperator + 1 ; i < line.length() ; i++)
    {
        if(line[i] == '|')
            sepfind = 1;
    }
    if(sepfind == 1)
    {
        std::cout << "Error: multiple separators " << std::endl;
        return false;
    }
    
    date = line.substr(0, seperator);
    date = s_trim(date);
    if(date == "")
    {
        std::cout << "Error : missing date"<<std::endl;
        return false;
    }

    val = line.substr(seperator + 1);
    val = s_trim(val);
    if(val == "")
    {
        std::cout << "Error : missing value"<<std::endl;
        return false;
    }
    
    if(!isNumericValue(val))
    {
        std::cout << "Error : invalid value" << std::endl;
        return false;
    }
    
    value = std::atof(val.c_str());
    if(value > 1000)
    {
        std::cout << "Error: value is too large "<< std::endl;
        return false;
    }
    else if(value < 0)
    {
        std::cout << "Error: negative number " << std::endl;
        return false;
    }
    return true;
}


bool BitcoinExchange::isvalidFormat_Db(std::string& date, int& month, int& day)
{
    if(date.length() != 10)
    {
        std::cout << "Error: invalid date length  " << std::endl;
        return false;
    }
    
    int underscoreFound = 0;
    std::string::size_type i = 0;
    std::string monthPart;
    std::string dayPart;

    while (i < date.length())
    {       
        if (date[i] == '-')
        {
            if (underscoreFound == 0)
            {
                if(i == 4)
                {
                    underscoreFound = 1;
                    monthPart = date.substr(i+1, 2);
                    month = std::atoi(monthPart.c_str());
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
                    day = std::atoi(dayPart.c_str());
                }
                else
                    return false;
            }
        }
        i++;
    }
    if(underscoreFound == 2)
        return true;
    return false;
}



bool BitcoinExchange::isvalidFormat_Input(std::string& date,int& year, int& month, int& day)
{
    std::string yearPart;
    
    if(date.length() != 10)
    {
        std::cout << "Error: invalid date length" << std::endl; 
        return false;
    }
    yearPart = date.substr(0,4);
    
    for(std::string::size_type j = 0; j < yearPart.length(); j++)
    {
        if(!std::isdigit(yearPart[j]))
        {
            std::cout << "Error: invalid year format" << std::endl;
            return false;
        }
        year = std::atoi(yearPart.c_str());
    }

    int underscoreFound = 0;
    std::string::size_type i = 0;
    std::string monthPart;
    std::string dayPart;

    while (i < date.length())
    {   
        if (date[i] == '-')
        {
            if (underscoreFound == 0)
            {
                if(i == 4)
                {
                    underscoreFound = 1;
                    monthPart = date.substr(i+1, 2);
                    if(nonDigitCheck(monthPart))
                    {
                        std::cout << "Error : invalid month" << std::endl; 
                        return false;
                    }
                    month = std::atoi(monthPart.c_str());
                    if(!isValidMonth(month))
                        return false;
                }
                else
                {
                    std::cout << "Error: bad emplacement of '-' "<< std::endl;
                    return false;
                }
            }
            else if (underscoreFound == 1)
            {
                if(i == 7)
                {
                    underscoreFound = 2;
                    dayPart = date.substr(i+1, 2);
                    if(nonDigitCheck(dayPart))
                    {
                        std::cout << "Error : invalid day" << std::endl; 
                        return false;
                    }
                    day = std::atoi(dayPart.c_str());
                    if(!isValidDay(day, month, year))
                        return false;
                }
                else
                {
                    std::cout << "Error: bad emplacement of '-' "<< std::endl;
                    return false;
                }
            }
        }
        i++;
    }
    if(underscoreFound == 2)
        return true;
    else
    {
        std::cout << "Error: bad date format" << std::endl ; 
        return false;
    }
}


void    BitcoinExchange::loadDataBase()
{   
    std::ifstream dataFile ("data.csv");
    if(!dataFile.is_open())
    {
        std::cout << "Error: file is not found"<< std::endl;
        return;
    }
    else
    {
        std::string line;
        std::string date;

        int month;
        int day;
        float rate;

        getline(dataFile, line);
        
        
        while(std::getline(dataFile,line))
        {
            if(Db_parsing(line , date, rate))
            {
                if(isvalidFormat_Db(date, month, day))
                {
                    db[date] = rate;
                }
            }
        }
    }
}

float BitcoinExchange::getRate(const std::string &date)
{
    if (db.empty())
        throw std::runtime_error("Error: empty database.");

    std::map<std::string, float>::iterator it = db.lower_bound(date);

    // if exact match
    if (it != db.end() && it->first == date)
        return it->second;

    // if lower_bound points to first element
    if (it == db.begin())
    {
        if (it->first > date)
            throw std::runtime_error("Error: date before database.");
        return it->second;
    }

    // otherwise step back to get closest lower date
    if (it == db.end() || it->first > date)
        --it;

    return it->second;
}


void BitcoinExchange::loadInputfile(const std::string& fileName)
{   
    std::ifstream input(fileName.c_str());
    if (!input.is_open())
        std::cout << "Error: input file not found\n";

    std::string line;
    std::string date;
    
    int month;
    int day;
    int year;
    
    float value;
    
    getline(input , line);
    while(std::getline(input,line))
    {
        if(s_trim(line).empty())
            continue;
        if(inputFile_parsing(line , date, value))
        {
            if(isvalidFormat_Input(date, year, month , day))
            {
                try
                {
                    float rate = getRate(date);
                    float result = value * rate;
                    std::cout << date
                              << " => "
                              << value
                              << " = "
                              << result
                              << std::endl;
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
        }
    }
}
