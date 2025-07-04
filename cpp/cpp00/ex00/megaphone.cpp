#include <iostream>

int main(int argc, char **argv)
{
	int arg_counter;

	arg_counter = argc - 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		for(int i = 1; argv[i]; i++)
		{
			for(int j=0;argv[i][j]; j++)
				std::cout << (char)toupper(argv[i][j]);
			if(arg_counter > 1)
			{
				arg_counter--;
				std::cout <<" ";
			}
		}
	return (0);
}
