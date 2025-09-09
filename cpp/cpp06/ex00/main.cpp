#include "ScalarConverter.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cout<<"Error\nBad arguments must be ./Scalar string";
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}