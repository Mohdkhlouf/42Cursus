#pragma once
#include <vector>


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
			numbers.insert(numbers.begin(), start, end);
		}
		std::vector<int> &getNumbers();
		void printNumbers();
		int shortestSpan();
		int longestSpan();

};