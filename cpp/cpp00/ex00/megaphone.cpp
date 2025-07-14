#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		for(int i = 1; argv[i]; i++)
		{
			for(int j=0;argv[i][j]; j++)
				std::cout << (char)std::toupper(argv[i][j]);
		}
		//we have to end every output wth newline as said in the subject.
		std::cout<<std::endl;
	return (0);
}