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
Animal::Animal(const Animal &obj)
{
	std::cout<<"Animal copy constructor called."<<std::endl;
	*this = obj;
}
Animal & Animal::operator=(const Animal &obj)
{
	if (this != &obj)
			type = obj.type;
	return(*this);
}

Animal::~Animal()
{
	std::cout<<"Animal destructor called."<<std::endl;
}

void Animal::makeSound() const{
	std::cout<<"Animal makes an animal sound"<<std::endl;
}

std::string Animal::getType()const
{
	return (type);
}