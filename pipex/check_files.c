/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/05 16:50:16 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_file_exisit_mode(char *filename, int mode)
{
	if (access(filename, F_OK | mode) == 0)
		return ;
	else
	{
		ft_putstr_fd("Error\n", 2);
	}
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

void	check_files(char *outfile, t_pipex *pipex)
{
	int	fd;
	
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
}

void	check_arguments(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("Error\n", 2);
		// free(pipex->cmds);
		// free(pipex);
		exit(1);
	}
	else
		return;
}
