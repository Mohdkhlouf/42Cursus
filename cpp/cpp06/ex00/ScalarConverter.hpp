#pragma once
#include <iostream>

class ScalarConverter{
	public:
	ScalarConverter() = delete;
	~ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter &obj) = delete;
	ScalarConverter &operator=(const ScalarConverter &obj) = delete;
	static void convert(std::string &str);
};