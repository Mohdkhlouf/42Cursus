#include "Fixed.hpp"

Fixed::Fixed() : fpn_value(0)
{
	std::cout << "Default constructor called" << "\n";
	if(fractional_bits < 0)
		std::cerr<<"Negative values are not allowed"<<"\n";
	if (sizeof())
	

}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << "\n";
};

Fixed::Fixed(const int value)
{
	std::cout << "int constructor called" << "\n";
	fpn_value = value << fractional_bits;
};
Fixed::Fixed(const float float_value)
{
	std::cout << "Float constructor called" << "\n";
	fpn_value = static_cast<int>(roundf(float_value * (1 << fractional_bits)));
};

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << "\n";
	*this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << "\n";
	if (this != &obj)
		this->fpn_value = obj.getRawBits();
	return (*this);
};

int Fixed::getRawBits() const
{
	return (fpn_value);
};

void Fixed::setRawBits(int const raw)
{
	fpn_value = raw;
};

float Fixed::toFloat(void) const
{
	return (static_cast<float>(fpn_value) / (1 << fractional_bits));
}

int Fixed::toInt(void) const
{
	return (static_cast<int>(fpn_value >> fractional_bits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}


bool Fixed::operator>(const Fixed &obj) const
{
	return (this->fpn_value > obj.fpn_value);
}

bool Fixed::operator<(const Fixed &obj) const
{
	return (this->fpn_value < obj.fpn_value);
}

bool Fixed::operator<=(const Fixed &obj) const
{
	return (this->fpn_value <= obj.fpn_value);
}

bool Fixed::operator>=(const Fixed &obj) const
{
	return (this->fpn_value >= obj.fpn_value);
}

bool Fixed::operator==(const Fixed &obj) const
{
	return (this->fpn_value == obj.fpn_value);
}

bool Fixed::operator!=(const Fixed &obj) const
{
	return (this->fpn_value != obj.fpn_value);
}

Fixed Fixed::operator+(const Fixed &obj) const
{
	Fixed result;
	result.fpn_value = this->fpn_value + obj.fpn_value;
	return (result);
}

Fixed Fixed::operator-(const Fixed &obj) const
{
	Fixed result;
	result.fpn_value = this->fpn_value - obj.fpn_value;
	return (result);
}

Fixed Fixed::operator*(const Fixed &obj) const
{
	Fixed result;
	result.fpn_value = (this->fpn_value * obj.fpn_value) >> fractional_bits;
	return (result);
}

Fixed Fixed::operator/(const Fixed &obj) const
{
	if (obj.fpn_value == 0)
	{
		std::cerr << "divided by zero" << "\n";
		exit(EXIT_FAILURE);
	}
	Fixed result;
	result.fpn_value = (this->fpn_value<<fractional_bits / obj.fpn_value);
	return (result);
}

Fixed&   Fixed::operator++()
{
	this->fpn_value++;
	return(*this);
}
Fixed&   Fixed::operator--()
{
	this->fpn_value--;
	return(*this);
}
Fixed&  Fixed::operator++(int)
{
	Fixed *tmp = this;
	this->fpn_value++;
	return(*tmp);
}
Fixed&  Fixed::operator--(int)
{
	Fixed *tmp = this;
	this->fpn_value--;
	return(*tmp);
}

Fixed& Fixed::min( Fixed &obj1, Fixed &obj2){
	if(obj1<obj2)
		return(obj1);
	else
		return(obj2);
}

const Fixed& Fixed::min( const Fixed &obj1, const Fixed &obj2){
	if(obj1<obj2)
		return(obj1);
	else
		return(obj2);
}

Fixed& Fixed::max( Fixed &obj1, Fixed &obj2){
	if(obj1<obj2)
		return(obj2);
	else
		return(obj1);
}

const Fixed& Fixed::max( const Fixed &obj1, const Fixed &obj2){
	if(obj1<obj2)
		return(obj2);
	else
		return(obj1);
}
