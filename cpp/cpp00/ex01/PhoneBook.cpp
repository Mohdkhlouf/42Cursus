#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(void)
{
	this->contacts_counter = 0;
	this->total_contacts = 0;
	return;
}
PhoneBook::~PhoneBook(void)
{
	std::cout << "destructer started" << std::endl;
	return;
}

void PhoneBook::add(Contact &contact)
{
	this->contacts[this->contacts_counter] = contact;
	this->contacts_counter++;
	this->total_contacts++;
	if (this->contacts_counter > 8)
	{
		std::cout << "the array is full" << std::endl;
		this->contacts_counter = 0;
	}
	if (this->total_contacts > 8)
		this->total_contacts = 8;
	std::cout << "contact is added" << this->contacts_counter << std::endl;
}

void PhoneBook::phonebook_print(void)
{
	std::cout << "PHONEBOOK Contacts are:" << std::endl;
	std::cout << std::setw(10) << "INDEX" << "|" << std::setw(10) << "FIRSTNAME" << "|" << std::setw(10) << "LASTNAME" << "|" << std::setw(10) << "NICKNAME" << std::endl;
	int i;
	i = 0;
	while (i < this->total_contacts)
	{
		std::cout << std::setw(10) << std::right << i << "|"
				  << std::setw(10) << std::right << this->contacts[i].get_first_name() << "|"
				  << std::setw(10) << std::right << this->contacts[i].get_last_name() << "|"
				  << std::setw(10) << std::right << this->contacts[i].get_nick_name() << std::endl;
		i++;
	}
}