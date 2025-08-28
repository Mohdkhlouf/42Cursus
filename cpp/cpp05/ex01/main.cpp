#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

int main(void)
{

	try
	{
		Bureaucrat a(149);
		a.decrement();
		a.decrement();
		std::cout << a;
	}
	catch (const GradeTooLowException &e)
	{
		std::cout << "GradeTooLowException: " << e.what() << std::endl;
	}
	catch (const GradeTooHighException &e)
	{
		std::cout << "GradeTooHighException: " << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "General mistake: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat c("mohammad", 140);
		std::cout << c.getName() << std::endl;
		std::cout << c.getGrade() << std::endl;
		c.decrement();
		c.decrement();
		c.increment();
		c.increment();
		std::cout << c.getName() << std::endl;
		std::cout << c.getGrade() << std::endl;
		std::cout << c;
	}
	catch (const GradeTooLowException &e)
	{
		std::cout << "GradeTooLowException: " << e.what() << std::endl;
	}
	catch (const GradeTooHighException &e)
	{
		std::cout << "GradeTooHighException: " << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "General mistake: " << e.what() << std::endl;
	}

	return (0);
}
