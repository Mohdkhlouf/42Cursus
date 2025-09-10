
#include "ScalarConverter.hpp"

void print_message(const std::string &str)
{
	std::cout << str << std::endl;
}

bool isChar(const std::string &str)
{
	if (str.length() > 1)
	{
		return (false);
	}
	if (str[0] < 33 || str[0] > 126)
		print_message("not displayable character");
	else
	{
		if (!(str[0] >= 48 && str[0] <= 57))
			return (true);
	}
	return (false);
}

bool hasDecimal(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '.')
		{
			return (true);
		}
	}
	return (false);
}

bool hasOneDecimal(const std::string &str)
{
	int floatCounter = 0;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '.')
			floatCounter++;
	}
	if (floatCounter != 1)
		return (false);
	return (true);
}

bool isInt(const std::string &str)
{
	bool is_digit = true;
	size_t i = 0;
	if (hasDecimal(str))
		return (false);
	if (str[0] == '+' || str[0] == '-')
		i = 1;
	for (; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			is_digit = false;
	}
	if (is_digit)
	{
		if (stod(str) > INT_MAX || stod(str) < INT_MIN)
			return (false);
		return (true);
	}

	return (false);
}

bool isFloat(const std::string &str)
{
	bool valid = true;
	size_t i = 0;
	if (str == "nanf" || str == "-inff" || str == "+inff")
		return (true);
	if (hasDecimal(str))
	{
		if (!hasOneDecimal(str))
			return (false);
	}
	if (str[0] == '+' || str[0] == '-')
		i = 1;
	if (str[str.length() - 1] == 'f')
	{
		for (; i < str.length(); i++)
		{
			if (!(isdigit(str[i]) || str[i] == '.'))
				valid = false;
		}
		if (!valid)
			return (true);
	}
	else
		return (false);
	return (false);
}

bool isDouble(const std::string &str)
{

	bool valid = true;
	size_t i = 0;

	if (str == "nan" || str == "-inf" || str == "+inf")
		return (true);
	if (hasDecimal(str))
	{
		if (!hasOneDecimal(str))
			return (false);
	}
	if (str[0] == '+' || str[0] == '-')
		i = 1;
	for (; i < str.length(); i++)
	{
		if (!(isdigit(str[i]) || str[i] == '.'))
			valid = false;
	}
	if (valid)
		return (true);
	return (false);
}
t_types checkType(const std::string &str)
{
	if (isChar(str))
		return (CHAR);
	else if (isInt(str))
		return (INT);
	else if (isFloat(str))
		return (FLOAT);
	else if (isDouble(str))
		return (DOUBLE);
	return (INVALID);
}

void printCasted(char ch)
{
	std::cout << "char: " << ch << std::endl;
	std::cout << "int: " << static_cast<int>(ch) << std::endl;
	std::cout << "float: " << std::fixed << static_cast<float>(ch) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(ch) << ".0" << std::endl;
}

void printCasted(int n)
{
	if (n < 33 || n > 126)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(n) << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
}

void printCasted(float n, bool has_decimal)
{
	if ((n < 33 && n> static_cast<float>(INT_MIN))|| (n > 126 && n < static_cast<float>(INT_MAX)))
		std::cout << "char: " << "Non displayable" << std::endl;
	else if(n !=n || n == -INFINITY || n == +INFINITY)
		std::cout << "char: " << "Impossible" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(n) << std::endl;

	if ((n < static_cast<float>(INT_MIN) && n > -INFINITY) || (n > static_cast<float>(INT_MAX) && n < +INFINITY))
		std::cout << "int: " << "Overflow" << std::endl;
	else if(n !=n || n == -INFINITY || n == +INFINITY)
		std::cout << "int: " << "Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(n) << std::endl;

	if (!has_decimal)
	{
		std::cout << "float: " << n << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(n) <<std::endl;
	}
	else
	{
		std::cout << "float: " << n << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
	}
}

void printCasted(double n, bool has_decimal)
{
	if ((n < 33 && n> static_cast<float>(INT_MIN))|| (n > 126 && n < static_cast<float>(INT_MAX)))
		std::cout << "char: " << "Non displayable" << std::endl;
	else if (n != n || n == -INFINITY || n == +INFINITY)
		std::cout << "char: " << "Impossible" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(n) << std::endl;

	if ((n < static_cast<float>(INT_MIN) && n > -INFINITY) || (n > static_cast<float>(INT_MAX) && n < +INFINITY))
		std::cout << "int: " << "Overflow" << std::endl;
	else if (n != n || n == -INFINITY || n == +INFINITY)
		std::cout << "int: " << "Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(n) << std::endl;
	if (!has_decimal){
		std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(n) << std::endl;
	}
	else{
		std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
	}

}
void ScalarConverter::convert(const std::string &str)
{
	// here i have to test if the string is empty or not
	if (str.empty())
		throw std::invalid_argument("empty value for the needed string");

	switch (checkType(str))
	{
	case 0:
	{
		printCasted(str[0]);
		break;
	}
	case 1:
	{
		printCasted(std::stoi(str));
		break;
	}
	case 2:
	{
		printCasted(std::stof(str), hasDecimal(str));
		break;
	}
	case 3:
	{
		printCasted(std::stod(str), hasDecimal(str));
		break;
	}
	case 4:
	{
		std::cout << "Invalid Type detected" << std::endl;
		break;
	}
	}
}