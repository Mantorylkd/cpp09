#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE
#include <map>
#include <string>


class BitcoinExchange
{
    private :
        std::map<std::string , float> db;
        std::map<std::string , float> ::iterator it;
            
    public:
        BitcoinExchange();

        void loadDataBase();
        // BitcoinExchange (const BitcoinExchange& other) {};
        // BitcoinExchange& operator =  (const BitcoinExchange& other) {};
        ~BitcoinExchange() {};

        bool   Db_parsing(std::string& line ,std::string& date, float& rate);
        bool isvalidFormat(std::string& date, float& month, float& day, float& rate);
        std::map<std::string , float>  iteration();     
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