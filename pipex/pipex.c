/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/05 16:48:26 by mkhlouf          ###   ########.fr       */
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

void	first_command(t_pipex *pipex, int fd_in, int *pipefd)
{
	check_file_exisit_mode(pipex->t_infile, R_OK);
	pipex->infile = ft_strdup(pipex->t_infile);
	fd_in = open(pipex->infile, O_RDONLY);
	dup2(fd_in, 0);
	dup2(pipefd[1], 1);
	close(fd_in);
	close_pipfd_exec(pipefd, pipex, 0);
}

void	second_command(t_pipex *pipex, int fd_out, int *pipefd)
{
	fd_out = open(pipex->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	dup2(pipefd[0], 0);
	dup2(fd_out, 1);
	close(fd_out);
	close_pipfd_exec(pipefd, pipex, 1);
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
			first_command(pipex, fd_in, pipefd);
		else if (i == 1)
			second_command(pipex, fd_out, pipefd);
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
	initialize_values(pipex, &i , &status, argv);
	check_arguments(argc);
	check_files(argv[4], pipex); 
	check_commands(argv[2], argv[3], pipex, env);
	if (pipe(pipefd) == -1)
		exit_print_error(pipex);
	pid[0] = ft_exec(pipex, pipefd, 0);
	pid[0] = ft_exec(pipex, pipefd, 1);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid[0], &status, WNOHANG);
	waitpid(pid[1], &status, 0);
	free_stack(pipex);
	exit(WEXITSTATUS(status));
}
