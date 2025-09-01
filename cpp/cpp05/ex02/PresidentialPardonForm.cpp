#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string &target):AForm(target,25,5){}
PresidentialPardonForm::~PresidentialPardonForm(){}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj){
	(void) obj;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &obj){
	if(this != &obj){}
	return (*this);
}