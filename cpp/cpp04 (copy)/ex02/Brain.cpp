#include "Brain.hpp"

Brain::Brain(){
	std::cout<<"Brain default constructor called"<<std::endl;
}

Brain::Brain(const Brain &obj)
{
	std::cout<<"Brain Copy constructor called"<<std::endl;
	*this = obj;
}
Brain& Brain::operator=(const Brain &obj)
{
	std::cout<<"Brain assignment operator called"<<std::endl;
	if(this != &obj)
	{
		*this = obj;
		return (*this);
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout<<"Brain default destructor called"<<std::endl;
}