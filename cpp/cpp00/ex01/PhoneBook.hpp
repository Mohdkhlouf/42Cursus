#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int contacts_counter;
		int total_contacts;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void add(Contact& value);
		void phonebook_print(void);
};

#endif