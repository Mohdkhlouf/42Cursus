/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:21:12 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/07/22 11:21:13 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

#include <limits>

void exit_phonebook(PhoneBook &phonebook)
{
	std::cout << "Exiting... Bye!" << std::endl;
	phonebook.~PhoneBook();
	std::exit(0);
}

void search_contact(PhoneBook &phonebook)
{
	int index = 0;

	if (phonebook.get_counter() == 0)
		std::cerr << "The phonebook is empty\n**********************************************\n";
	else
	{
		phonebook.phonebook_print();
		while (1)
		{
			std::cout << "what are you searching for?, please enter a valid index" << std::endl;
			std::cin >> index;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Not a NUMBER\n";
			}
			else
			{
				if (index >= 0 && index <= phonebook.get_total())
				{
					phonebook.single_contact_print(index);
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					break;
				}
				else
					std::cout << "please enter a valid index" << std::endl;
		
			}
			
		}
	}
}

bool check_digits(std::string str)
{
	for (char i : str)
	{
		if (i < 48 || i > 57)
			return (false);
	}
	return (true);
}

void add_contact(PhoneBook &phonebook)
{
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string secret;

	while (first_name.empty())
	{
		std::cout << "Please, type in contact First Name:" << std::endl;
		if (!std::getline(std::cin, first_name))
			handle_failed_getline();
	}
	while (last_name.empty())
	{
		std::cout << "Please, type in contact Last Name:" << std::endl;
		if (!std::getline(std::cin, last_name))
			handle_failed_getline();
	}

	while (nick_name.empty())
	{
		std::cout << "Please, type in contact Nick Name:" << std::endl;
		if (!std::getline(std::cin, nick_name))
			handle_failed_getline();
	}
	while (phone_number.empty() || !check_digits(phone_number))
	{
		std::cout << "Please, type in Phone Number *Numbers only*:" << std::endl;
		if (!std::getline(std::cin, phone_number))
			handle_failed_getline();
	}
	while (secret.empty())
	{
		std::cout << "Please, type in your secret:" << std::endl;
		if (!std::getline(std::cin, secret))
			handle_failed_getline();
	}
	Contact contact(first_name, last_name, nick_name, phone_number, secret);
	phonebook.add(contact);
}
void handle_failed_getline()
{
	std::cin.clear();  // to reset the error to default.
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // to remove the leftovers from the function
	std::exit(1);
}

int main(void)
{
	std::string input_value;
	PhoneBook phonebook;

	while (true)
	{
		std::cout << R"(
		|  __ \| |  | |/ __ \| \ | |  ____| __ ) / __ \ / __ \| |/ /
		| |__) | |__| | |  | |  \| | |__  |  _ \| |  | | |  | | ' / 
		|  ___/|  __  | |  | | . ` |  __| | |_) | |  | | |  | |  <  
		| |    | |  | | |__| | |\  | |____|____/| |__| | |__| | . \ 
		|_|    |_|  |_|\____/|_| \_|______|      \____/ \____/|_|\_\
		)" << "\n";
		std::cout << "Welcome to PhoneBook:" << std::endl
				  << "type ADD, SEARCH and EXIT " << std::endl;
		if (!std::getline(std::cin, input_value))
			handle_failed_getline();
		if (input_value == "ADD")
			add_contact(phonebook);
		else if (input_value == "SEARCH")
			search_contact(phonebook);
		else if (input_value == "EXIT")
			exit_phonebook(phonebook);
		else
			std::cout << "Unknown Value,try again" << std::endl
					  << std::endl
					  << std::endl;
	}
	return (0);
}
