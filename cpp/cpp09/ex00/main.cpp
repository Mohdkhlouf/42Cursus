#include "BitcoinExchange.hpp"

bool	checkFile(std::ifstream &sfile, const std::string &fileName)
{
	sfile.open(fileName);
	if (!sfile.is_open())
	{
		std::cerr << "cannot open the file" << std::endl;
		return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	BitcoinExchange	btc;

	std::ifstream inputFile;
	std::ifstream datafile;
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
		// btc.printDataMap();
		btc.calculateValue(inputFile);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
