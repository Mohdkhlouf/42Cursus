/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/10 16:35:07 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	second_command(t_pipex *pipex, int *pipefd, char *env[], int i)
{
	int	fd_out;

	check_outfile(pipex, &fd_out);
	if (pipex->outfile)
	{
		check_command(pipex->t_cmd2, pipex, i);
		printf("%s\n", pipex->cmds[1].cmd[0]);
		printf("%s\n", pipex->cmds[1].cmd[1]);
		printf("%s\n", pipex->cmds[1].cmd[2]);
		printf("%s\n", pipex->cmds[1].cmd[3]);
		printf("%s\n", pipex->cmds[1].cmd[4]);
		if (pipex->cmds[1].path)
		{
			check_grep(pipex, 1);
			dup2(pipefd[0], STDIN_FILENO);
			dup2(fd_out, STDOUT_FILENO);
			close(fd_out);
			close(pipefd[0]);
			close(pipefd[1]);
			if (execve(pipex->cmds[1].path, pipex->cmds[1].cmd, env) == -1)
				execve_error_close(pipex);
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
			check_grep(pipex, 0);
			fd_in = open(pipex->infile, O_RDONLY);
			if (fd_in == -1)
				exit_print_error(pipex);
			dup2(fd_in, STDIN_FILENO);
			dup2(pipefd[1], STDOUT_FILENO);
			close(fd_in);
			close(pipefd[1]);
			close(pipefd[0]);
			if (execve(pipex->cmds[0].path, pipex->cmds[0].cmd, env) == -1)
				execve_error_close(pipex);
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

	pid = fork();
	if (pid == -1)
		exit_print_error(pipex);
	if (pid == 0)
		first_command(pipex, pipefd, env, 0);
	return (pid);
}

int	main(int argc, char **argv, char *env[])
{
	t_pipex	*pipex;
	int		pipefd[2];
	int		pid[2];
	int		status;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		exit(-1);
	initialize_values(pipex, &status, argv, pid);
	check_arguments(argc, pipex);
	pipex->env_path = parse_path(env, pipex);
	if (pipe(pipefd) == -1)
		exit_print_error(pipex);
	pid[0] = ft_exec1(pipex, pipefd, env);
	close(pipefd[1]);
	pid[1] = ft_exec2(pipex, pipefd, env);
	close(pipefd[0]);
	waitpid(pid[0], &status, 0);
	waitpid(pid[1], &status, 0);
	free_stack(pipex);
	exit(WEXITSTATUS(status));
}
