#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string &target):AForm("PresidentialPardonForm",25,5),target_(target){}
PresidentialPardonForm::~PresidentialPardonForm(){}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj){
	(void) obj;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &obj){
	if(this != &obj){
		target_ = obj.target_;
	};
	return (*this);
}

bool PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	(void)	executor;
	return (false);
}