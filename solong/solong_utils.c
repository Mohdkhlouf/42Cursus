/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:36:55 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/12/20 16:42:05 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	create_assets(s_game *game)
{
	mlx_texture_t	*baby_boy;
	mlx_texture_t	*wall;
	mlx_texture_t	*home;
	mlx_texture_t	*ground;
	mlx_texture_t	*player;
	

	baby_boy = mlx_load_png("assets/babyboy.png");
	wall = mlx_load_png("assets/wall.png");
	home = mlx_load_png("assets/home.png");
	ground = mlx_load_png("assets/ground.png");
	player = mlx_load_png("assets/player.png");
	game->player_to_left_texture = mlx_load_png("assets/player_to_left.png");
	game->player_to_right_texture = mlx_load_png("assets/player.png");
	if (!baby_boy || !wall || !home || !ground || !player || !game->player_to_left_texture)
		perror("error in loading image textures");
	game->wall = mlx_texture_to_image(game->mlx, wall);
	game->ground = mlx_texture_to_image(game->mlx, ground);
	game->home = mlx_texture_to_image(game->mlx, home);
	game->baby = mlx_texture_to_image(game->mlx, baby_boy);
	game->img = mlx_texture_to_image(game->mlx, player);
	// game->player_to_left = mlx_texture_to_image(game->mlx, game->player_to_left_texture);
	// game->player_to_right = mlx_texture_to_image(game->mlx, player);
	if (!game->wall || !game->ground || !game->home || !game->img || !game->player_to_left)
		perror("Error in loading textures to images");
	mlx_delete_texture(baby_boy);
	mlx_delete_texture(wall);
	mlx_delete_texture(home);
	mlx_delete_texture(ground);
	mlx_delete_texture(player);
}

int	two2one(int x, int y, s_game *game)
{
	return (y * game->map_width + x);
}


void set_points(s_game *game, int new_location_x, int new_location_y)
		{
			game->img->instances->x = new_location_x * TILE_SIZE;
			game->img->instances->y = new_location_y * TILE_SIZE;
		}