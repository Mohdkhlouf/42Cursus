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
		//orthodox canonicals
		Fixed();
		~Fixed();
		Fixed(const int value);
		Fixed(const float floatValue);
		Fixed(const Fixed &obj);
		Fixed& operator=(const Fixed &obj);

		// extra functions
		int getRawBits() const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};
std::ostream &operator<<(std::ostream &os, const Fixed &obj);

#endif