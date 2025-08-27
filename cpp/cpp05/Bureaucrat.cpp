#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"

Bureaucrat::Bureaucrat():name_("unnamed"),grade_(150){}
Bureaucrat::Bureaucrat(const std::string &name, const int grade):name_(name){
    if(grade < 1)
        throw GradeTooHighException("grade must be from 150  - 1");
    else if( grade > 150)
        throw GradeTooHighException("grade must be from 150  - 1");
    else{
        grade_ = grade;
    }
}
Bureaucrat::~Bureaucrat(){}
Bureaucrat::Bureaucrat(const Bureaucrat &obj):name_(obj.name_), grade_(obj.grade_){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &obj){
    if (this != &obj){
        grade_ = obj.grade_;
    }
    return (*this);
}

std::string Bureaucrat::getName(){
    return (name_);
}

int Bureaucrat::getGrade(){
    return (grade_);
}