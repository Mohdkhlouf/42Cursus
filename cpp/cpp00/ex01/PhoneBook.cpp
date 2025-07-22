/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:21:09 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/07/22 11:21:10 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->contacts_counter = 0;
	this->total_contacts = 0;
	return;
}
PhoneBook::~PhoneBook()
{
}

void PhoneBook::add(const Contact &contact)
{
	if (this->contacts_counter == 8)
		this->contacts_counter = 0;
	this->contacts[this->contacts_counter] = contact;
	this->contacts_counter++;
	this->total_contacts++;
	if (this->total_contacts >= 8)
		this->total_contacts = 8;
}

std::string trunc_dot(std::string string)
{
	if (string.length() > 10)
	{
		string = string.substr(0, 10);
		string[9] = '.';
	}
	return (string);
}

void PhoneBook::phonebook_print() const
{
	std::cout << "PHONEBOOK Contacts are:" << std::endl;
	std::cout << std::setw(10) << "INDEX" << "|" << std::setw(10) << "FIRSTNAME" << "|" << std::setw(10) << "LASTNAME" << "|" << std::setw(10) << "NICKNAME" << std::endl;
	int i;
	i = 0;
	while (i < this->total_contacts)
	{
		std::cout << std::setw(10) << std::right << i << "|"
				  << std::setw(10) << std::right << trunc_dot(this->contacts[i].get_first_name()) << "|"
				  << std::setw(10) << std::right << trunc_dot(this->contacts[i].get_last_name()) << "|"
				  << std::setw(10) << std::right << trunc_dot(this->contacts[i].get_nick_name()) << std::endl;
		i++;
	}
}

void PhoneBook::single_contact_print(int i) const
{
	std::cout << "Firstname: " << this->contacts[i].get_first_name() << std::endl;
	std::cout << "Lastname: " << this->contacts[i].get_last_name() << std::endl;
	std::cout << "Nickname: " << this->contacts[i].get_nick_name() << std::endl;
	std::cout << "Phone number: " << this->contacts[i].get_phone_number() << std::endl;
	std::cout << "Secret: " << this->contacts[i].get_secret() << std::endl;
}


int PhoneBook::get_counter()
{
	return this->contacts_counter;
}

int PhoneBook::get_total()
{
	return this->total_contacts;
}