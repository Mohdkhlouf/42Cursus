/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/04 18:29:58 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **path, char *cmd)
{
	int		i;
	char	*file_name;

	i = 0;
	file_name = NULL;
	while (path[i])
	{
		if (i != 0)
			free(file_name);
		file_name = ft_strjoin(path[i], cmd);
		if ((access(file_name, F_OK | X_OK) == 0))
			return (file_name);
		i++;
	}
	free(file_name);
	return (NULL);
}

void	check_commands_exisit_mode(char *filename, int mode, t_pipex *pipex)
{
	if (access(filename, F_OK | mode) == 0)
		return ;
	else
		exit_print_error(pipex);
}

void handle_2nd_cmd()
{
	printf("Do ls\n");
}
void	check_accessed(char **path, char *cmd1, char *cmd2, t_pipex *pipex)
{
	int result;
	
	pipex->cmds[0].path = find_path(path, cmd1);
	pipex->cmds[1].path = find_path(path, cmd2);
	
	if (!pipex->cmds[0].path)
	{
		if (!pipex->cmds[1].path)
		{
			free_2d_arr(path);
			exit_print_error(pipex);
		}	
		else
		{
			result = ft_strcmp("ls", pipex->cmds[1].cmd[0] + 1);
			if(result == 0)
				handle_2nd_cmd();
			else
			{
				free_2d_arr(path);
				exit_print_error(pipex);
			}
		}
	}
}

void	compare_commands(char **path, char *cmd1, char *cmd2, t_pipex *pipex)
{
	check_accessed(path, cmd1, cmd2, pipex);
	pipex->counter = 2;
	if (!pipex->cmds[0].path || !pipex->cmds[1].path)
	{
		free_2d_arr(path);
		exit_print_error(pipex);
	}	
}

void	check_commands(char *cmd1, char *cmd2, t_pipex *pipex, char *env[])
{
	char	**path;

	cmd1 = ft_strjoin("/", cmd1);
	cmd2 = ft_strjoin("/", cmd2);
	pipex->cmds[0].cmd = ft_split(cmd1, ' ');
	pipex->cmds[1].cmd = ft_split(cmd2, ' ');
	free_multi(cmd1, cmd2, NULL, NULL); 
	path = parse_path(env, pipex);
	if (path)
		compare_commands(path, pipex->cmds[0].cmd[0], pipex->cmds[1].cmd[0],
			pipex);
	else
	{
        free_2d_arr(path);
        exit_print_error(pipex);
	}
	free_2d_arr(path);
}
