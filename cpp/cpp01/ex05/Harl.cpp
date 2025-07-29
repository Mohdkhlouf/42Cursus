
#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "DEBUG: i am debugging the software and may you be useful as me!"<<std::endl;
}
void Harl::info(void)
{
	std::cout << "INFO: it is an important to check this info."<<std::endl;
}
void Harl::warning(void)
{
	std::cout << "WARNING: i warn you from some possible bugs."<<std::endl;
}
void Harl::error(void)
{
	std::cout << "ERROR: i am s sorry to declare that you have many errors!"<<std::endl;
}

void Harl::complain(std::string level)
{
	std::string level_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void(Harl::*funcs_ptrs[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for(int i = 0; i < 4; i++)
	{
		if(level_arr[i] == level)
			return (this->*funcs_ptrs[i])();
	}
	std::cout<<"only these are correct {DEBUG, INFO, WARNING, ERROR}"<<"\n";
}