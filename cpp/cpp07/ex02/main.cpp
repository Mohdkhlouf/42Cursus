#include "Array.hpp"
#include "Array.tpp"

#include <iostream>

int main()
{

	try
	{
		std::cout<<"##### Test Case 1:\n";

		Array<int> x(5);
		std::cout << x.size() << std::endl;
		x[0] = 5;
		x[1] = 10;
		x[2] = 15;

		std::cout << x[0] << std::endl;
		std::cout << x[1] << std::endl;
		std::cout << x[2] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	{
		try
		{
			std::cout<<"\n##### Test Case 2:\n";
			Array<int> x(5);
			std::cout << x.size() << std::endl;
			x[0] = 5;
			x[1] = 10;
			x[2] = 15;
			x[10] = 100;

			std::cout << x[0] << std::endl;
			std::cout << x[1] << std::endl;
			std::cout << x[2] << std::endl;
			std::cout << x[10] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	return (0);
}