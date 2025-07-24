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


};
#endif