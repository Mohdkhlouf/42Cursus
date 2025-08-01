#include "Dog.hpp"

Dog::Dog(){
	std::cout<<"Dog default constructor called."<<std::endl;
	this->type= "Dog";
}
Dog::Dog(std::string type)
{
	std::cout<<"Dog Parameterized constructor called."<<std::endl;
	this->type = type;
}
Dog::Dog(const Dog &obj)
{
	std::cout<<"Dog Copy constructor called."<<std::endl;
	*this = obj;
}
Dog& Dog::operator=(const Dog& dog)
{
	if(this != &dog)
		type= dog.type;
	return(*this);
}
Dog::~Dog()
{
		std::cout<<"Dog Destructor called."<<std::endl;

}

void Dog::makeSound() const
{
	std::cout<<"Dog sound is Woof Woof."<<std::endl;
}
