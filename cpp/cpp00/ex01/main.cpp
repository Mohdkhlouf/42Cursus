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
	int index = 0;
	phonebook.phonebook_print();
	std::cout << "what are you searching for?, please enter a valid indx" << std::endl;
	std::cin >> index;
	while (1)
	{
		if (index >= 0 && index <= 8)
		{
			phonebook.single_contact_print(index);
			break;
		}
		else
		{
			std::cout << "please enter a valid index" << std::endl;
			std::cin >> index;
		}
	}
}
void add_contact(PhoneBook &phonebook)
{
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string secret;

	std::cout << "Please, type in contact First Name:" << std::endl;
	std::getline(std::cin, first_name);
	std::cout << "Please, type in contact Last Name:" << std::endl;
	std::getline(std::cin, last_name);
	std::cout << "Please, type in contact Nick Name:" << std::endl;
	std::getline(std::cin, nick_name);
	std::cout << "Please, type in contact Phone Number:" << std::endl;
	std::getline(std::cin, phone_number);
	std::cout << "Please, type in your secret:" << std::endl;
	std::getline(std::cin, secret);

	Contact contact(first_name, last_name, nick_name, phone_number, secret);
	phonebook.add(contact);
}

int main(void)
{
	std::string input_value;
	PhoneBook phonebook;

	while (true)
	{
		std::cout << "Welcome to PhoneBook:" << std::endl;
		std::cout << "type ADD, SEARCCH and EXIT " << std::endl;

		if (!std::getline(std::cin, input_value))
			{
				std::cin.ignore();
				// needs more protection
			}
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
