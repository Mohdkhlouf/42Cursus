#pragma once
#include "AForm.hpp"
#include <stdlib.h>

class RobotomyRequestForm: public AForm{
	private:
		std::string target_;

	public:
		RobotomyRequestForm(const std::string &target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &obj);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &obj);
		bool virtual execute(Bureaucrat const & executor) const override;
};