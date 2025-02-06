/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/07 00:35:26 by mkhlouf          ###   ########.fr       */
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

void	check_command(char *cmd, t_pipex *pipex, int i)
{

	if (ft_strchr(cmd, '/'))
	{
		printf("fix when cmd is with full path\n");
	}
	else
	{
		cmd = ft_strjoin("/", cmd);
		pipex->cmds[i].cmd = ft_split(cmd, ' ');
		free_multi(cmd, NULL, NULL, NULL);
		if (pipex->env_path)
			pipex->cmds[i].path = find_path(pipex->env_path, pipex->cmds[i].cmd[0]);
		else
		{
			exit_print_error(pipex);
		}

	}	

}
