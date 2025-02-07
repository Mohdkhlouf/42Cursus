/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/07 14:48:23 by mkhlouf          ###   ########.fr       */
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
			ft_putstr_fd("pipex: permission denied: ", 2);
			ft_putstr_fd(pipex->infile, 2);
			ft_putstr_fd("\n", 2);
		}
	}
	else
	{
		pipex->infile = NULL;
		ft_putstr_fd("pipex: no such file or directory: ", 2);
		ft_putstr_fd(pipex->t_infile, 2);
		ft_putstr_fd("\n", 2);
	}
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
