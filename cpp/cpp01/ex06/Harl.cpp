
#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "DEBUG:\ni am debugging the software and may you be useful as me!" << "\n\n";
}
void Harl::info(void)
{
	std::cout << "INFO:\ni am debugging the software and may you be useful as me!" << "\n\n";
}
void Harl::warning(void)
{
	std::cout << "WARNING:\ni warn you from some possible bugs." << "\n\n";
}
void Harl::error(void)
{
	std::cout << "ERROR:\ni am s sorry to declare that you have many errors!" << "\n";
}

void Harl::complain(std::string level)
{
	std::string level_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcs_ptrs[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++)
	{
		if (level_arr[i] == level)
			return (this->*funcs_ptrs[i])();
	}
	std::cout << "only these are correct {DEBUG, INFO, WARNING, ERROR}" << "\n";
}

void Harl::filtered(std::string level)
{
	int int_level = -1;
	std::string level_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcs_ptrs[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++)
	{
		if (level_arr[i] == level)
			int_level = i;
	}

	switch (int_level)
	{
		case 0:
			(this->*funcs_ptrs[0])();
			[[fallthrough]];

		case 1:
			(this->*funcs_ptrs[1])();
			[[fallthrough]];

		case 2:
			(this->*funcs_ptrs[2])();
			[[fallthrough]];

		case 3:
			(this->*funcs_ptrs[3])();
			[[fallthrough]];

		default:
			std::cout<<"only these are correct {DEBUG, INFO, WARNING, ERROR}"<<"\n";
	}
}