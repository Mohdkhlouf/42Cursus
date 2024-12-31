/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 10:41:10 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/12/31 19:22:32 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	print_error_and_exit(char *str, t_game *game)
{
	perror("Error\n");
	perror(str);
	if (game && game->map)
		free_2d_map(game);
	exit(-1);
}

void	free_row_closefd(int fd, char *row, t_game *game)
{
	close(fd);
	free(row);
	print_error_and_exit("creating 2d array faild", game);
}

void	free_faild_arr(t_game *game, int fd, char *row, unsigned int i)
{
	while (i > 0)
	{
		free(game->map[i - 1]);
		i--;
	}
	free(game->map);
	free_row_closefd(fd, row, game);
}
