#include "whatever.hpp"
#include <iostream>

int main()
{
	auto a = 2.5f;
	auto b = 1.0f;

	{
		std::cout << "### Case 1: swap function ###\n";
		std::cout << "Values before swapping:\n"
				  << "a:" << a << " b:" << b << "\n";
		swap(a, b);
		std::cout << "Values after swapping:\n"
				  << "a:" << a << " b:" << b << "\n";

		std::cout << "\n### Case 2: min function ###\n";
		std::cout << "The min is:" << min(a, b) << "\n";

		std::cout << "\n### Case 2: max function ###\n";
		std::cout << "The max is:" << max(a, b) << "\n";
	}

	{
		std::cout << "\n### Subject Test Cases ###\n";
		int a = 2;
		int b = 3;
		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
		std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;

		std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
		std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	}
	return (0);
}