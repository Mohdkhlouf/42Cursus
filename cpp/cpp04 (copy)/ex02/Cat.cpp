#include "Cat.hpp"

Cat::Cat(){
	std::cout<<"Cat default constructor called."<<std::endl;
	type = "Cat";
	BrainPtr = new Brain();
}
Cat::Cat(std::string type)
{
	std::cout<<"Cat Parameterized constructor called."<<std::endl;
}
Cat::Cat(const Cat &obj)
{
	std::cout<<"Cat Copy constructor called."<<std::endl;
	*this = obj;
}
Cat& Cat::operator=(const Cat& Cat)
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
		delete BrainPtr;

}

void Cat::makeSound() const{
	std::cout<<"Cat sound is Meao Meao."<<std::endl;
}

