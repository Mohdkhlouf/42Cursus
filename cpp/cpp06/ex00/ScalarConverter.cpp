
#include "ScalarConverter.hpp"

void print_message(const std::string &str){
	std::cout<<str<<std::endl;
}


bool isChar(const std::string &str){
	if(str.length()>1){
		return (false);
	}
	if (str[0] < 33 || str[0]> 126)
		print_message("not displayable character");
	else{
		if(!(str[0] >=48 && str[0] <= 57))
			return (true);
	}
	return (false);
}
bool hasDecimal(const std::string &str){
	for(size_t i = 0; i <str.length(); i++){
		if (str[i] == '.'){
			return (true);}
	}
	return (false);
}

bool hasOneDecimal(const std::string &str){
	int  floatCounter = 0;

	for(size_t i = 0; i <str.length(); i++){
		if (str[i] == '.')
			floatCounter++;
	}
	if(floatCounter != 1)
		return (false);
	return (true);
}

bool isInt(const std::string &str){
	bool is_digit = true;
	size_t i = 0;
	if(hasDecimal(str))
		return (false);
	if(str[0] == '+' || str[0] == '-')
		i = 1;
	for(; i <str.length(); i++){
		if (!isdigit(str[i]))
			is_digit = false;
	}
	if(is_digit)
		return (true);
	return (false);
}


bool isFloat(const std::string &str){
	bool is_digit = true;
	size_t i = 0;
	if(hasDecimal(str)){
		if(!hasOneDecimal(str))
			return (false);
	}
	if(str[0] == '+' || str[0] == '-')
		i = 1;
	for(; i <str.length(); i++){
		if (!(isdigit(str[i]) || str[i] == '.'))
			is_digit = false;
	}
	std::cout<<"DEBUG: "<<str[str.length() - 1]<<std::endl;
	if(!is_digit && str[str.length() - 1] == 'f')
		return (true);

	return (false);
}

bool isDouble(const std::string &str){

(void) str;
	std::cout<<"I am in Double"<<std::endl;
	return (false);
}
t_types checkType(const std::string &str){
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
void ScalarConverter::convert(const std::string &str){

	// here i have to test if the string is empty or not
	if (str.empty())
		throw std::invalid_argument("empty value for the needed string");

	switch (checkType(str)){
		case 0:{
			std::cout<<"Char Type detected"<<std::endl;
			break;
		}
		case 1:{
			std::cout<<"Int Type detected"<<std::endl;
			break;
		}
		case 2:{
			std::cout<<"Float Type detected"<<std::endl;
			break;
		}
		case 3:{
			std::cout<<"Double Type detected"<<std::endl;
			break;
		}
		case 4:{
			std::cout<<"Invalid Type detected"<<std::endl;
			break;
		}

	}
	
}