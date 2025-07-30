#include "WrongAnimal.hpp"

void WrongAnimal::makeSound()
{
	std::cout<<"Wrong Animal makes sound"<<std::endl;
}

WrongAnimal::WrongAnimal(){
	std::cout<<"Wrong Cat default constructor called"<<std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout<<"Wrong Cat destructor called"<<std::endl;
}