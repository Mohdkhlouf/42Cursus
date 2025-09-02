#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try{
		std::cout<<"######Case 1:######"<<std::endl;
		Bureaucrat ber(130);
		
		std::string teststr = "mohammad";
		ShrubberyCreationForm test(teststr);

		test.beSigned(ber);
		std::cout<<"is signed?:"<<test.getSignedStatus() <<std::endl;
		test.execute(ber);
		
	}catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}

	return (0);
}
