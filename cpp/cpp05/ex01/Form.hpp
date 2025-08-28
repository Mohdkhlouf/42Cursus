#pragma once
#include <iostream>
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "Bureaucrat.hpp"

class Form{
	private:
		const std::string name_;
		bool is_signed;
		const int signItGrade_;
		const int executeItGrade_;
	public:
		const std::string getName();
		const int getSignItGrade();
		const int getExecuteItGrade();
		bool getSignedStatus();
		beSigned(Bureaucrat &bureaucrat)

};
std::ostream &operator<<(std::ostream &os, const Form &obj);