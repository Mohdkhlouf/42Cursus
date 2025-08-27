#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <cstdint>
#include <iostream>

class  Bureaucrat{
    private:
        const std::string name_;
        int grade_;  // ranged from 0 to 255

    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, const int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat &operator=(const Bureaucrat &obj);

        std::string getName();
        int getGrade();
        
};

#endif