/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/01 02:04:16 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//--end of check commands functions
void	child_process(t_pipex *pipex, int *pipefd)
{
	close(1);
	pipefd[0] = open(pipex->infile, O_RDONLY);
	dup2(pipefd[0], 1);
	printf("Hi!, child process %s \n", pipex->infile);
	execve(pipex->path1, pipex->cmd1, NULL);
	exit(EXIT_SUCCESS);
}

void	parent_process(t_pipex *pipex, int *pipefd)
{
	close(pipefd[0]);
	pipefd[1] = open(pipex->outfile, O_WRONLY);
	dup2(pipefd[1],1);
	wait(NULL);
	execve(pipex->path2, pipex->cmd2, NULL);
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
