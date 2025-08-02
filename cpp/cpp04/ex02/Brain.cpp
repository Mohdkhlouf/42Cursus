#include "Brain.hpp"

Brain::Brain() {
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
	if (this != &obj)
		for(int i =0; i < 100 ; i++)
			ideas_[i] = obj.ideas_[i];
	return(*this);
}

Brain::~Brain()
{
	std::cout<<"Brain default destructor called"<<std::endl;
}