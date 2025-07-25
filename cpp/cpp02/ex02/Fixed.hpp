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
		void operator++();
		void operator--();
		void operator++(int);
		void operator--(int);





};
std::ostream &operator<<(std::ostream &os, const Fixed &obj);
#endif