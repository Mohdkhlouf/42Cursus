/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/08 02:53:55 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_outfile(t_pipex *pipex, int *pipefd)
{
	int	fd_out;

	fd_out = 0;
	if (access(pipex->t_outfile, F_OK) == 0)
	{
		if (access(pipex->t_outfile, W_OK) == 0)
		{
			pipex->outfile = pipex->t_outfile;
			fd_out = open(pipex->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
		}
		else
		{
			ft_putstr_fd("pipex: permission denied: ", 2);
			ft_putstr_fd(pipex->t_outfile, 2);
			ft_putstr_fd("\n", 2);
			free_stack(pipex);
			exit(1);
		}
	}
	else
	{
		pipex->outfile = pipex->t_outfile;
		fd_out = open(pipex->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	dup2(pipefd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	close(pipefd[0]);
	close(pipefd[1]);
}

void	second_command(t_pipex *pipex, int *pipefd, char *env[], int i)
{
	check_outfile(pipex, pipefd);
	if (pipex->outfile)
	{
		check_command(pipex->t_cmd2, pipex, i);
		if (pipex->cmds[1].path)
		{
			if (execve(pipex->cmds[1].path, pipex->cmds[1].cmd, env) == -1)
			{
				perror("execve failed: ");
				free_stack(pipex);
				exit(127);
			}
		}
		else
			exit(1);
	}
}

void	first_command(t_pipex *pipex, int *pipefd, char *env[], int i)
{
	int	fd_in;

	check_file_exisit_mode(pipex->t_infile, pipex);
	if (pipex->infile)
	{
		check_command(pipex->t_cmd1, pipex, i);
		if (pipex->cmds[i].path)
		{
			fd_in = open(pipex->infile, O_RDONLY);
			dup2(fd_in, STDIN_FILENO);
			dup2(pipefd[1], STDOUT_FILENO);
			close(fd_in);
			close(pipefd[1]);
			close(pipefd[0]);
			if (execve(pipex->cmds[0].path, pipex->cmds[0].cmd, env) == -1)
			{
				perror("execve failed: ");
				free_stack(pipex);
				exit(127);
			}
		}
		else
			exit(1);
	}
}

int	ft_exec2(t_pipex *pipex, int *pipefd, char *env[])
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_print_error(pipex);
	if (pid == 0)
		second_command(pipex, pipefd, env, 1);
	return (pid);
}

int	ft_exec1(t_pipex *pipex, int *pipefd, char *env[])
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		exit_print_error(pipex);
	if (pid == 0)
		first_command(pipex, pipefd, env, 0);
	waitpid(pid, &status, 0);
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
	pipex->env_path = parse_path(env, pipex);
	if (pipe(pipefd) == -1)
		exit_print_error(pipex);
	pid[0] = ft_exec1(pipex, pipefd, env);
	close(pipefd[1]);
	if (pid[0] > 0)
	{
		pid[1] = ft_exec2(pipex, pipefd, env);
		close(pipefd[0]);
		waitpid(pid[0], &status, WNOHANG);
		waitpid(pid[1], &status, 0);
	}
	free_stack(pipex);
	exit(WEXITSTATUS(status));
}
