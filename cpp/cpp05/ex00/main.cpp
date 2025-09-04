#include "Bureaucrat.hpp"

int main(void)
{

	try
	{
		Bureaucrat a(149);
		a.decrement();
		a.decrement();
		std::cout << a;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "GradeTooLowException: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
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
		std::cout << c.getName() << std::endl;
		std::cout << c.getGrade() << std::endl;
		c.increment();
		c.increment();
		std::cout << c.getName() << std::endl;
		std::cout << c.getGrade() << std::endl;
		std::cout << c;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "GradeTooLowException: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "GradeTooHighException: " << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "General mistake: " << e.what() << std::endl;
	}

	return (0);
}
