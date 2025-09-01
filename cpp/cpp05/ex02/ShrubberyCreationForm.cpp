#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target):AForm(target,145,137){}
ShrubberyCreationForm::~ShrubberyCreationForm(){}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj){
	(void) obj;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj){
	if(this != &obj){}
	return (*this);
}