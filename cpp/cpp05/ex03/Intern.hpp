#pragma once
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{

	public:
		Intern() = default;
		~Intern() = default;
		Intern(const Intern& obj) = default;
		Intern & operator=(const Intern & obj) = default;

		AForm * makeForm(std::string name, std::string target);

};