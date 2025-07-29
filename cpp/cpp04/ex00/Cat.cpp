#include "Cat.hpp"

Cat::Cat(){
	std::cout<<"Cat default constructor called."<<std::endl;
	type = "Cat";
}
Cat::Cat(std::string type)
{
	std::cout<<"Cat Parameterized constructor called."<<std::endl;
}
Cat::Cat(Cat &obj)
{
	std::cout<<"Cat Copy constructor called."<<std::endl;
	*this = obj;
}
Cat& Cat::operator=(Cat& Cat)
{
	if(this != &Cat)
	{
		*this = Cat;
		return(*this);
	}
	else
		return(*this);
}
Cat::~Cat()
{
		std::cout<<"Cat Destructor called."<<std::endl;

}

void Cat::makeSound()
{
	std::cout<<"Cat sound is Meao Meao."<<std::endl;
}

