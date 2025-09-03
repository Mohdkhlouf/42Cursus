#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	srand(time(NULL)); // change the seed to be taken from time every time it runs.
	try
	{
		{
		std::cout << "######Case 1:######" << std::endl;
		Bureaucrat ber("BER",1);
		std::string teststr = "mohammad";
		ShrubberyCreationForm test(teststr);
		test.beSigned(ber);
		ber.executeForm(test);
		}

		{
		std::cout << "######Case 2:######" << std::endl;
		Bureaucrat ber("BER2",44);
		std::string teststr = "Khaled";
		RobotomyRequestForm test2(teststr);
		test2.beSigned(ber);
		ber.executeForm(test2);
		}

		{
		std::cout << "######Case 3:######" << std::endl;
		Bureaucrat ber("BER3",4);
		std::string teststr = "Ali";
		PresidentialPardonForm test3(teststr);
		test3.beSigned(ber);
		ber.executeForm(test3);
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
