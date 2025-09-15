#pragma once
#include <iostream>
#include <climits>
#include <cmath>

typedef enum s_types
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
} t_types;

class ScalarConverter
{
private:
	ScalarConverter() = delete;
	~ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter &obj) = delete;
	ScalarConverter &operator=(const ScalarConverter &obj) = delete;

public:
	static void convert(const std::string &str);
};