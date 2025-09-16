#include "iter.hpp"
#include <array>
#include <iostream>

int main()
{
	{
		std::cout<<"Case 00\n";
		int tab[] = {0,1,2,3,4};
		Awesome tab2[5];

		Iter(tab, 5, function);
		Iter(tab2, 5, function);
		Iter(tab, 5, increment);
		Iter(tab, 5, function);
		
	}


	{
		std::cout<<"\nCase 1\n";
		int arr[] = {1, 2, 3};
		Iter(arr, sizeof(arr) / sizeof(arr[0]), function);
	}
	{
		std::cout<<"\nCase 2\n";
		float arr[] = {1.1f, 2.2f, 3.3f};
		Iter(arr, sizeof(arr) / sizeof(arr[0]), function);
	}
	{
		std::cout<<"\nCase 3\n";
		double arr[] = {1.9, 2.5, 3.8};
		Iter(arr, sizeof(arr) / sizeof(arr[0]), function);
	}
	{
		std::cout<<"\nCase 4\n";
		char arr[] = {'a', 'b', 'c'};
		Iter(arr, sizeof(arr) / sizeof(arr[0]), function);
	}
	return (0);
}