#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string &target):AForm("RobotomyRequestForm",72,45),target_(target){}
RobotomyRequestForm::~RobotomyRequestForm(){}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj){
	target_=obj.target_;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &obj){
	if(this != &obj){
		target_ = obj.target_;
	}
	return (*this);
}

bool RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	(void)	executor;
	return (false);
}