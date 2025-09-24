#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <climits>
#include <numeric>


Span::Span() : maxNumbers(0) {}
Span::Span(long long n){
if (n <=UINT_MAX && n>= 0)
	maxNumbers = n;
else
	throw std::runtime_error("Out of range");
}
Span::~Span() {}
Span::Span(const Span &obj)
{
	this->numbers = obj.numbers;
}
Span &Span::operator=(const Span &obj)
{
	if (this != &obj)
	{
		this->numbers = obj.numbers;
	}
	return (*this);
}
void Span::addNumber(long n)
{
	if (numbers.size() >= maxNumbers)
		throw std::runtime_error("Numbers are full cannot add new one");
	if (n > INT_MAX || n< INT_MIN)
		throw std::runtime_error("Out of range");
	numbers.push_back(n);
	std::sort(numbers.begin(), numbers.end());
}

std::vector<int> &Span::getNumbers()
{
	return numbers;
}

void Span::printNumbers()
{
	for (auto it = numbers.begin(); it != numbers.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}

int Span::shortestSpan()
{
	if (numbers.empty() || numbers.size() <= 2)
		throw std::runtime_error("no elements enough for this");

	int maxElement = *std::max_element(numbers.begin(), numbers.end());
	int minElement = *std::min_element(numbers.begin(), numbers.end());
	int distance = maxElement - minElement;

	for (auto it = numbers.begin(); it != numbers.end(); it++)
	{
		if (std::abs(*it - *(it + 1)) < distance)
		{
			distance = std::abs(*it - *(it + 1));
		}
	}
	return (distance);
}

int Span::longestSpan()
{
	if (numbers.empty() || numbers.size() <= 2)
		throw std::runtime_error("no elements enough for this");

	int maxElement = *std::max_element(numbers.begin(), numbers.end());
	int minElement = *std::min_element(numbers.begin(), numbers.end());
	int distance = maxElement - minElement;
	return (distance);
}
