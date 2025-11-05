#include "BitcoinExchange.hpp"

void	checkFile(std::ifstream &sfile, const std::string &fileName)
{
	sfile.open(fileName);
	if (!sfile)
	{
		throw std::runtime_error("Error\nconnot open the file");
	}
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
	
	try
	{
		checkFile(datafile, "data.csv");
		checkFile(inputFile, argv[1]);
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
