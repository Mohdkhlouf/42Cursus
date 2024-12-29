/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:36:55 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/12/29 22:07:40 by mohammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	creat_textures(t_game *game)
{
	game->textures.baby_boy = mlx_load_png("assets/babyboy.png");
	game->textures.wall = mlx_load_png("assets/wall.png");
	game->textures.home = mlx_load_png("assets/home.png");
	game->textures.ground = mlx_load_png("assets/ground.png");
	game->textures.player = mlx_load_png("assets/player.png");
	game->textures.player_left_t = mlx_load_png("assets/player_to_left.png");
	game->textures.player_to_right_texture = mlx_load_png("assets/player.png");
	if (!game->textures.baby_boy || !game->textures.wall || !game->textures.home
		|| !game->textures.ground || !game->textures.player
		|| !game->textures.player_left_t)
		perror("error in loading image textures");
	game->wall = mlx_texture_to_image(game->mlx, game->textures.wall);
	game->ground = mlx_texture_to_image(game->mlx, game->textures.ground);
	game->home = mlx_texture_to_image(game->mlx, game->textures.home);
	game->baby = mlx_texture_to_image(game->mlx, game->textures.baby_boy);
	game->img = mlx_texture_to_image(game->mlx, game->textures.player);
	if (!game->wall || !game->ground || !game->home || !game->img
		|| !game->baby)
		perror("Error in loading textures to images");
}

void	create_assets(t_game *game)
{
	creat_textures(game);
	mlx_delete_texture(game->textures.baby_boy);
	mlx_delete_texture(game->textures.wall);
	mlx_delete_texture(game->textures.home);
	mlx_delete_texture(game->textures.ground);
	mlx_delete_texture(game->textures.player);
}

int	two2one(int x, int y, t_game *game)
{
	return (y * game->map_orginal.map_width + x);
}

void	set_points(t_game *game, int new_location_x, int new_location_y)
{
	game->img->instances->x = new_location_x * TILE_SIZE;
	game->img->instances->y = new_location_y * TILE_SIZE;
}
