/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/11 16:37:35 by mkhlouf          ###   ########.fr       */
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
		if (!file_name)
			exit_print_error(pipex);
		if ((access(file_name, F_OK) == 0))
			return (file_name);
		else
			not_found = 1;
		i++;
	}
	if (not_found == 1)
		path_nfnound_error(pipex, file_name, cmd);
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
}

void	do_quotes(char *cmd, t_pipex *pipex, int i)
{
	int		y;
	char	*temp_cmd1;
	char	*temp_cmd2;
	int		len1;

	y = 0;
	len1 = 0;
	while (cmd[y] != '\0')
	{
		if (cmd[y] == ' ')
		{
			len1 = y;
			break ;
		}
		y++;
	}
	temp_cmd1 = malloc(len1 + 1);
	temp_cmd2 = malloc(ft_strlen(cmd) - len1 + 1);
	ft_strlcpy(temp_cmd1, cmd, len1 + 1);
	ft_strlcpy(temp_cmd2, cmd + len1 + 2, ft_strlen(cmd) - len1 - 2);
	pipex->cmds[i].cmd[0] = temp_cmd1;
	pipex->cmds[i].cmd[1] = temp_cmd2;
	pipex->cmds[i].cmd[2] = 0;
}

int	qoute_check(char *cmd)
{
	int	j;

	j = 0;
	while (cmd[j])
	{
		if (cmd[j] == 34 || cmd[j] == 39)
			return (1);
		j++;
	}
	return (0);
}

void	check_command(char *cmd, t_pipex *pipex, int i)
{
	int	len1;

	if (cmd[0] == '/')
		check_cmd_with_path(cmd, pipex, i);
	else
	{
		len1 = 0;
		cmd = ft_strjoin("/", cmd);
		if (!cmd)
			exit_print_error(pipex);
		pipex->cmds[i].cmd = ft_split(cmd, ' ');
		free(cmd);
		if (!pipex->cmds[i].cmd)
			exit_print_error(pipex);
		if (pipex->env_path)
			pipex->cmds[i].path = find_path(pipex, pipex->cmds[i].cmd[0]);
		else
			exit_print_error(pipex);
	}
}
