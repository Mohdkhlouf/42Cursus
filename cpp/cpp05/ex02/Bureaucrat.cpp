#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

Bureaucrat::Bureaucrat() : name_("unnamed"), grade_(150) {}

Bureaucrat::Bureaucrat(const int grade) : name_("unnamed")
{
    if (grade < 1)
        throw GradeTooLowException("grade must be from 150  - 1");
    else if (grade > 150)
        throw GradeTooHighException("grade must be from 150  - 1");
    else
    {
        grade_ = grade;
    }
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : name_(name)
{
    if (grade < 1)
        throw GradeTooLowException("grade must be from 150  - 1");
    else if (grade > 150)
        throw GradeTooHighException("grade must be from 150  - 1");
    else
    {
        grade_ = grade;
    }
}
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name_(obj.name_), grade_(obj.grade_) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    if (this != &obj)
    {
        grade_ = obj.grade_;
    }
    return (*this);
}

std::string Bureaucrat::getName() const
{
    return (name_);
}

int Bureaucrat::getGrade() const
{
    return (grade_);
}

void Bureaucrat::increment()
{
    if (grade_ - 1 < 1)
    {
        throw GradeTooLowException("grade cannot be higher that 1");
    }
    else
    {
        grade_--;
    }
}

void Bureaucrat::decrement()
{
    if (grade_ + 1 > 150)
    {
        throw GradeTooLowException("grade cannot be smaller that 150");
    }
    else
    {
        grade_++;
    }
}

void Bureaucrat::signForm(AForm &form){
    try{
        form.beSigned(*this);
        std::cout<<name_<<" signed "<<form.getName()<<"."<<std::endl;
    }catch(const GradeTooLowException &e){
        std::cout<<name_<<"  couldn’t sign "<<form.getName()<<" because"<<e.what()<<"."<<std::endl;
    }
    catch(const GradeTooHighException &e){
        std::cout<<name_<<"  couldn’t sign "<<form.getName()<<" because"<<e.what()<<"."<<std::endl;
    }
}   

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
    os << obj.getName()
       << ", bureaucrat grade "
       << obj.getGrade() << ". \n";
    return os;
}


void Bureaucrat::executeForm(AForm const & form){
    if(form.execute(*this) ){
        std::cout<<name_<<" executed "<<form.getName()<<std::endl;
    }
    else{
        std::cout<<"NOT execute "<<form.getName()<<std::endl;
    }
}