/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/08 03:56:57 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(t_pipex *pipex, char *cmd)
{
	int		i;
	char	*file_name;
	int		not_found;

	not_found = 0;
	i = 0;
	file_name = NULL;
	while (pipex->env_path[i])
	{
		if (i != 0)
			free(file_name);
		file_name = ft_strjoin(pipex->env_path[i], cmd);
		if ((access(file_name, F_OK) == 0))
			return (file_name);
		else
			not_found = 1;
		i++;
	}
	if (not_found == 1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putstr_fd(cmd + 1, 2);
		ft_putstr_fd("\n", 2);
		free(file_name);
		free_stack(pipex);
		exit(127);
	}
	return (NULL);
}

void	check_cmd_with_path(char *cmd, t_pipex *pipex, int x)
{
	char	**temp;
	char	**temp2;
	int		len;
	int		i;

	i = 0;
	len = 0;
	temp = ft_split(cmd, ' ');
	temp2 = ft_split(temp[0], '/');
	while (temp2[i])
	{
		len++;
		i++;
	}
	pipex->cmds[x].path = temp[0];
	pipex->cmds[x].cmd = temp;
	pipex->cmds[x].cmd[0] = ft_strjoin("/", temp2[len - 1]);
	// free_2d_arr(temp);
	// free_2d_arr(temp2);
}

void	check_command(char *cmd, t_pipex *pipex, int i)
{
	if (ft_strchr(cmd, '/'))
		check_cmd_with_path(cmd, pipex, i);
	else
	{
		cmd = ft_strjoin("/", cmd);
		if (!cmd)
			exit_print_error(pipex);
		pipex->cmds[i].cmd = ft_split(cmd, ' ');
		free(cmd);
		if (!pipex->cmds[i].cmd)
		{
			exit_print_error(pipex);
		}
		if (pipex->env_path)
		{
			pipex->cmds[i].path = find_path(pipex, pipex->cmds[i].cmd[0]);
			printf(" real cmd%s\n", pipex->cmds[i].path);
		}
		else
			exit_print_error(pipex);
	}
}
