#pragma once
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

class BitcoinExchange{
    private:
        std::map<std::string, std::string> bitData;
    
    public:
        BitcoinExchange() = default;
        ~BitcoinExchange() = default;
        BitcoinExchange(const BitcoinExchange &obj) = default;
        BitcoinExchange & operator=(const BitcoinExchange &obj) = default;
        std::map<std::string, std::string> getMap();
        void parseData(std::ifstream &dataFile);
        void printDataMap();
};