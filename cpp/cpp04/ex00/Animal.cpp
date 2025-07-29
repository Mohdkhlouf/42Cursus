#include "Animal.hpp"

Animal::Animal(){
	std::cout<<"Animal default constructor called."<<std::endl;
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