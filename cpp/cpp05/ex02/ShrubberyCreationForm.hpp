#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm: private AForm{
	public:
		ShrubberyCreationForm(std::string &home);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &obj);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &obj);
};