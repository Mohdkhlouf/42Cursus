#pragma once
#include <set>
#include <utility>

class Span{

	private:
		std::set<int> numbers;

	public:
		Span();
		~Span();
		Span(const Span &obj);
		Span & operator=(const Span &obj);

		void addNumber(unsigned int N);
};