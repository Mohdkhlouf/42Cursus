/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/03 00:38:44 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipfd_exec(int *pipefd, t_pipex *pipex, int i)
{
	close(pipefd[0]);
	close(pipefd[1]);
	execve(pipex->cmds[i].path, pipex->cmds[i].cmd, NULL);
}
void	ft_exec(t_pipex *pipex, int *pipefd, int i)
{
	pid_t	pid;
	int		fd_in;
	int		fd_out;

	pid = fork();
	if (pid == -1)
		Exit_print_Error(pipex);
	if (pid == 0)
	{
		if (i == 0)
		{
			fd_in = open(pipex->infile, O_RDONLY);
			dup2(fd_in, 0);
			dup2(pipefd[1], 1);
			close_pipfd_exec(pipefd, pipex, i);
		}
		else if (i == 1)
		{
			fd_out = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			dup2(pipefd[0], 0);
			dup2(fd_out, 1);
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
		Exit_print_Error(pipex);
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
	return (0);
}
