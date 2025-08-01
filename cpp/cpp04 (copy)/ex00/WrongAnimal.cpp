#include "WrongAnimal.hpp"

void WrongAnimal::makeSound()
{
	std::cout<<"WrongAnimal makes sound"<<std::endl;
}

WrongAnimal::WrongAnimal(){
	std::cout<<"WrongCat default constructor called"<<std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout<<"WrongCat destructor called"<<std::endl;
}