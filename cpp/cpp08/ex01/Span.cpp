#include "Span.hpp"
#include <iostream>

Span::Span(){}
Span::~Span(){}
Span::Span(const Span &obj){
	this->numbers = obj.numbers;
}
Span & Span::operator=(const Span &obj){
	if(this != &obj){
		this->numbers = obj.numbers;
	}
	return (*this);
}
void Span::addNumber(unsigned int N){
	auto result = numbers.insert(N);
	if (!result.second)
		throw std::runtime_error("Duplicated Value Not allowed");
}