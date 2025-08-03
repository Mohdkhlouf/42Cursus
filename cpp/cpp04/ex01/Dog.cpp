#include "Dog.hpp"

Dog::Dog():Animal("Dog"){
	std::cout<<"Dog default constructor called."<<std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog &obj):Animal(obj)
{
	std::cout<<"Dog Copy constructor called."<<std::endl;
	this->brain = new Brain(*obj.brain);
}

Dog& Dog::operator=(const Dog& obj)
{
	if(this != &obj)
	{
		Animal::operator=(obj);
		delete this->brain;
		this->brain = new Brain(*obj.brain);
	}
		
	return(*this);
}
Dog::~Dog()
{
	std::cout<<"Dog Destructor called."<<std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout<<"Dog sound is Woof Woof."<<std::endl;
}

std::string Dog::getIdea(unsigned int index)
{
	return (brain->getIdea(index));
}

void Dog::setIdea(unsigned int index, std::string idea)
{
	brain->setIdea(index, idea);
}