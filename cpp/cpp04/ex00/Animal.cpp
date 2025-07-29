#include "Animal.hpp"

Animal::Animal(){
	std::cout<<"Animal default constructor called."<<std::endl;
	type = "Animal";
}
Animal::Animal(std::string type)
{
	std::cout<<"Animal parameterized constructor called."<<std::endl;
	this->type= type;
}
Animal::Animal(Animal &obj)
{
	std::cout<<"Animal copy constructor called."<<std::endl;
	*this = obj;
}
Animal & Animal::operator=(Animal &obj)
{
	if (this != &obj)
	{
		*this = obj;
		return (*this);
	}
	else
		return(*this);
}

Animal::~Animal()
{
	std::cout<<"Animal default destructor called."<<std::endl;
}

void Animal::makeSound() const{
	std::cout<<"Animal is make an animal sound"<<std::endl;
}

std::string Animal::getType()const
{
	return (type);
}