#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target_(target) {}
RobotomyRequestForm::~RobotomyRequestForm() {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj)
{
	target_ = obj.target_;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	if (this != &obj)
	{
		target_ = obj.target_;
	}
	return (*this);
}


bool RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!getSignedStatus())
		throw Bureaucrat::FormNotSignedException("Cannot be assigned");
	else if (executor.getGrade() > getExecuteItGrade())
		throw Bureaucrat::GradeTooLowException("grade is not high enough");
	if(rand() % 2)
		std::cout << target_ << "has been robotomized successfully 50'%' of the time." << std::endl;
	else
		std::cout << target_ << "the robotomy failed." << std::endl;
	return (true);
}