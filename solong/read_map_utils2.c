/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 10:41:10 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/31 16:16:38 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	print_exit_after_mlx(char *str, t_game *game)
{
	ft_printf("Error\n");
	ft_printf("%s", str);
	if ()
	if (game && game->map)
		free_2d_map(game);
	mlx_terminate(game->mlx);
	game->mlx = NULL;
	exit(EXIT_FAILURE);
}

void	print_error_and_exit(char *str, t_game *game)
{
	ft_printf("Error\n");
	ft_printf("%s", str);
	if (game && game->map)
		free_2d_map(game);
	exit(EXIT_FAILURE);
}

void	free_row_closefd(int fd, char *row, t_game *game, char *msg)
{
	close(fd);
	free(row);
	print_error_and_exit(msg, game);
}

void	free_faild_arr(t_game *game, int fd, char *row, unsigned int i)
{
	while (i > 0)
	{
		free(game->map[i - 1]);
		i--;
	}
	free(game->map);
	free_row_closefd(fd, row, game, "Memory allocation problem");
}

void	free_mlx(t_game *game)
{
	free_2d_map(game);
	mlx_terminate(game->mlx);
	exit(EXIT_FAILURE);
}
