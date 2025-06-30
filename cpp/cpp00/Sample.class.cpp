#include <iostream>
#include "Sample.class.hpp"


Sample::Sample(void){
	std::cout << "Constructor started" << std::endl;
	this->x = 1050;
	return;
};

Sample::~Sample(void) {
	std::cout << "Desctructer called" << std::endl;
	return;
};


void Sample::print(void)
{
	std::cout << "Hello i am the function from the class" << std:: endl;

	
	return;
};
