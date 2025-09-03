#include "Intern.hpp"
#include <iostream>



ShrubberyCreationForm &createShrubberyForm(const std::string target) const{

	return (ShrubberyCreationForm(target));
}



AForm * Intern::makeForm(std::string name, std::string target){

	std::string namesArr[3] = {"ShrubberyCreationForm","RobotomyRequestForm","PresidentialPardonForm"};
	AForm *formArr[3] ={&ShrubberyCreationForm, &RobotomyRequestForm , &PresidentialPardonForm};


	for (int i = 0; i < 3; i++){
		if(namesArr[i] == name)

	}
}