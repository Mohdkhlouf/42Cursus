/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/07 01:36:29 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	check_outfile(t_pipex *pipex, int *pipefd)
// {
// 	int	fd_out;

// 	fd_out = 0;
// 	if (access(pipex->t_outfile, F_OK) == 0)
// 	{
// 		if (access(pipex->t_outfile, W_OK) == 0)
// 		{
// 			pipex->outfile = pipex->t_outfile;
// 			fd_out = open(pipex->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
// 		}
// 		else
// 			exit_print_error(pipex);
// 	}
// 	else
// 	{
// 		pipex->outfile = pipex->t_outfile;
// 		fd_out = open(pipex->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
// 	}

// }

void	second_command(t_pipex *pipex, int *pipefd, char *env[])
{
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(pipex->fd_out, STDOUT_FILENO);
	close(pipefd[0]);
	// check_outfile(pipex, pipefd);
	pipex->outfile = pipex->t_outfile;
	check_command(pipex->t_cmd2, pipex, 1);
	if (!pipex->cmds[1].path)
		print_error_exit("Command 1 is not valid");
	execve(pipex->cmds[1].path, pipex->cmds[1].cmd, env);
}

void	first_command(t_pipex *pipex, int *pipefd, char *env[])
{
	close(pipefd[0]);
	dup2(pipex->fd_in, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	pipex->infile = pipex->t_infile;
	// check_file_exisit_mode(pipex->t_infile, pipex);
	check_command(pipex->t_cmd1, pipex, 0);
	if (!pipex->cmds[0].path)
		print_error_exit("Command 1 is not valid");
	execve(pipex->cmds[0].path, pipex->cmds[0].cmd, env);
}

int	ft_exec_cmd2(t_pipex *pipex, int *pipefd, char *env[])
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_print_error(pipex);
	if (pid == 0)
		second_command(pipex, pipefd, env);
	return (pid);
}

int	ft_exec_cmd1(t_pipex *pipex, int *pipefd, char *env[])
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_print_error(pipex);
	if (pid == 0)
		first_command(pipex, pipefd, env);
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
	initialize_values(pipex, &status, argv);
	check_arguments(argc, pipex);
	pipex->env_path = parse_path(env, pipex);
	if (pipe(pipefd) == -1)
		exit_print_error(pipex);
	pid[0] = ft_exec_cmd1(pipex, pipefd, env);
	pid[1] = ft_exec_cmd2(pipex, pipefd, env);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid[0], &status, 0);
	waitpid(pid[1], &status, 0);
	free_stack(pipex);
	exit(WEXITSTATUS(status));
}
