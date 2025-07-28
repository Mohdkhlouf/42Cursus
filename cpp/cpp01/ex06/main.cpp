#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Bad arguments" << "\n";
		return (1);
	}
	Harl test;
	
	test.filtered(argv[1]);

	return (0);
}