/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/01 01:01:27 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_commands_exisit_mode(char *filename, int mode, t_pipex *pipex)
{
	printf("%s , %d \n", filename, mode);
	if (access(filename, F_OK | mode) == 0)
		return ;
	else
		Exit_print_Error(pipex);
}

void	check_accessed(char **path, char *cmd1, char *cmd2, t_pipex *pipex)
{
	pipex->path1 = find_path(path, cmd1);
	if (!pipex->path1)
		Exit_print_Error(pipex);
	pipex->path2 = find_path(path, cmd2);
	if (!pipex->path1)
		Exit_print_Error(pipex);
}
void	compare_commands(char **path, char *cmd1, char *cmd2, t_pipex *pipex)
{
	cmd1 = ft_strjoin("/", cmd1);
	cmd2 = ft_strjoin("/", cmd2);
	check_accessed(path, cmd1, cmd2, pipex);
	if (!pipex->path1 && !pipex->path2)
		Exit_print_Error(pipex);
	free(cmd1);
	free(cmd2);
}
void	check_commands(char *cmd1, char *cmd2, t_pipex *pipex, char *env[])
{
	char	**path;

	cmd1 = ft_strjoin("/", cmd1);
	cmd2 = ft_strjoin("/", cmd2);
	pipex->cmd1 = ft_split(cmd1, ' ');
	pipex->cmd2 = ft_split(cmd2, ' ');
	path = parse_path(env, pipex);
	if (path)
		compare_commands(path, pipex->cmd1[0], pipex->cmd2[0], pipex);
	ft_printf("path1:%s\npath2:%s\n", pipex->path1, pipex->path2);
	ft_printf("cmd1:%s\ncmd2:%s\n", pipex->cmd1[0], pipex->cmd2[0]);
	free_2d_arr(path);
}
