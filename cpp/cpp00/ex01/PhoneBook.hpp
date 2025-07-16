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
		PhoneBook();
		~PhoneBook();
		void add(const Contact& value);
		void phonebook_print() const;
		void single_contact_print(int index) const;
		int get_counter();
		int get_total();
};

#endif
