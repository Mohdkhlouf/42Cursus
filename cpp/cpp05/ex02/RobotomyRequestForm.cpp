#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string &target):AForm(target,72,45){}
RobotomyRequestForm::~RobotomyRequestForm(){}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj){
	(void) obj;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &obj){
	if(this != &obj){}
	return (*this);
} 