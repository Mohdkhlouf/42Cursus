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
	if (getSignedStatus()){
		if (executor.getGrade() <= getExecuteItGrade()){
			std::cout<<target_<<"has been pardoned by Zaphod Beeblebrox."<<std::endl;
			return (true);
		}
		else{
			std::cout<<target_<<" has NOT been pardoned."<<std::endl;
		}
	}
	return (false);
}