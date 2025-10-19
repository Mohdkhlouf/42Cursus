#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring> 

void checkFile(std::ifstream &sfile,const std::string &fileName){
	
	sfile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try{
		sfile.open(fileName);
		std::cout<<"File Name is:"<<fileName<<std::endl;
	}catch (const std::exception &e){
		throw;
	}
}

int main(int argc, char **argv){
	std::ifstream inputFile;
	std::ifstream datafile;

	if ( argc != 2){
		std::cerr<<"Error\nit must be [btc filename]"<<std::endl;
		return (1);
	}
	try{
		// check data file
		checkFile(datafile,"data.csv");
		//check input file
		checkFile(inputFile,argv[1]);

	}catch (const std::exception &e){
		int errorCode = errno;
		std::string systemError = std::strerror(errorCode);
		std::cerr<<"Error\n"<<systemError<<std::endl;
		if(datafile.is_open())
			datafile.close();
		if (inputFile.is_open())
			inputFile.close();
	}
	
	return (0);
}