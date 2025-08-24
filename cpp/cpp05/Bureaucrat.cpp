#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name_("unnamed"),grade_(150){}
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

uint8_t Bureaucrat::getGrade(){
    return (grade_);
}