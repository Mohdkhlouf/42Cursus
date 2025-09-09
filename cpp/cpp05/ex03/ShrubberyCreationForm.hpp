#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm{
	private:
		std::string target_;

	public:
		ShrubberyCreationForm(const std::string &target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &obj);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &obj);
		bool virtual execute(Bureaucrat const & executor) const override;
		void draw_trees(const std::string &target) const;
};
