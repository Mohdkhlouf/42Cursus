#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string phone_number;
		std::string secret;

	public:
		Contact(std::string first_name,std::string last_name, std::string phone_number, std::string secret);
		~Contact(void);
		void print(void);
};

#endif