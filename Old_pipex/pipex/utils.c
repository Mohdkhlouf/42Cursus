/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/07 14:23:17 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initialize_values(t_pipex *pipex, int *i, int *status, char *argv[])
{
	*status = 0;
	*i = 0;
	pipex->infile = NULL;
	pipex->outfile = NULL;
	pipex->cmds = malloc(sizeof(t_cmd) * 3);
	pipex->cmds[0].cmd = NULL;
	pipex->cmds[0].path = NULL;
	pipex->cmds[1].cmd = NULL;
	pipex->cmds[1].path = NULL;
	pipex->t_infile = argv[1];
	pipex->t_outfile = argv[4];
	pipex->t_cmd1 = argv[2];
	pipex->t_cmd2 = argv[3];
	pipex->counter = 0;
}

void	free_stack(t_pipex *pipex)
{
	if (pipex->cmds[0].cmd)
		free_2d_arr(pipex->cmds[0].cmd);
	if (pipex->cmds[0].path)
		free(pipex->cmds[0].path);
	if (pipex->cmds[1].cmd)
		free_2d_arr(pipex->cmds[1].cmd);
	if (pipex->cmds[1].path)
		free(pipex->cmds[1].path);
	free(pipex->cmds);
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

void	exit_print_error(t_pipex *pipex)
{
	ft_putstr_fd("Error\n", 2);
	free_stack(pipex);
	exit(1);
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
