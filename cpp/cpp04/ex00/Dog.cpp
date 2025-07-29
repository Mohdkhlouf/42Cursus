#include "Dog.hpp"

Dog::Dog(){
	std::cout<<"Dog default constructor called."<<std::endl;
	type= "Dog";
}
Dog::Dog(std::string type)
{
	std::cout<<"Dog Parameterized constructor called."<<std::endl;
}
Dog::Dog(Dog &obj)
{
	std::cout<<"Dog Copy constructor called."<<std::endl;
	*this = obj;
}
Dog& Dog::operator=(Dog& dog)
{
	if(this != &dog)
	{
		*this = dog;
		return(*this);
	}
	else
		return(*this);
}
Dog::~Dog()
{
		std::cout<<"Dog Destructor called."<<std::endl;

}

void Dog::makeSound()
{
	std::cout<<"Cat sound is Woof Woof."<<std::endl;
}
