#pragma once
#include <exception>
#include <iostream>

class GradeTooHighException : public std::exception
{
private:
	std::string msg;

public:
	GradeTooHighException(const char *message);
	const char *what() const noexcept override;
};