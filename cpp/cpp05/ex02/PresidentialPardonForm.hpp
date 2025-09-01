#pragma once
#include "AForm.hpp"

class PresidentialPardonForm: private AForm{
	public:
		PresidentialPardonForm(std::string &home);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &obj);
		
};