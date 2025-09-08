
#include "ScalarConverter.hpp"


void ScalarConverter::convert(std::string &str){

	std::cout<<"char: "<<str.c_str()<<std::endl;
	std::cout<<"Int: "<<std::stoi(str)<<std::endl;

}