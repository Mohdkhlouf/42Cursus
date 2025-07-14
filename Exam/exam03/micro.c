#include <unistd.h>

void ft_print_err(char *str, char *str2)
{
	while(str)
		write(2, str++, 1);
	if (str2)
		while(str2)
			write(2,str2++, 1);
	write(1, "\n", 2);
}

int main(int argc, char **argv, char **env)
{
	int i;
	int tmp_fd;

	i = 0;
	tmp_fd= dup(STDIN_FILENO);
	while(argv[i] && argv[i+1])
	{
		argv = argv[i+1];
		i = 0;

		while(argv[i] && strcmp(argv[i],";") && strcmp(argv[i], "|"))
			i++;
		if(strcmp(argv[0], "cd") ==0)
		{
			if (i != 2)
				ft_print_err("error: cd: bad arguments", NULL);
			else if(chdir(argv[1] != 0))
				ft_print_err("error: cd: cannot change directory to", argv[1]);
		}
		else if(i!= 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0) )
		{
			if (fork() == 0)
				ft_execute(i, argv,tmp_fd, env );
		}

		else if(i!=0 && strcmp(argv[i], "|") == 0)
		{

		}





	}


	return(0);
}