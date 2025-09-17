#include "iter.hpp"
#include <array>
#include <iostream>

int main()
{
	{
		std::cout<<"Case 00\n";
		int tab[] = {0,1,2,3,4};
		Awesome tab2[5];

		iter(tab, 5, print);
		iter(tab2, 5, print);

		iter(tab, 5, increment<int>);
		iter(tab, 5, print);
		
	}

	{
		std::cout<<"\nCase 01\n";
		int tab[] = {'a','b','c','d','e'};
		iter(tab, 5, print);	
		iter(tab, 5, increment<int>);
		iter(tab, 5, print);		
	}


	{
		std::cout<<"\nCase 1\n";
		int arr[] = {1, 2, 3};
		iter(arr, sizeof(arr) / sizeof(arr[0]), print);
	}
	{
		std::cout<<"\nCase 2\n";
		float arr[] = {1.1f, 2.2f, 3.3f};
		iter(arr, sizeof(arr) / sizeof(arr[0]), print);
	}
	{
		std::cout<<"\nCase 3\n";
		double arr[] = {1.9, 2.5, 3.8};
		iter(arr, sizeof(arr) / sizeof(arr[0]), print);
	}
	{
		std::cout<<"\nCase 4\n";
		char arr[] = {'a', 'b', 'c'};
		iter(arr, sizeof(arr) / sizeof(arr[0]), print);
	}
	return (0);
}