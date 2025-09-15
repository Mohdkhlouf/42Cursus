#include "iter.hpp"
#include <array>
#include <iostream>

int main()
{
	{
		std::cout<<"Case 1\n";
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