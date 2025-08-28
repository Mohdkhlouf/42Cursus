#include "GradeTooLowException.hpp"

GradeTooLowException::GradeTooLowException(const char *msg) : message(msg) {};

const char *GradeTooLowException::what() const throw()
{
	return (message.c_str());
}