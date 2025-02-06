/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/06 03:39:14 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_command(t_pipex *pipex, int *fd_in, int *pipefd)
{
	check_file_exisit_mode(pipex->t_infile, pipex);
	if (pipex->infile)
	{
		*fd_in = open(pipex->infile, O_RDONLY);
		dup2(*fd_in, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(*fd_in);
		close(pipefd[1]);
		close(pipefd[0]);
		if (pipex->cmds[0].path)
			execve(pipex->cmds[0].path, pipex->cmds[0].cmd, NULL);
		else
			return ;
	}
}

void	check_outfile(t_pipex *pipex, int *fd_out)
{
	if (access(pipex->t_outfile, F_OK) == 0)
	{
		if (access(pipex->t_outfile, W_OK) == 0)
		{
			pipex->outfile = pipex->t_outfile;
			*fd_out = open(pipex->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
		}
		else
			exit_print_error(pipex);
	}
	else
	{
		pipex->outfile = pipex->t_outfile;
		*fd_out = open(pipex->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
}

void	second_command(t_pipex *pipex, int *fd_out, int *pipefd)
{
	check_outfile(pipex, fd_out);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(*fd_out, STDOUT_FILENO);
	close(*fd_out);
	close(pipefd[0]);
	close(pipefd[1]);
	if (execve(pipex->cmds[1].path, pipex->cmds[1].cmd, NULL) == -1)
	{
		perror("execve failed");
		exit(127);
	}
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
			first_command(pipex, &fd_in, pipefd);
		else if (i == 1)
			second_command(pipex, &fd_out, pipefd);
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

	pid[0] = 0;
	pid[1] = 0;
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		exit(-1);
	initialize_values(pipex, &i, &status, argv);
	check_arguments(argc, pipex);
	check_commands(argv[2], argv[3], pipex, env);
	if (pipe(pipefd) == -1)
		exit_print_error(pipex);
	pid[0] = ft_exec(pipex, pipefd, 0);
	pid[1] = ft_exec(pipex, pipefd, 1);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid[0], &status, 0);
	waitpid(pid[1], &status, 0);
	free_stack(pipex);
	exit(WEXITSTATUS(status));
}
