#include "BitcoinExchange.hpp"
#include <iostream>

bool checkFile(const std::string &fileName){
	std::cout<<"File Name is:"<<fileName<<std::endl;
	return (true);
}

int main(int argc, char **argv){

	if ( argc != 2){
		std::cout<<"Error\nit must be [btc filename]"<<std::endl;
		return (1);
	}
		
	checkFile(argv[1]);
	return (0);
}