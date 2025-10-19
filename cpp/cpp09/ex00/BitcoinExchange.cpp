#include "BitcoinExchange.hpp"

std::map<std::string, std::string> BitcoinExchange::getMap()
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
			bitData.insert({firstPart, secondPart});
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
	std::map<std::string, std::string>::iterator it;
	for (it = bitData.begin(); it != bitData.end(); it++)
	{
		std::cout << "First:" << it->first << "| second:" << it->second << std::endl;
	}
}