#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
class Fixed
{
	private:
		int fpn_value;
		static const int n_counters = 8;
	public:
		//orthodox canonical
		Fixed();
		~Fixed();
		Fixed(int value);
		Fixed(const Fixed &obj);
		Fixed& operator=(const Fixed &obj);

		//extra functions
		int getRawBits() const;
		void setRawBits( int const raw );
};
#endif