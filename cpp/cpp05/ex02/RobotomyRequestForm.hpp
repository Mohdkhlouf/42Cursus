#pragma once
#include "AForm.hpp"


class RobotomyRequestForm: private AForm{
	public:
		RobotomyRequestForm(std::string &home);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &obj);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &obj);
		
};