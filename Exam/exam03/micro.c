#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void ft_execute()
{
	argv[i] = NULL;
	dup2(tmp_fd,STDIN_FILENO);
	close (tmp_fd);
	execve(argv[0], argv, env);
	ft_print_error("cannoe exectute", argv[0]);
	exit(1);
}
int main( int argc, char **argv, char **env)
{
	int i;
	(void) argc;

	i = 0;
	
	while(argv[i] && argv[i+1])
	{
		argv = &argv[i + 1];
		int tmp_fd;

		i = 0;
		tmp_fd = dup(STDIN_FILENO);
		while( argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if(strcmp(argv[0],"cd") == 0)
		{
			if( i != 2)
				ft_print_error("",NULL);
			else if(chdir(argv[1]) != 0)
				ft_print_error("",argv[1]);
		}

		else if(i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
		{
			if (fork() == 0)
				ft_execute();
			else
			{
				close(tmp_fd);
				while(waitpid(-1, NULL, WUNTRACED) != -1)
					;
				tmp_fd = dup(STDIN_FILENO);
			}

		}
		else if(i != 0 && strcmp(argv[i], "|") == 0)
		{
			pipe(fd);
			if(fork() == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				ft_execute();
			}
			else
			{
				close(fd[1]);
				close(tmp_fd);
				tmp_fd = fd[0];
			}
		}
	}

	close(tmp_fd);
	return(0);
}