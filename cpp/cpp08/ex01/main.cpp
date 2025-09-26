#include "Span.hpp"
#include <iostream>
#include <random>

int main()
{

	try
	{
		Span first_span(100);
		first_span.addNumber(10);
		first_span.addNumber(8);
		first_span.addNumber(6);
		first_span.addNumber(4);
		first_span.addNumber(2);
		first_span.printNumbers();
		std::cout << "Shortest Span is:" << first_span.shortestSpan() << std::endl;
		std::cout << "Longest Span is:" << first_span.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	{
		try
		{
			std::cout << "\nAdd many numbers test case" << std::endl;
			Span test(1000);
			std::vector<int> range;
			range.reserve(1000);
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<long long> dist(-5000, 5465465415154);
			for (int i = 0; i < 1000; i++)
				range.push_back(dist(gen));
			test.addManyNumbers(range.begin(), range.end());
			std::cout << "Shortest Span is:" << test.shortestSpan() << std::endl;
			std::cout << "Longest Span is:" << test.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	{
		try
		{
			std::cout << "\nSubject test case" << std::endl;
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	return (0);
}