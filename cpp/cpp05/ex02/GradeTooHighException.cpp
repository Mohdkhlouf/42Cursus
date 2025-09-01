#include "GradeTooHighException.hpp"

GradeTooHighException::GradeTooHighException(const char *message) : msg(message) {};
const char *GradeTooHighException::what() const throw()
{
	return (msg.c_str());
}