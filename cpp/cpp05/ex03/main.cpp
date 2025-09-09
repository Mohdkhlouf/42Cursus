#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	srand(time(NULL)); // change the seed to be taken from time every time it runs.
	try
	{
		{
			std::cout << "************Case1:\n";
			Intern test;
			AForm *rrf = nullptr;
			rrf = test.makeForm("ShrubberyCreationForm", "Bender");
			std::cout << "Form info " << rrf->getName() << "  " << rrf->getSignItGrade() << std::endl;
			delete rrf;
		}

		{
			std::cout << "************Case2:\n";
			Bureaucrat ber("test", 130);
			Intern test;
			AForm *rrf = nullptr;
			rrf = test.makeForm("ShrubberyCreationForm", "Bender");
			ber.signForm(*rrf);
			rrf->execute(ber);
			std::cout << "Form info " << rrf->getName() << "  " << rrf->getSignItGrade() << std::endl;
			delete rrf;
		}

		{
			std::cout << "************Case3:\n";
			Bureaucrat ber("test", 30);
			Intern test;
			AForm *rrf = nullptr;
			rrf = test.makeForm("RobotomyRequestForm", "NiceBender");
			ber.signForm(*rrf);
			rrf->execute(ber);
			std::cout << "Form info " << rrf->getName() << "  " << rrf->getSignItGrade() << std::endl;
			delete rrf;
		}

		{
			std::cout << "************Case4:\n";
			Intern someRandomIntern;
			AForm *rrf = nullptr;
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			std::cout << "Form info " << rrf->getName() << "  " << rrf->getSignItGrade() << std::endl;
			delete rrf;
		}
	}

	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::FormNotSignedException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
