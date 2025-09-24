#include "Span.hpp"
#include <iostream>
#include <random>

int main(){

try{
	Span first_span(100);
	first_span.addNumber(10);
	first_span.addNumber(8);
	first_span.addNumber(6);
	first_span.addNumber(4);
	first_span.addNumber(2);
	first_span.printNumbers();
	std::cout<<"Shortest Span is:"<<first_span.shortestSpan()<<std::endl;
	std::cout<<"Longest Span is:"<<first_span.longestSpan()<<std::endl;
}catch (std::exception &e){
	std::cout<<"Error: "<<e.what()<<std::endl;
}


{
	Span test(1000);
	std::vector<int> range;
	range.reserve(1000);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(-5000, 5000);

	for(int i = 0; i < 1000; i++)
		range.push_back(dist(gen));

	test.addManyNumbers(range.begin(), range.end());
	std::cout<<"Shortest Span is:"<<test.shortestSpan()<<std::endl;
	std::cout<<"Longest Span is:"<<test.longestSpan()<<std::endl;
}
	return (0);
}