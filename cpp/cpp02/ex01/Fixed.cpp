#include "Fixed.hpp"

Fixed::Fixed():fpn_value(0)
{
	std::cout<<"Default constructor called"<<"\n";
}
Fixed::~Fixed(){
	std::cout<<"Destructor called"<<"\n";
};

Fixed::Fixed(const int value)
{
	std::cout<<"int constructor called"<<"\n";
	fpn_value = value << fractional_bits;
};
Fixed::Fixed(const float float_value)
{
	std::cout<<"Float constructor called"<<"\n";
	fpn_value = roundf(float_value * (1 << fractional_bits));
};

Fixed::Fixed(const Fixed &obj)
{
	std::cout<<"Copy constructor called"<<"\n";
	*this = obj;
};

Fixed &Fixed::operator=(const Fixed &obj){
	std::cout<<"Copy assignment operator called"<<"\n";
	if(this != &obj)
		fpn_value = obj.fpn_value;
	return (*this);
};

int Fixed::getRawBits() const{
	return(fpn_value);
};

void Fixed::setRawBits(int const raw){
	fpn_value = raw;
};

float Fixed::toFloat( void ) const{
	return (static_cast<float>(fpn_value) / (1<<fractional_bits));
}

int Fixed::toInt( void ) const{
	return( static_cast<int> (fpn_value >> fractional_bits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}