
#include <iostream>
#include <fstream>
#include <cstring>
#include <cerrno>
#include <sstream>

std::string replace_words(std::string &new_str, std::string readStr, std::string s1, std::string s2)
{
	std::string temp;
	(void) s1;
	(void) s2;
	
	std::istringstream ss(readStr);
	while(ss >> temp)
		if(temp == s1)
			new_str.append(s2).append(" ");
		else if (temp != s1)
			new_str.append(temp).append(" ");
		else
			new_str.append(temp);
	return new_str;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "must be 4 arguments" << "\n";
		return (1);
	}
	std::string fileName = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string readStr;
	std::ifstream file(fileName);
	std::string new_str;
	if (!file)
	{
		std::cerr << "Error opening the file:" << std::strerror(errno) << "\n";
		return (errno);
	}
	try
	{
		while (std::getline(file, readStr))
			replace_words(new_str, readStr, s1, s2);
		std::cout<<new_str<<std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "error while reading the line: " << e.what() << "\n";
		return (1);
	}

	file.close(); // needs also try and catch if it fails;
	return (0);
}