#include "BitcoinExchange.hpp"
#include <iterator>
#include <string>

std::map<std::string, float> BitcoinExchange::getMap()
{
	return (bitData);
}

void BitcoinExchange::parseData(std::ifstream &dataFile)
{
	size_t	pos;

	pos = 0;
	std::string line;
	while (std::getline(dataFile, line))
	{
		pos = line.find(',');
		if (pos != std::string::npos)
		{
			std::string firstPart = line.substr(0, pos);
			std::string secondPart = line.substr(pos + 1);
			if (firstPart != "date")
			    bitData.insert({firstPart, std::stof(secondPart)});
		}
	}
	if (dataFile.eof())
	{
		std::cout << "Reached end of file." << std::endl;
	}
	else if (dataFile.fail())
	{
		std::cerr << "Read failed due to an error." << std::endl;
	}
}
void BitcoinExchange::printDataMap()
{
	std::cout << "debug" << std::endl;
	std::map<std::string, float>::iterator it;
	for (it = bitData.begin(); it != bitData.end(); it++)
	{
		std::cout << "First:" << it->first << "| second:" << it->second << std::endl;
	}
}

float BitcoinExchange::result(const std::string &firstP, float value){
    float secondValue = 0;
    std::map<std::string,float>::iterator it;
    for(it = bitData.begin();(it != bitData.end() && it->first <= firstP); it++ ){
        if (firstP == it->first)
            return (value * it->second);
        secondValue = it->second;
    }
    return (value * secondValue);
}

void BitcoinExchange::calculateValue(std::ifstream &inputFile){
    std::string line;
    size_t pos = 0;

    while (std::getline(inputFile, line)){
        std::string firstP;
        std::string secondP;
        pos = line.find(" | ");
        if(pos != std::string::npos){
            firstP = line.substr(0,pos);
            secondP = line.substr(pos+3);
            if(firstP != "date"){
                if (stof(secondP) < 0){
                    std::cout<<"Error: not a positive number."<<std::endl;
                }
                else{
                    std::cout<<firstP<<" => "<<secondP<<" = "<<result(firstP ,stof(secondP))<<std::endl;
                }

            }
        }
        else {
            std::cout<<"Error: bad input => "<<line<<std::endl;
        }
    }

}
