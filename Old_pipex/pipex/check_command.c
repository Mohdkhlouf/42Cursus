/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/06 16:15:03 by mkhlouf          ###   ########.fr       */
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
		if ((access(file_name, F_OK) == 0))
			return (file_name);
		i++;
	}
	free(file_name);
	return (NULL);
}

char	**parse_path(char *env[], t_pipex *pipex)
{
	int		i;
	char	**parse_path;
	char	*result;

	i = 0;
	parse_path = NULL;
	result = NULL;
	while (env[i])
	{
		result = ft_strnstr(env[i], "PATH=", 5);
		if (result)
		{
			parse_path = ft_split(result + 5, ':');
			if (!parse_path)
			{
				ft_putstr_fd("Error\n", 2);
				free_stack(pipex);
				exit(1);
			}
			return (parse_path);
		}
		i++;
	}
	free_2d_arr(parse_path);
	return (NULL);
}

void	check_command(char *cmd, t_pipex *pipex, char *env[], int i)
{
	char	**path;
	
	path = NULL;
	if (ft_strchr(cmd, '/'))
	{
		printf("fix when cmd is with full path\n");
	}
	else
	{
		cmd = ft_strjoin("/", cmd);
		pipex->cmds[i].cmd = ft_split(cmd, ' ');
		free_multi(cmd, NULL, NULL, NULL);
		path = parse_path(env, pipex);
		if (path)
			pipex->cmds[i].path = find_path(path, pipex->cmds[i].cmd[0]);
		else
		{
			free_2d_arr(path);
			exit_print_error(pipex);
		}
	}	
	free_2d_arr(path);
}
