#include "Cat.hpp"

Cat::Cat(){
	std::cout<<"Cat default constructor called."<<std::endl;
	type = "Cat";
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
Cat& Cat::operator=(const Cat& obj)
{
	if(this != &obj)
		type = obj.type;
	return(*this);
}
Cat::~Cat()
{
		std::cout<<"Cat Destructor called."<<std::endl;

}

void Cat::makeSound() const{
	std::cout<<"Cat sound is Meao Meao."<<std::endl;
}

