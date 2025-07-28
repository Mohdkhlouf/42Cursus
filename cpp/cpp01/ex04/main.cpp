
#include <cerrno>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>

std::string replace_words(std::string readStr, std::string s1, std::string s2)
{
	std::string temp;
	std::istringstream ss(readStr);
	std::string new_str;
	std::size_t found;
	found = readStr.find(s1);
	while (found != std::string::npos)
	{
		new_str.append(readStr.substr(0, found));
		new_str.append(s2);
		readStr.erase(0, found+ s1.length());
		found = readStr.find(s1);
	}
	new_str.append(readStr);
	return (new_str);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "must be 4 arguments"
					<< "\n";
		return (1);
	}
	std::string inFile = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string outFile = inFile + ".replace";
	std::string readStr;
	std::ifstream file(inFile);
	std::ofstream ofile(outFile);
	std::string new_str;
	if (!file || !ofile)
	{
		std::cout << "Error opening the file:" << std::strerror(errno) << "\n";
		return (errno);
	}
	while (std::getline(file, readStr))
	{
		if (readStr.find(s1) != std::string::npos)
		{
			new_str.append(replace_words(readStr, s1, s2));
			new_str.append("\n");
		}
		else
		{
			new_str.append(readStr);
			new_str.append("\n");
		}
	}
	if (file.eof())
		if (new_str.back() == '\n')
			new_str.pop_back();
	if (file.bad())
	{
		std::cout << "Error while reading line: " << strerror(errno) << "\n";
		return (errno);
	}
	std::cout << new_str << std::endl;
	file.close(); // needs also try and catch if it fails;
	ofile.close();
	return (0);
}
