#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdlib>

void exit_phonebook(PhoneBook &phonebook)
{
	std::cout << "Exiting... Bye!" << std::endl;
	phonebook.~PhoneBook();
	std::exit(0);
}

void search_contact(PhoneBook &phonebook)
{
	phonebook.phonebook_print();
}
void add_contact(PhoneBook &phonebook)
{
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string secret;

	std::cout << "Please, type in contact First Name:" << std::endl;
	std::cin >> first_name;
	std::cout << "Please, type in contact Last Name:" << std::endl;
	std::cin >> last_name;
	std::cout << "Please, type in contact Nick Name:" << std::endl;
	std::cin >> nick_name;
	std::cout << "Please, type in contact Phone Number:" << std::endl;
	std::cin >> phone_number;
	std::cout << "Please, type in your secret:" << std::endl;
	std::cin >> secret;

	Contact contact(first_name, last_name, nick_name, phone_number, secret);
	phonebook.add(contact);
}

int main(void)
{
	std::string input_value;
	PhoneBook phonebook;

	while (true)
	{
		std::cout << "************************************" << std::endl;
		std::cout << "Welcome to PhoneBook:" << std::endl;
		std::cout << "Type you want me to do, please:" << std::endl;
		std::cout << "type ADD if you need me to add new contact." << std::endl;
		std::cout << "type SEARCH if you need me to find a contact." << std::endl;
		std::cout << "type EXIT if you need me to exit." << std::endl;
		std::cin >> input_value;
		if (input_value.compare("ADD") == 0)
			add_contact(phonebook);
		else if (input_value.compare("SEARCH") == 0)
			search_contact(phonebook);
		else if (input_value.compare("EXIT") == 0)
			exit_phonebook(phonebook);
		else
			std::cout << "Unknown Value,try again" << std::endl
					  << std::endl
					  << std::endl;
	}
	return (0);
}