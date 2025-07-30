#include "WrongCat.hpp"

void WrongCat::makeSound()
{
	std::cout<<"Wrong Cat makes Cat sound Meao Meao Meao"<<std::endl;
}

WrongCat::WrongCat(){
	std::cout<<"Wrong Cat default constructor called"<<std::endl;
}

WrongCat::~WrongCat(){
	std::cout<<"Wrong Cat destructor called"<<std::endl;
}