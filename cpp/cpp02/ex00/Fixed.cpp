#include "Fixed.hpp"

Fixed::Fixed()
{
	fpn_value = 0;
	std::cout<<"Default constructor called"<<"\n";
}
Fixed::~Fixed(){
	std::cout<<"Destructor called"<<"\n";
};

Fixed::Fixed(int value)
{
	fpn_value = value;
};

Fixed::Fixed(const Fixed &obj)
{
	std::cout<<"Copy constructor called"<<"\n";
	this->fpn_value = obj.getRawBits();
	
};

Fixed& Fixed::operator=(const Fixed &obj){
	std::cout<<"Copy assignment operator called"<<"\n";
	if(this != &obj)
		this->fpn_value = obj.getRawBits();
	
	return(*this);
};

int Fixed::getRawBits() const{
	std::cout<<"getRawBits member function called"<<"\n";
	return(fpn_value);
};

void Fixed::setRawBits(int const raw){
	std::cout<<"setRawBits member function called"<<"\n";
	fpn_value = raw;
};
