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
        
        // BitcoinExchange (const BitcoinExchange& other) {};
        // BitcoinExchange& operator =  (const BitcoinExchange& other) {};

        bool    Db_parsing(std::string& line ,std::string& date, float& rate);
        bool    inputFile_parsing(std::string& line ,std::string& date, float& value);
        bool    isvalidFormat_Db(std::string& date, int& month, int& day);
        bool    isvalidFormat_Input(std::string& date, int&year, int& month, int& day);
        float   getRate(const std::string &date);
};


#endif