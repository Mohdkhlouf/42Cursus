
#include <iostream>
#include "Contact.hpp"

//this is the initiaization list to add the variables directly to the values,

Contact::Contact(void)
{
	return;
}

Contact::Contact(std::string first_name, std::string last_name,	std::string nick_name, std::string phone_number, std::string secret) : first_name(first_name), last_name(last_name),nick_name(nick_name), phone_number(phone_number), secret(secret)
{
	return;
}

Contact::~Contact(void)
{
	return;
}


std::string trunc_dot(std::string string)
{
	if(string.length() >10)
		{
			string = string.substr(0,10);
			string[9] = '.';
		}
	return(string);
}
std::string const Contact::get_first_name(void)
{
	return(trunc_dot(this->first_name));	
}

std::string const Contact::get_last_name(void)
{
	return(trunc_dot(this->last_name));	
}

std::string const Contact::get_nick_name(void)
{
	return(trunc_dot(this->nick_name));	
}
std::string Contact::print(void){
	std::string result;
	result = this->first_name + "|" + this->last_name + "|" + this->nick_name;
	return(result);
}