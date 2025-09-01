#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
class Form;
#include <string>
#include <cstdint>
#include <iostream>
#include "Form.hpp"


class Bureaucrat
{
private:
    const std::string name_;
    int grade_; // ranged from 0 to 255

public:
    Bureaucrat();
    Bureaucrat(const std::string &name, const int grade);
    Bureaucrat(const int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &obj);
    Bureaucrat &operator=(const Bureaucrat &obj);

    void increment();
    void decrement();
    std::string getName() const;
    int getGrade() const;
    void signForm(Form &form);
};
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif