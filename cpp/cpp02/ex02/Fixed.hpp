#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int fpn_value; //fixed point number value
		static const int fractional_bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(int value);
		Fixed(float floatValue);
		Fixed(const Fixed &obj);
		Fixed& operator=(const Fixed &obj);
		int getRawBits() const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		//logical operations
		bool operator>(const Fixed &obj) const;
		bool operator<(const Fixed &obj)const;
		bool operator<=(const Fixed &obj)const;
		bool operator>=(const Fixed &obj)const;
		bool operator==(const Fixed &obj)const;
		bool operator!=(const Fixed &obj)const;
		//numeric operations
		Fixed operator+(const Fixed &obj)const;
		Fixed operator-(const Fixed &obj)const;
		Fixed operator*(const Fixed &obj)const;
		Fixed operator/(const Fixed &obj)const;
		//increment and decrement
		Fixed& operator++();
		Fixed&  operator--();
		Fixed&  operator++(int);
		Fixed&  operator--(int);
		//extra functions
		static Fixed& min(Fixed &obj1, Fixed &obj2);
		const static Fixed& min(const Fixed &obj1, const Fixed &obj2);
		static Fixed& max(Fixed &obj1, Fixed &obj2);
		const static Fixed& max(const Fixed &obj1, const Fixed &obj2);
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);
#endif