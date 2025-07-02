#include <iostream>
#include "Contact.hpp"
int main(void)
{
	std::string first_name;
	std::string last_name;
	std::string phone_number;
	std::string secret;


	std::cout<<"Please, type in your choice:"<<std::endl;
	std::cin >> first_name;
	std::cin >> last_name;
	std::cin >> phone_number;
	std::cin >> secret;


	Contact contact(first_name, last_name, phone_number, secret);
	contact.print();
	return (0);
}