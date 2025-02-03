/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/03 03:01:22 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipfd_exec(int *pipefd, t_pipex *pipex, int i)
{
	close(pipefd[0]);
	close(pipefd[1]);
	// execve(pipex->cmds[i].path, pipex->cmds[i].cmd, NULL);
	if (execve(pipex->cmds[i].path, pipex->cmds[i].cmd, NULL) == -1)
	{
		perror("execve failed");
		exit(127);
	}
}

void	ft_exec(t_pipex *pipex, int *pipefd, int i)
{
	pid_t	pid;
	int		fd_in;
	int		fd_out;

	pid = fork();
	if (pid == -1)
		exit_print_error(pipex);
	if (pid == 0)
	{
		if (i == 0)
		{
			fd_in = open(pipex->infile, O_RDONLY);
			dup2(fd_in, 0);
			dup2(pipefd[1], 1);
			close(fd_in);
			close_pipfd_exec(pipefd, pipex, i);
		}
		else if (i == 1)
		{
			fd_out = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
			dup2(pipefd[0], 0);
			dup2(fd_out, 1);
			close(fd_out);
			close_pipfd_exec(pipefd, pipex, i);
		}
	}
}

int	main(int argc, char **argv, char *env[])
{
	t_pipex	*pipex;
	int		pipefd[2];
	int		i;

	i = 0;
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		exit(-1);
	initialize_values(pipex);
	check_arguments(argc, argv, pipex, env);
	if (pipe(pipefd) == -1)
		exit_print_error(pipex);
	while (i < pipex->counter)
	{
		ft_exec(pipex, pipefd, i);
		i++;
	}
	close(pipefd[0]);
	close(pipefd[1]);
	wait(NULL);
	wait(NULL);
	free_stack(pipex);
	exit (0);
}
