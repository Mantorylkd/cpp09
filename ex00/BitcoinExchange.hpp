#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE
#include <map>
#include <string>
#include <iostream>
#include <cstdlib>

class BitcoinExchange
{
    private :
        std::map<std::string , float> db;
    public:
        BitcoinExchange();
        ~BitcoinExchange() {};

        void loadDataBase();
        void loadInputfile(const std::string& fileName);       
        
        BitcoinExchange (const BitcoinExchange& other) {};
        BitcoinExchange& operator =  (const BitcoinExchange& other) {};

        bool    Db_parsing(std::string& line ,std::string& date, float& rate);
        bool    inputFile_parsing(std::string& line ,std::string& date, float& value);
        bool    isvalidFormat_Db(std::string& date, int& month, int& day);
        bool    isvalidFormat_Input(std::string& date, int&year, int& month, int& day);
        float   getRate(std::string &date);
};


// std::string     s_trim(std::string &s);
// bool    isNumericValue(const std::string& val);
// bool    isLeapYear(int year);
// bool    isvalideMonth(float& month );
// bool    isvalideMonth(float& month );
// bool    Db_parsing(std::string& line,std::string& date, float& rate);
// bool    inputfile_parsing(std::string& line ,std::string& date, float& value);
// bool    isvalideFormat(std::string& date, float& year, float& month, float& day);

#endif