/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:21:02 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/06/30 17:08:20 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

#ifdef TEST_SH
# define TEST		1
#else
# define TEST		0
#endif

void ft_print(char *str1, char *str2)
{
	while(*str1)
		write(2, str1++, 1);
	if (str2)
		while(*str2)
			write(2,str2++,1);
	write(2, "\n", 1);
}

void ft_execute(char **argv, int i, int tmp_fd, char **env)
{
	argv[i] = NULL;
	dup2(tmp_fd, STDIN_FILENO);
	close(tmp_fd);
	execve(argv[0], argv, env);
	ft_print("Error: cannot execute ", argv[0]);
	exit(1);
}

int main(int argc, char **argv, char **env)
{
	int i;
	int tmp_fd;
	int fd[2];
	(void) argc;
	
	i = 0;
	tmp_fd = dup(STDIN_FILENO);
	while (argv[i] && argv[i + 1])
		{
			argv = &argv [i+1];
			i = 0;
			while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i],"|"))
				i++;
			if (strcmp(argv[0], "cd") == 0 )
				{
					if (i != 2)
						ft_print("Error: cd: bad arguments", NULL);
					else if (chdir(argv[1]) == -1)
						ft_print("Error: cd: cannot change directory to ", argv[1]);
				}
			else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
			{
				if (fork ())
					ft_execute(argv, i, tmp_fd, env);
				else
				{
					close(tmp_fd);
					while (waitpid(-1, NULL, WUNTRACED) != -1)
						;
					tmp_fd = dup(STDIN_FILENO);
				}
			}
			else if (i != 0 && (strcmp(argv[i], "|") ==0) )
			{
				pipe(fd);
				if (fork() == 0)
				{
					dup2(fd[1], STDOUT_FILENO);
					close(fd[0]);
					close(fd[1]);
					ft_execute(argv, i, tmp_fd, env);
				}
				else
				{
					close (fd[1]);
					close (tmp_fd);
					tmp_fd = fd[0];
				}
			}
				
		}

	close (tmp_fd);

	if (TEST)
		while (1);
	return (0);
}