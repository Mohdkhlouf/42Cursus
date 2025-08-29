#pragma once

#include <iostream>
#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

class Bureaucrat;

class Form{
	private:
		const std::string name_;
		bool is_signed;
		const int signItGrade_;
		const int executeItGrade_;
	public:
		Form();
		Form(std::string name, int signitgrade, int executeitgrade);
		~Form();
		Form(const Form &obj);
		Form &operator=(const Form& obj);
		std::string getName() const;
		int getSignItGrade() const;
		int getExecuteItGrade() const;
		bool getSignedStatus() const;
		void beSigned(Bureaucrat &obj);

};
std::ostream &operator<<(std::ostream &os, const Form &obj);