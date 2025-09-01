#pragma once
#include <exception>
#include <iostream>

class GradeTooLowException : public std::exception
{
private:
	std::string message;

public:
	GradeTooLowException(const char *msg);
	const char *what() const noexcept override;
};