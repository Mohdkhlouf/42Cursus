/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:53:30 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/11 10:29:09 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execve_error_close(t_pipex *pipex)
{
	perror("execve failed: ");
	free_stack(pipex);
	exit(127);
}

void	permission_denide_error(t_pipex *pipex)
{
	ft_putstr_fd("pipex: permission denied: ", 2);
	ft_putstr_fd(pipex->t_outfile, 2);
	ft_putstr_fd("\n", 2);
	free_stack(pipex);
	exit(1);
}

void	check_grep(t_pipex *pipex, int i)
{
	int		j;
	int		y;
	char	*temp;

	y = 0;
	if (ft_strnstr(pipex->cmds[i].cmd[0], "grep", 5)
		&& pipex->cmds[i].cmd[1][0] == 39)
	{
		temp = malloc(sizeof(char) * (ft_strlen(pipex->cmds[i].cmd[0]) + 1
					- 2));
		while (pipex->cmds[i].cmd[1][j])
		{
			if (pipex->cmds[i].cmd[1][j] == 39)
				j++;
			else
			{
				temp[y] = pipex->cmds[i].cmd[1][j];
				j++;
				y++;
			}
		}
		free(pipex->cmds[i].cmd[1]);
		pipex->cmds[i].cmd[1] = temp;
		printf("CMD from grep #%s#\n", pipex->cmds[i].cmd[1]);
	}
}
