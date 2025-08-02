#include "Dog.hpp"

Dog::Dog():Animal("Dog"){
	std::cout<<"Dog default constructor called."<<std::endl;
	type= "Dog";
}

Dog::Dog(const Dog &obj):Animal(obj)
{
	std::cout<<"Dog Copy constructor called."<<std::endl;
	*this = obj;
}
Dog& Dog::operator=(const Dog& obj)
{
	if(this != &obj)
		Animal::operator=(obj);
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
