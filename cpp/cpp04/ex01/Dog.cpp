#include "Dog.hpp"

Dog::Dog(){
	std::cout<<"Dog default constructor called."<<std::endl;
	type= "Dog";
	BrainPtr = new Brain();
}
Dog::Dog(std::string type)
{
	std::cout<<"Dog Parameterized constructor called."<<std::endl;
	this->type =type;
}
Dog::Dog(const Dog &obj)
{
	std::cout<<"Dog Copy constructor called."<<std::endl;
	*this = obj;
}

Dog& Dog::operator=(const Dog& obj)
{
	if(this != &obj)
		type = obj.type;
	return(*this);
}

Dog::~Dog()
{
	std::cout<<"Dog Destructor called."<<std::endl;
	delete BrainPtr;
}

void Dog::makeSound() const
{
	std::cout<<"Dog sound is Woof Woof."<<std::endl;
}
