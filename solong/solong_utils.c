/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:36:55 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/06 15:55:21 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	creat_images(t_game *game)
{
	game->wall = mlx_texture_to_image(game->mlx, game->textures.wall);
	if (!game->wall)
		print_exit_after_mlx("Cannot load image of wall", game);
	game->ground = mlx_texture_to_image(game->mlx, game->textures.ground);
	if (!game->ground)
		print_exit_after_mlx("Cannot load image of ground", game);
	game->home = mlx_texture_to_image(game->mlx, game->textures.home);
	if (!game->home)
		print_exit_after_mlx("Cannot load image of Exit", game);
	game->baby = mlx_texture_to_image(game->mlx, game->textures.baby_boy);
	if (!game->baby)
		print_exit_after_mlx("Cannot load image of Baby", game);
	game->img = mlx_texture_to_image(game->mlx, game->textures.player);
	if (!game->wall)
		print_exit_after_mlx("Cannot load image of wall", game);
}

void	creat_textures(t_game *game)
{
	game->textures.baby_boy = mlx_load_png("textures/babyboy.png");
	if (!game->textures.baby_boy)
		print_exit_after_mlx("Cannot create baby textures", game);
	game->textures.wall = mlx_load_png("textures/wall.png");
	if (!game->textures.wall)
		print_exit_after_mlx("Cannot create wall textures", game);
	game->textures.home = mlx_load_png("textures/home.png");
	if (!game->textures.home)
		print_exit_after_mlx("Cannot create home textures", game);
	game->textures.ground = mlx_load_png("textures/ground.png");
	if (!game->textures.ground)
		print_exit_after_mlx("Cannot create ground textures", game);
	game->textures.player = mlx_load_png("textures/player.png");
	if (!game->textures.player)
		print_exit_after_mlx("Cannot create player textures", game);
	game->textures.player_left_t = mlx_load_png("textures/player_to_left.png");
	if (!game->textures.player_left_t)
		print_exit_after_mlx("Cannot create player left textures", game);
	game->textures.player_right_tex = mlx_load_png("textures/player.png");
	if (!game->textures.player_right_tex)
		print_exit_after_mlx("Cannot create palyer right tetxures", game);
}

void	create_assets(t_game *game)
{
	creat_textures(game);
	creat_images(game);
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
	game->img->instances->x = new_location_x * game->tile_size;
	game->img->instances->y = new_location_y * game->tile_size;
	game->move_counter += 1;
	ft_printf("number of movements: %u\n", game->move_counter);
}
