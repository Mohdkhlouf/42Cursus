/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/10 14:56:44 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_outfile(t_pipex *pipex, int *fd_out)
{
	pipex->outfile = pipex->t_outfile;
	*fd_out = open(pipex->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (*fd_out == -1)
		exit_print_error(pipex);
}

void	check_outfile(t_pipex *pipex, int *fd_out)
{
	if (access(pipex->t_outfile, F_OK) == 0)
	{
		if (access(pipex->t_outfile, W_OK) == 0)
			open_outfile(pipex, fd_out);
		else
			permission_denide_error(pipex);
	}
	else
		open_outfile(pipex, fd_out);
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
	return (NULL);
}

void	check_file_exisit_mode(char *filename, t_pipex *pipex)
{
	if (access(filename, F_OK) == 0)
	{
		if (access(filename, R_OK) == 0)
			pipex->infile = filename;
		else
		{
			ft_putstr_fd("pipex: permission denied: ", 2);
			ft_putstr_fd(pipex->t_infile, 2);
			ft_putstr_fd("\n", 2);
			free_stack(pipex);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		pipex->infile = NULL;
		ft_putstr_fd("pipex: no such file or directory: ", 2);
		ft_putstr_fd(pipex->t_infile, 2);
		ft_putstr_fd("\n", 2);
		free_stack(pipex);
		exit(EXIT_FAILURE);
	}
}

void	check_arguments(int argc, t_pipex *pipex)
{
	if (argc != 5)
		exit_print_error(pipex);
	else
		return ;
}
