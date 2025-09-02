#pragma once
#include "AForm.hpp"


class RobotomyRequestForm: private AForm{
	private:
		std::string target_;

	public:
		RobotomyRequestForm(std::string &target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &obj);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &obj);
		bool virtual execute(Bureaucrat const & executor) const override;
};