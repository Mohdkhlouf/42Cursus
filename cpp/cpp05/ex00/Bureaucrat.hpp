#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <cstdint>
#include <iostream>

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
};
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif