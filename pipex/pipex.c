/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/04 16:36:14 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipfd_exec(int *pipefd, t_pipex *pipex, int i)
{
	close(pipefd[0]);
	close(pipefd[1]);
	if (execve(pipex->cmds[i].path, pipex->cmds[i].cmd, NULL) == -1)
	{
		perror("execve failed");
		exit(127);
	}
}

void	first_command(t_pipex *pipex, int fd_in, int *pipefd, int i)
{
	fd_in = open(pipex->infile, O_RDONLY);
	dup2(fd_in, 0);
	dup2(pipefd[1], 1);
	close(fd_in);
	close_pipfd_exec(pipefd, pipex, i);
}

void	second_command(t_pipex *pipex, int fd_out, int *pipefd, int i)
{
	fd_out = open(pipex->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	dup2(pipefd[0], 0);
	dup2(fd_out, 1);
	close(fd_out);
	close_pipfd_exec(pipefd, pipex, i);
}

int	ft_exec(t_pipex *pipex, int *pipefd, int i)
{
	pid_t	pid;
	int		fd_in;
	int		fd_out;

	fd_in = 0;
	fd_out = 0;
	pid = fork();
	if (pid == -1)
		exit_print_error(pipex);
	if (pid == 0)
	{
		if (i == 0)
			first_command(pipex, fd_in, pipefd, i);
		else if (i == 1)
			second_command(pipex, fd_out, pipefd, i);
	}
	return (pid);
}

int	main(int argc, char **argv, char *env[])
{
	t_pipex	*pipex;
	int		pipefd[2];
	int		pid[2];
	int		i;
	int		status;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		exit(-1);
	initialize_values(pipex, &i , &status);
	check_arguments(argc, argv, pipex, env);
	if (pipe(pipefd) == -1)
		exit_print_error(pipex);
	while (i < pipex->counter)
	{
		pid[i] = ft_exec(pipex, pipefd, i);
		i++;
	}
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid[0], &status, WNOHANG);
	waitpid(pid[1], &status, 0);
	free_stack(pipex);
	exit(WEXITSTATUS(status));
}
