/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/03 17:53:30 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_files(char *infile, char *outfile, t_pipex *pipex)
{
	int	fd;

	check_file_exisit_mode(infile, R_OK, pipex);
	pipex->infile = ft_strdup(infile);
	if (access(outfile, F_OK) == 0)
	{
		if (access(outfile, W_OK) == 0)
			pipex->outfile = ft_strdup(outfile);
		else
			exit_print_error(pipex);
	}
	else
	{
		fd = open(outfile, O_CREAT | O_TRUNC, 0777);
		if (fd > -1)
			pipex->outfile = ft_strdup(outfile);
		close(fd);
	}
	ft_printf("infile:%s\noutfile:%s\n", pipex->infile, pipex->outfile);
}

void	check_arguments(int argc, char **argv, t_pipex *pipex, char *env[])
{
	if (argc != 5)
	{
		ft_putstr_fd("Error\n", 2);
		free(pipex->cmds);
		free(pipex);
		exit(1);
	}
	else
	{
		check_files(argv[1], argv[4], pipex);
		check_commands(argv[2], argv[3], pipex, env);
	}
}

void	check_file_exisit_mode(char *filename, int mode, t_pipex *pipex)
{
	if (access(filename, F_OK | mode) == 0)
		return ;
	else
		{
		ft_putstr_fd("Error\n", 2);
		free(pipex->cmds);
		free(pipex);
		exit(1);
		}
}

char	**parse_path(char *env[], t_pipex *pipex)
{
	int		i;
	char	**path;
	char	*temp;
	char *result;

	i = 0;
	while (env[i])
	{
		result = ft_strnstr(env[i], "PATH=", 5);
		if (result)
		{
			free(result);
			temp = ft_strdup(env[i] + 5);
			path = ft_split(temp, ':');
			free(temp);
			if (!path)
				exit_print_error(pipex);
			return (path);
		}
		i++;
	}
	return (NULL);
}

char	*find_path(char **path, char *cmd)
{
	int		i;
	char	*file_name;

	i = 0;
	while (path[i])
	{
		if (i != 0)
			free(file_name);
		file_name = ft_strjoin(path[i], cmd);
		if ((access(file_name, F_OK | X_OK) == 0))
		{
			free_2d_arr(path);
			return (file_name);
		}
		i++;
	}
	return (NULL);
}
