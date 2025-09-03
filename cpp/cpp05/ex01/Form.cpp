#include "Form.hpp"
Form::Form():name_("Unnamed"),is_signed(false),signItGrade_(150), executeItGrade_(150){}
Form::~Form(){}
Form::Form(const Form &obj):name_(obj.name_),is_signed(obj.is_signed), signItGrade_(obj.signItGrade_), executeItGrade_(obj.executeItGrade_){}

Form &Form::operator=(const Form& obj){
	if(this != &obj){
		is_signed = obj.is_signed;
	}
	return (*this);
}

std::string Form::getName() const{
	return name_;
}

int Form::getSignItGrade() const{
	return signItGrade_;
}

int Form::getExecuteItGrade() const{
	return executeItGrade_;
}

bool Form::getSignedStatus() const{
	return is_signed;
}


void Form::beSigned(Bureaucrat &obj){
	if(obj.getGrade() <= signItGrade_)
		is_signed = true;
	else
		throw Bureaucrat::GradeTooLowException("grade is too low");
}

std::ostream &operator<<(std::ostream &os, const Form &obj) {
	os << "Form name: "<<obj.getName() <<" Grade to sign: "<< obj.getSignItGrade() <<std::endl
		<< "Grade to execute: "<< obj.getExecuteItGrade()<<" is it signed:"<<(obj.getSignedStatus() ? "true" : "false")<<std::endl;
	return os;
	}

Form::Form(std::string name, int signitgrade, int executeitgrade): name_(name),is_signed(false),signItGrade_(signitgrade),executeItGrade_(executeitgrade){
	if (signItGrade_ < 1 || executeItGrade_<1)
		throw Bureaucrat::GradeTooHighException("Grade is too High");
	else if(signItGrade_ > 150 || executeItGrade_ > 150)
		throw Bureaucrat::GradeTooLowException("Grade is too Low");
}