/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/06 03:39:04 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_file_exisit_mode(char *filename, t_pipex *pipex)
{
	if (access(filename, F_OK) == 0)
	{
		if (access(filename, R_OK) == 0)
		{
			pipex->infile = filename;
		}
		else
		{
			ft_putstr_fd("Error: No permission to access file\n", 2);
		}
	}
	else
	{
		pipex->infile = NULL;
		ft_putstr_fd("Error: File does not exist\n", 2);
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

void	check_arguments(int argc,t_pipex *pipex)
{
	if (argc != 5)
	{
		exit_print_error(pipex);
	}
	else
		return ;
}
