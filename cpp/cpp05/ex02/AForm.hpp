#pragma once

#include <iostream>
#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

class Bureaucrat;

class AForm{
	private:
		const std::string name_;
		bool is_signed;
		const int signItGrade_;
		const int executeItGrade_;

	public:
		AForm();
		AForm(std::string name, int signitgrade, int executeitgrade);
		~AForm();
		AForm(const AForm &obj);
		AForm &operator=(const AForm& obj);
		std::string getName() const;
		int getSignItGrade() const;
		int getExecuteItGrade() const;
		bool getSignedStatus() const;
		void beSigned(Bureaucrat &obj);
		bool virtual execute(Bureaucrat const & executor) const = 0;

};
std::ostream &operator<<(std::ostream &os, const AForm &obj);