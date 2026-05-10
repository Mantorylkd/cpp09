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
    {
        std::cout << "missing value : ";
        return false;
    }

    for (size_t i = 0; i < val.length(); i++)
    {
        if(val[i] == '-' && i == 0)
            continue;
        if (val[i] == '.')
        {
            dotCount == 1;

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

bool  isvalideDay(float& day, float& month, float& year)
{
    if(month == 2)
    {
        if(day >= 1 && day <= 28)
            return true;
        else if(day == 29 && isLeapYear(year))
            return true ;
        
        std::cout << "Error : invalid February day : ";
        return false;
    }
   else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day >= 1 && day <= 30)
            return true;

        std::cout << "invalid day : ";
        return false;
    }
    else
    {
        if(day >= 1 && day <= 31)
            return true;
        
        std::cout << "invalid day : ";
        return false;
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
    if(line.empty())
        return false;
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
        std::cout << "error : too many seperators : ";
        return false;
    }
    
    date = line.substr(0, seperator);
    date = s_trim(date);

    int end = line.find_last_not_of(" \t");

    val = line.substr(seperator + 1 , end);
    val = s_trim(val);
    
    if(!isNumericValue(val))
    {
        return false;
    }
    value = std::atof(val.c_str());
    if(value > 1000)
    {
        std::cout << "value is too large :";
        return false;
    }
    else if(value < 0)
    {
        std::cout << "non positive number :";
        return false;
    }
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
        {
            std::cout << "Date is too short : ";
            return false;
        }
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
                    if(!isvalideDay(day, month, year))
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
    else
    {
        std::cout << "bad date format : " ; 
        return false;
    }
}


BitcoinExchange::BitcoinExchange()
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
        if(s_trim(line).empty())
            continue;
        else
            std::cout << line << std::endl;

        if(inputfile_parsing(line , date, value))
        {
            if(!isvalideFormat(date, year, month , day))
           {
                std::cout << "invalid date" << std::endl;
                std::cout << std::endl;
            }
            else
            {
                std::cout << "valid" << std::endl;
                std::cout << std::endl;
            }
        }
        else 
        {
            std::cout << "invalid syntax"<< std::endl;
            std::cout << std::endl;
        }   
    }
    db[date] = value;
}




// int main()
// {
//     std::ifstream input("input.txt"); 
    
//     if (!input.is_open())
//         std::cout << "input file not found\n";

//     std::string line;
//     std::string date;
    
//     float month;
//     float day;
//     float year;
    
//     float value;
    
//     getline(input , line);
//     while(std::getline(input,line))
//     {
//         if(s_trim(line).empty())
//             continue;
//         else
//             std::cout << line << std::endl;

//         if(inputfile_parsing(line , date, value))
//         {
//             if(!isvalideFormat(date, year, month , day))
//            {
//                 std::cout << "invalid date" << std::endl;
//                 std::cout << std::endl;
//             }
//             else
//             {
//                 std::cout << "valid" << std::endl;
//                 std::cout << std::endl;
//             }
//         }
//         else 
//         {
//             std::cout << "invalid syntax"<< std::endl;
//             std::cout << std::endl;
//         }   
//     }
// }



