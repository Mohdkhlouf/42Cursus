#include "AForm.hpp"

AForm::AForm():name_("Unnamed"),is_signed(false),signItGrade_(150), executeItGrade_(150){}
AForm::~AForm(){}
AForm::AForm(const AForm &obj):name_(obj.name_),is_signed(obj.is_signed), signItGrade_(obj.signItGrade_), executeItGrade_(obj.executeItGrade_){}

AForm &AForm::operator=(const AForm& obj){
	if(this != &obj){
		is_signed = obj.is_signed;
	}
	return (*this);
}

std::string AForm::getName() const{
	return name_;
}

int AForm::getSignItGrade() const{
	return signItGrade_;
}

int AForm::getExecuteItGrade() const{
	return executeItGrade_;
}

bool AForm::getSignedStatus() const{
	return is_signed;
}


void AForm::beSigned(Bureaucrat &obj){
	if(obj.getGrade() <= signItGrade_)
		is_signed = true;
	else
		throw GradeTooLowException("grade is too low");
}

std::ostream &operator<<(std::ostream &os, const AForm &obj) {
	os << "AForm name: "<<obj.getName() <<" Grade to sign: "<< obj.getSignItGrade() <<std::endl
		<< "Grade to execute: "<< obj.getExecuteItGrade()<<" is it signed:"<<(obj.getSignedStatus() ? "true" : "false")<<std::endl;
	return os;
	}

AForm::AForm(std::string name, int signitgrade, int executeitgrade): name_(name),is_signed(false),signItGrade_(signitgrade),executeItGrade_(executeitgrade){
	if (signItGrade_ < 1 || executeItGrade_<1)
		throw GradeTooHighException("Grade is too High");
	else if(signItGrade_ > 150 || executeItGrade_ > 150)
		throw GradeTooLowException("Grade is too Low");
}