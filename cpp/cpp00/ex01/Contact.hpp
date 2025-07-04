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
	Contact();
	Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string secret);
	~Contact();
	const std::string &get_first_name() const;
	const std::string &get_last_name() const;
	const std::string &get_nick_name() const;
	const std::string &get_phone_number() const;
	const std::string &get_secret() const;
};

#endif