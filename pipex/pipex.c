/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/01 01:00:35 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//--end of check commands functions
void	child_process(t_pipex *pipex, int *pipefd)
{
	int	i;

	close(pipefd[1]);
	printf("Hi!, child process %s \n", pipex->infile);
	i = 0;
	while (pipex->cmd1[i])
		i++;
	execve(pipex->path1, pipex->cmd1, NULL);
	printf("counter is: %d\n", i);
	exit(EXIT_SUCCESS);
}

void	parent_process(t_pipex *pipex, int *pipefd)
{
	close(pipefd[0]);
	wait(NULL);
	printf("Hi!, Parent process %s \n", pipex->outfile);
}

int	main(int argc, char **argv, char *env[])
{
	t_pipex	*pipex;
	int		pipefd[2];
	pid_t	pid;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		exit(-1);
	initialize_values(pipex);
	check_arguments(argc, argv, pipex, env);
	pipe(pipefd);
	if (pipe(pipefd) == -1)
		Exit_print_Error(pipex);
	pid = fork();
	if (pid == -1)
		Exit_print_Error(pipex);
	if (pid == 0)
		child_process(pipex, pipefd);
	else
		parent_process(pipex, pipefd);
	free_stack(pipex);
	return (0);
}
