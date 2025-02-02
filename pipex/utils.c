/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/02 21:28:01 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initialize_values(t_pipex *pipex)
{
	pipex->infile = NULL;
	pipex->outfile = NULL;
	pipex->cmds = malloc(sizeof(t_cmd)); 
	pipex->counter = 120;
}
void	free_stack(t_pipex *pipex)
{
	// if (pipex->infile)
	// 	free(pipex->infile);
	// if (pipex->outfile)
	// 	free(pipex->outfile);
	// if (pipex->cmds[0])
	// 	free_2d_arr(pipex->cmds[0]);
	// if (pipex->paths)
	// 	free_2d_arr(pipex->paths);
	free(pipex);
}

void	free_multi(char *str1, char *str2, char *str3, char *str4)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	if (str3)
		free(str3);
	if (str4)
		free(str4);
}

void	Exit_print_Error(t_pipex *pipex)
{
	ft_putstr_fd("Error\n", 2);
	free_stack(pipex);
	exit(-1);
}
void	free_2d_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

