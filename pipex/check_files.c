/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/07 00:46:54 by mkhlouf          ###   ########.fr       */
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

void	check_arguments(int argc,t_pipex *pipex)
{
	if (argc != 5)
	{
		exit_print_error(pipex);
	}
	pipex->fd_in = open(pipex->t_infile, O_RDONLY);
	pipex->fd_out = open(pipex->t_outfile, O_TRUNC | O_CREAT | O_RDWR, 0644);//TRUNC - if file exsist, clear it.
	if (pipex->fd_in== -1)
		print_error_exit("infile is not exist");
	if (pipex->fd_out == -1)
		print_error_exit("outfile is not exist");

}
