#include "Cat.hpp"

Cat::Cat():Animal("Cat"){
	std::cout<<"Cat default constructor called."<<std::endl;
	brain = new Brain();
}

Cat::Cat(const Cat &obj):Animal(obj)
{
	std::cout<<"Cat Copy constructor called."<<std::endl;
	brain = new Brain(*obj.brain);
}

Cat& Cat::operator=(const Cat& obj){
	if(this != &obj)
	{
		Animal::operator=(obj);
		delete brain;
		brain = new Brain(*obj.brain);
	}
	return(*this);
}

Cat::~Cat()
{
	std::cout<<"Cat Destructor called."<<std::endl;
	delete brain;
}

void Cat::makeSound() const{
	std::cout<<"Cat sound is Meao Meao."<<std::endl;
}

std::string Cat::getIdea(unsigned int index)
{
	return (brain->getIdea(index));
}

void Cat::setIdea(unsigned int index, std::string idea)
{
	brain->setIdea(index, idea);
}