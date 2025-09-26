#pragma once
#include <vector>
#include <iostream>
#include <limits>
class Span{

	private:
		unsigned int maxNumbers;
		std::vector<int> numbers;

	public:
		Span();
		Span(long long n);
		~Span();
		Span(const Span &obj);
		Span & operator=(const Span &obj);
		void addNumber(long N);
		template<typename T>
		void addManyNumbers(T start, T end){
			if( std::distance(start, end) < 0)
				throw std::runtime_error("Error in your iterators.");
			if (std::distance(start, end) > maxNumbers)
				throw std::runtime_error("Overflow iterators.");
			for(auto it = start; it != end; it++)
			{
				if(*it > std::numeric_limits<int>::max() || *it < std::numeric_limits<int>::min()){
					throw std::runtime_error("Overflow iterators.");
				}
			}
			numbers.insert(numbers.begin(), start, end);	
		}
		std::vector<int> &getNumbers();
		void printNumbers();
		int shortestSpan();
		int longestSpan();

};