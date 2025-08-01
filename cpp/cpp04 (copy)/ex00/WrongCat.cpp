#include "WrongCat.hpp"

void WrongCat::makeSound()
{
	std::cout<<"WrongCat makes Cat sound Meao Meao Meao"<<std::endl;
}

WrongCat::WrongCat(){
	std::cout<<"WrongCat default constructor called"<<std::endl;
}

WrongCat::~WrongCat(){
	std::cout<<"WrongCat destructor called"<<std::endl;
}