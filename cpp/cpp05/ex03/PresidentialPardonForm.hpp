#pragma once
#include "AForm.hpp"

class PresidentialPardonForm: public AForm{
	private:
		std::string target_;

	public:
		PresidentialPardonForm(const std::string &target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &obj);
		bool virtual execute(Bureaucrat const & executor) const override;	
};
