#include "BitcoinExchange.hpp"
#include <iterator>
#include <string>
#include <regex>
#include <stdexcept>

std::map<std::string, float> BitcoinExchange::getMap()
{
	return (bitData);
}

void BitcoinExchange::parseData(std::ifstream &dataFile)
{
	size_t pos;

	pos = 0;
	std::string line;
	if (std::getline(dataFile, line))
	{
		if (line != "date,exchange_rate")
		{
			std::cerr << "Error\nData file header is not correct";
			exit(1);
		}
	}
	while (std::getline(dataFile, line))
	{
		pos = line.find(',');
		if (pos != std::string::npos)
		{
			std::string firstPart = line.substr(0, pos);
			std::string secondPart = line.substr(pos + 1);
			std::regex digitsOnly(R"(^\d*\.?\d+$)");
			if (!std::regex_match(secondPart, digitsOnly))
			{
				std::cerr << "Error\nnot digits {" << secondPart << "} value in data file";
				exit(1);
			}
			if (firstPart != "date")
			{

				bitData.insert({firstPart, std::stof(secondPart)});
			}
		}
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

float BitcoinExchange::result(const std::string &firstP, float value)
{
	float secondValue;

	secondValue = 0;
	std::map<std::string, float>::iterator it;
	for (it = bitData.begin(); (it != bitData.end() && it->first <= firstP); it++)
	{
		if (firstP == it->first)
			return (value * it->second);
		secondValue = it->second;
	}
	return (value * secondValue);
}

bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool validateDate(std::string &dateStr)
{

	int year;
	int month;
	int day;

	year = stoi(dateStr.substr(0, 4));
	month = stoi(dateStr.substr(5, 2));
	day = stoi(dateStr.substr(8, 2));

	if (month > 12 || month < 0)
	{
		return false;
	}

	if ((day > 31 || day < 0) || ((day == 31 || day == 30) && month == 2) || (day == 29 && !isLeapYear(year) && month == 2) || (day == 31 && month == 4) || (day == 31 && month == 6) || (day == 31 && month == 9) || (day == 31 && month == 11))
	{
		return false;
	}

	return (true);
}

bool pre_validate(std::string &line)
{
	std::regex date_pattern1(R"(\d{4}-\d{2}-\d{2})");
	std::regex date_pattern2(R"(\d{4}-\d{2}-\d{2} \| -?\d+(\.\d+)?$)");
	if (!std::regex_match(line, date_pattern1) && !std::regex_match(line, date_pattern2))
			return false;
	return (true);
}

bool BitcoinExchange::calculateValue(std::ifstream &inputFile)
{
	size_t pos;

	std::string line;
	pos = 0;
	inputFile.clear();
	inputFile.seekg(0, std::ios::beg); // will reset the getline to read from begining

	std::getline(inputFile, line);
	if (line != "date | value")
	{
		throw std::runtime_error("Error\nfile has incorrect values");
	}
	while (std::getline(inputFile, line))
	{
		if (!pre_validate(line)){
			std::cout << "bad input => " << line<<std::endl;
		}
		std::string firstP = "";
		std::string secondP = "";
		std::map<std::string, float>::iterator it = bitData.begin();
		pos = line.find(" | ");
		if (pos != std::string::npos)
		{
			firstP = line.substr(0, pos);
			secondP = line.substr(pos + 3);
			if (firstP != "date")
			{
				if (firstP < it->first)
				{
					std::cout << "Error: no record for this." << std::endl;
				}else if(!validateDate(firstP)){
					std::cout << "bad input => " << firstP<<std::endl;
				}
				else if (stof(secondP) < 0)
				{
					std::cout << "Error: not a positive number." << std::endl;
				}
				else
				{
					if (stof(secondP) < 1000 && stof(secondP) > 0)
						std::cout << firstP << " => " << secondP << " = " << result(firstP, stof(secondP)) << std::endl;
					else
						std::cout << "Error: too large a number." << std::endl;
				}
			}
		}
		else
		{
			std::cout << "Error: bad input => " << line << std::endl;
		}
	}
	return (true);
}
