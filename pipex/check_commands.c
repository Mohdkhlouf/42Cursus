/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/03 17:47:09 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_commands_exisit_mode(char *filename, int mode, t_pipex *pipex)
{
	if (access(filename, F_OK | mode) == 0)
		return ;
	else
		exit_print_error(pipex);
}

void	check_accessed(char **path, char *cmd1, char *cmd2, t_pipex *pipex)
{
	pipex->cmds[0].path = find_path(path, cmd1);
	if (!pipex->cmds[0].path)
		exit_print_error(pipex);
	pipex->cmds[1].path = find_path(path, cmd2);
	if (!pipex->cmds[1].path)
		exit_print_error(pipex);
}

void	compare_commands(char **path, char *cmd1, char *cmd2, t_pipex *pipex)
{
	check_accessed(path, cmd1, cmd2, pipex);
	pipex->counter = 2;
	if (!pipex->cmds[0].path || !pipex->cmds[1].path)
		exit_print_error(pipex);
}

void	check_commands(char *cmd1, char *cmd2, t_pipex *pipex, char *env[])
{
	char	**path;

	cmd1 = ft_strjoin("/", cmd1);
	cmd2 = ft_strjoin("/", cmd2);
	pipex->cmds[0].cmd = ft_split(cmd1, ' ');
	pipex->cmds[1].cmd = ft_split(cmd2, ' ');
	ft_printf("cmd1:%s %s %s\n", pipex->cmds[0].cmd[0], pipex->cmds[0].cmd[1],
		pipex->cmds[0].cmd[2]);
	ft_printf("cmd2:%s %s % s\n", pipex->cmds[1].cmd[0], pipex->cmds[1].cmd[1],
		pipex->cmds[1].cmd[2]);
	path = parse_path(env, pipex);
	if (path)
		compare_commands(path, pipex->cmds[0].cmd[0], pipex->cmds[1].cmd[0],
			pipex);
	else
	{
		free_multi(cmd1, cmd2, NULL, NULL);  // Free cmd1 and cmd2
        free_2d_arr(path);  // Free parsed path
        exit_print_error(pipex);  // Exit with error
	}
	ft_printf("path1:%s\npath2:%s\n", pipex->cmds[0].path, pipex->cmds[1].path);
	free_multi(cmd1, cmd2, NULL, NULL);
	free_2d_arr(path);
}
