#include "phonebook.h"

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
	if (!std::getline(std::cin, first_name))
		handle_failed_getline(first_name);
	std::cout << "Please, type in contact Last Name:" << std::endl;
	if (!std::getline(std::cin, last_name))
		handle_failed_getline(last_name);
	std::cout << "Please, type in contact Nick Name:" << std::endl;
	if (!std::getline(std::cin, nick_name))
		handle_failed_getline(nick_name);
	std::cout << "Please, type in contact Phone Number:" << std::endl;
	if (!std::getline(std::cin, phone_number))
		handle_failed_getline(phone_number);
	std::cout << "Please, type in your secret:" << std::endl;
	if (!std::getline(std::cin, secret))
		handle_failed_getline(secret);

	Contact contact(first_name, last_name, nick_name, phone_number, secret);
	phonebook.add(contact);
}
void handle_failed_getline(std::string &input)
{
	std::cin.clear();  // to reset the error to default.
	std::cin.ignore(); // to remove the leftovers from the function
	if (!std::getline(std::cin, input))
		handle_failed_getline(input);
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
			handle_failed_getline(input_value);
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
