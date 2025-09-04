#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try{
		std::cout<<"######Case 1:######"<<std::endl;
		Form a;
		std::cout<<a;
		Bureaucrat bob;
		bob.signForm(a);
		std::cout<<a;
		std::cout<<"######Case 2:######"<<std::endl;
		Form c("mezo", 140, 45);
		std::cout<<c;
		bob.signForm(c);
	}catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}



	return (0);
}
