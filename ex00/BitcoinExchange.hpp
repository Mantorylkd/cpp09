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
        ~BitcoinExchange() {};

        void loadDataBase();
        void loadInputfile();       
        
        // BitcoinExchange (const BitcoinExchange& other) {};
        // BitcoinExchange& operator =  (const BitcoinExchange& other) {};

        bool    Db_parsing(std::string& line ,std::string& date, float& rate);
        bool    inputFile_parsing(std::string& line ,std::string& date, float& value);
        bool    isvalidFormat_Db(std::string& date, float& month, float& day, float& rate);
        bool    isvalidFormat_Input(std::string& date, float&year, float& month, float& day);
        
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