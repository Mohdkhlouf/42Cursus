#include "Intern.hpp"
#include <iostream>

AForm *Intern::makeForm(std::string name, std::string target)
{

	std::string namesArr[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	typedef AForm* (*myFunc)(const std::string &);

	myFunc myFuncs[]={
		[](const std::string &target) -> AForm *{try{return new ShrubberyCreationForm(target);}catch(std::exception &e){std::cout<<"Error allocating memory:"<<e.what()<<std::endl;return nullptr;}},
		[](const std::string &target) -> AForm *{try{return new RobotomyRequestForm(target);}catch(std::exception &e){std::cout<<"Error allocating memory:"<<e.what()<<std::endl;return nullptr;}},
		[](const std::string &target) -> AForm *{try{return new PresidentialPardonForm(target);}catch(std::exception &e){std::cout<<"Error allocating memory:"<<e.what()<<std::endl;return nullptr;}}
	};

				
	AForm *resultptr = nullptr;
	int index = -1;
	for (auto &value : namesArr)
	{
		index++;
		if (value == name)
		{

			resultptr = myFuncs[index](target);
			std::cout<<"Intern creates "<< name<<std::endl;
			return (resultptr);
		}
	}
	throw std::out_of_range ("invalid parameter, cannot find the class name.");
	return (resultptr);
}