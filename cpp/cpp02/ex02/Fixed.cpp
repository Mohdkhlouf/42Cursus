#include "Fixed.hpp"

// Constructors & Destructor

Fixed::Fixed() : fpn_value(0)
{
	std::cout << "Default constructor called"
				<< "\n";
	if (fractional_bits != 8)
		throw std::runtime_error("Fractional Bits must be 8 \n");
}

Fixed::Fixed(const int value)
{
		std::cout << "int constructor called"<< "\n";
	long long int	tmp;

	tmp = static_cast<long>(value << fractional_bits);
	if (tmp > INT32_MAX || tmp < INT32_MIN)
	{
		fpn_value = (tmp > INT32_MAX) ? INT32_MAX : INT32_MIN;
	}
	else
		fpn_value = static_cast<int>(tmp);
};
Fixed::Fixed(const float float_value)
{
	std::cout << "Float constructor called"	<< "\n";
	long long int tmp = static_cast<long>(roundf(float_value * (1 << fractional_bits)));
	if (tmp > INT32_MAX || tmp < INT32_MIN)
	{
		fpn_value = (tmp > INT32_MAX) ? INT32_MAX : INT32_MIN;
	}
	else
		fpn_value = static_cast<int>(tmp);
};
Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called"
				<< "\n";
	*this = obj;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called"
				<< "\n";
};
// Setters and Getters
int Fixed::getRawBits() const
{
	return (fpn_value);
};
void Fixed::setRawBits(int const raw)
{
	fpn_value = raw;
};
// Converting Functions
float Fixed::toFloat(void) const
{
	return (static_cast<float>(roundf(fpn_value) / (1 << fractional_bits)));
}

int Fixed::toInt(void) const
{
	return (static_cast<int>(fpn_value >> fractional_bits));
}

// Operators overloading
Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called"
				<< "\n";
	if (this != &obj)
		this->fpn_value = obj.getRawBits();
	return (*this);
};
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

// numeric functions
Fixed Fixed::operator+(const Fixed &obj) const
{
	Fixed result;
	long long int tmp = static_cast<long long int>(this->fpn_value
			+ obj.fpn_value);
	if (tmp > INT32_MAX || tmp < INT32_MIN)
		result.fpn_value = (tmp > INT32_MAX) ? INT32_MAX : INT32_MIN;
	else
		result.fpn_value = static_cast<int>(tmp);
	return (result);
}

Fixed Fixed::operator-(const Fixed &obj) const
{
	Fixed result;
	long long int tmp = static_cast<long long int>(this->fpn_value
			- obj.fpn_value);
	if (tmp > INT32_MAX || tmp < INT32_MIN)
		result.fpn_value = (tmp > INT32_MAX) ? INT32_MAX : INT32_MIN;
	else
		result.fpn_value = static_cast<int>(tmp);
	return (result);
}

Fixed Fixed::operator*(const Fixed &obj) const
{
	Fixed result;
	long long int tmp = static_cast<long long int>((this->fpn_value
				* obj.fpn_value) >> fractional_bits);
	if (tmp > INT32_MAX || tmp < INT32_MIN)
		result.fpn_value = (tmp > INT32_MAX) ? INT32_MAX : INT32_MIN;
	else
		result.fpn_value = static_cast<int>(tmp);
	return (result);
}

Fixed Fixed::operator/(const Fixed &obj) const
{
	if (obj.fpn_value == 0)
	{
		throw std::runtime_error("divided by Zero value");
	}

	Fixed result;
	long long int tmp = static_cast<long long int>((this->fpn_value << fractional_bits)
			/ obj.fpn_value);
	if (tmp > INT32_MAX || tmp < INT32_MIN)
		result.fpn_value = (tmp > INT32_MAX) ? INT32_MAX : INT32_MIN;
	else
		result.fpn_value = static_cast<int>(tmp);
	return (result);
}

// increment and decrement operators
Fixed &Fixed::operator++()
{
	long long int	tmp;

	tmp = fpn_value + 1;
	if (tmp > INT32_MAX || tmp < INT32_MIN)
		fpn_value = (tmp > INT32_MAX) ? INT32_MAX : INT32_MIN;
	else
		fpn_value = static_cast<int>(tmp);
	return (*this);
}
Fixed &Fixed::operator--()
{
	long long int	tmp;

	tmp = fpn_value - 1;
	if (tmp > INT32_MAX || tmp < INT32_MIN)
		fpn_value = (tmp > INT32_MAX) ? INT32_MAX : INT32_MIN;
	else
		fpn_value = static_cast<int>(tmp);
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed	tmp(*this);
	fpn_value = fpn_value +1;
	return (tmp);
}
Fixed Fixed::operator--(int)
{
	Fixed	tmp(*this);
	fpn_value = fpn_value -1;
	return (tmp);
}

// Comparing functions
Fixed &Fixed::min(Fixed &obj1, Fixed &obj2)
{
	if (obj1 < obj2)
		return (obj1);
	else
		return (obj2);
}

const Fixed &Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
	if (obj1 < obj2)
		return (obj1);
	else
		return (obj2);
}

Fixed &Fixed::max(Fixed &obj1, Fixed &obj2)
{
	if (obj1 < obj2)
		return (obj2);
	else
		return (obj1);
}

const Fixed &Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
	if (obj1 < obj2)
		return (obj2);
	else
		return (obj1);
}
