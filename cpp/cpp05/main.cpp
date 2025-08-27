#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

int main(void){

	// Bureaucrat b;
	// std::cout<<b.getName()<<std::endl;
	// std::cout<<b.getGrade()<<std::endl;

	try{
		Bureaucrat c("mohammad", 900);
		std::cout<<c.getName()<<std::endl;
		std::cout<<c.getGrade()<<std::endl;
	}catch(GradeTooLowException &e){
		std::cout<<"GradeTooLowException: "<< e.what()<<std::endl;
	}catch(GradeTooHighException &e){
		std::cout<<"GradeTooHighException: "<< e.what()<<std::endl;
	}catch (std::exception &e){
		std::cout<<"General mistake: "<< e.what()<<std::endl;
	}


	return (0);
}


