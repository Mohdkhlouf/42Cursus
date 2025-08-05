#include "AMateria.hpp"

AMateria::AMateria()
{
	type = "unset";
	// std::cout<<"AMateria default constructor called."<<std::endl;
}
AMateria::AMateria(std::string const & type)
{
	// std::cout<<"AMateria parameterized constructor called."<<std::endl;
	this->type = type;
}
AMateria::~AMateria()
{
	// std::cout<<"AMateria destructor called."<<std::endl;
}

AMateria::AMateria(const AMateria & obj):type(obj.type)
{
	// std::cout<<"AMateria copy constructor called."<<std::endl;
}

AMateria& AMateria::operator=(const AMateria &obj)
{
	// std::cout<<"AMateria assignment operator called."<<std::endl;
	if (this != &obj)
	{
		type = obj.type;
	}
	return (*this);
}


std::string const & AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter& target)
{
	(void) target;
	// std::cout<<"ICharacter base use message"<<std::endl;
}