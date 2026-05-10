#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE
#include <map>


class BitcoinExchange
{
    private :
        std::map<std::string , float> db;
    
    public:
        BitcoinExchange();

        void loadDataBase();
        BitcoinExchange (const BitcoinExchange& other);
        BitcoinExchange& operator =  (const BitcoinExchange& other);
        ~BitcoinExchange();
};



#endif