/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:25:11 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/12/31 19:24:44 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	draw_bg(t_game *game)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (i < game->map_orginal.map_height)
	{
		j = 0;
		while (j < game->map_orginal.map_width)
		{
			mlx_image_to_window(game->mlx, game->ground, j * game->tile_size, i
				* game->tile_size);
			j++;
		}
		i++;
	}
}

void	draw_walls_exit(t_game *game)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (i < game->map_orginal.map_height)
	{
		j = 0;
		while (j < game->map_orginal.map_width)
		{
			if (game->map[i][j] == '1')
				mlx_image_to_window(game->mlx, game->wall, j * game->tile_size,
					i * game->tile_size);
			else if (game->map[i][j] == 'E')
				mlx_image_to_window(game->mlx, game->home, j * game->tile_size,
					i * game->tile_size);
			j++;
		}
		i++;
	}
}

void	draw_player(t_game *game)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (i < game->map_orginal.map_height)
	{
		j = 0;
		while (j < game->map_orginal.map_width)
		{
			if (game->map[i][j] == 'P')
				mlx_image_to_window(game->mlx, game->img, j * game->tile_size, i
					* game->tile_size);
			j++;
		}
		i++;
	}
}

void	draw_collectables(t_game *game)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (i < game->map_orginal.map_height)
	{
		j = 0;
		while (j < game->map_orginal.map_width)
		{
			mlx_image_to_window(game->mlx, game->baby, j * game->tile_size, i
				* game->tile_size);
			game->baby->instances[two2one(j, i, game)].enabled = false;
			if (game->map[i][j] == 'C')
				game->baby->instances[two2one(j, i, game)].enabled = true;
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *game)
{
	draw_bg(game);
	draw_walls_exit(game);
	draw_collectables(game);
	draw_player(game);
}
