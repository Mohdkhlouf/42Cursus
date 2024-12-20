/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:25:11 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/12/20 10:59:00 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void draw_bg(s_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i++ < game->map_height)
	{
		j = 0;
		while (j++ < game->map_width)
			mlx_image_to_window(game->mlx, game->ground, j* TILE_SIZE, i * TILE_SIZE);		
	}
}
void draw_walls_exit(s_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == '1')
				mlx_image_to_window(game->mlx, game->wall, j * TILE_SIZE,
					i * TILE_SIZE);
			else if (game->map[i][j] == 'E')
				mlx_image_to_window(game->mlx, game->home, j * TILE_SIZE,
					i * TILE_SIZE);
			j++;
		}
		i++;
	}
}
void draw_player(s_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'P')
				mlx_image_to_window(game->mlx, game->img, j * TILE_SIZE, i
					* TILE_SIZE);
			j++;
		}
		i++;
	}
}
void	draw_collectables(s_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < game->map_height)
	{
		j = 0;

		while (j < game->map_width)
		{
			mlx_image_to_window(game->mlx, game->baby, j * TILE_SIZE,
					i * TILE_SIZE);
			game->baby->instances[two2one(j, i,game)].enabled = false;
			if (game->map[i][j] == 'C')
				game->baby->instances[two2one(j, i,game)].enabled = true;
			j++;
		}
		i++;
	}
}
void draw_map(s_game *game)
{
	draw_bg(game);
	draw_walls_exit(game);
	draw_collectables(game);
	draw_player(game);
}