#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string secret;

public:
	Contact(void);
	Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string secret);
	~Contact(void);
	std::string print(void);
	std::string const get_first_name(void);
	std::string const get_last_name(void);
	std::string const get_nick_name(void);
	std::string const get_phone_number(void);
	std::string const get_secret(void);
};

#endif