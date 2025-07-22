/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:21:16 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/07/22 11:21:17 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// this is the initiaization list to add the variables directly to the values,

Contact::Contact()
{
}

Contact::Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string secret)
	: first_name(first_name), last_name(last_name), nick_name(nick_name), phone_number(phone_number), secret(secret)
{
}

Contact::~Contact()
{
}

const std::string &Contact::get_first_name() const
{
	return (this->first_name);
}

const std::string &Contact::get_last_name() const
{
	return (this->last_name);
}

const std::string &Contact::get_nick_name() const
{
	return (this->nick_name);
}

const std::string &Contact::get_phone_number() const
{
	return (this->phone_number);
}

const std::string &Contact::get_secret() const
{
	return (this->secret);
}