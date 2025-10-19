#include "BitcoinExchange.hpp"

bool	checkFile(std::ifstream &sfile, const std::string &fileName)
{
	sfile.open(fileName);
	std::cout << "File Name is:" << fileName << std::endl;
	if (!sfile.is_open())
	{
		std::cerr << "cannot open the file" << std::endl;
		return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	std::ifstream inputFile;
	std::ifstream datafile;
	BitcoinExchange btc;
	if (argc != 2)
	{
		std::cerr << "Error\nit must be [btc filename]" << std::endl;
		return (1);
	}
	if (!checkFile(datafile, "data.csv") || !checkFile(inputFile, argv[1]))
		return (1);
	try
	{
		btc.parseData(datafile);
		btc.printDataMap();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}