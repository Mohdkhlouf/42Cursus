
#include <iostream>
#include "Contact.hpp"

//this is the initiaization list to add the variables directly to the values, 
Contact::Contact(std::string first_name, std::string last_name, std::string phone_number, std::string secret) : first_name(first_name), last_name(last_name), phone_number(phone_number), secret(secret)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

void Contact::print(){
	std::cout<<this->first_name<<" "<<this->last_name<<" "<<this->phone_number<<" "<< this->secret<< std::endl;
}