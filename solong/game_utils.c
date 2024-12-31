/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 19:00:39 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/12/31 19:26:04 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	change_player_direction(t_game *game)
{
	game->player_place_x = game->img->instances->x / game->tile_size;
	game->player_place_y = game->img->instances->y / game->tile_size;
	mlx_delete_image(game->mlx, game->img);
	mlx_new_image(game->mlx, game->tile_size, game->tile_size);
	if (game->player_direction == 1)
	{
		game->img = mlx_texture_to_image(game->mlx,
				game->textures.player_left_t);
		game->player_direction = -1;
	}
	else if (game->player_direction == -1)
	{
		game->img = mlx_texture_to_image(game->mlx,
				game->textures.player_to_right_texture);
		game->player_direction = 1;
	}
	if (!game->img)
		perror("Errror loadng player to left image");
	mlx_image_to_window(game->mlx, game->img, game->player_place_x
		* game->tile_size, game->player_place_y * game->tile_size);
}

void	handle_collectable(t_game *game, int new_location_x, int new_location_y)
{
	game->collected += 1;
	game->map[new_location_y][new_location_x] = 'P';
	set_points(game, new_location_x, new_location_y);
	game->baby->instances[two2one(new_location_x, new_location_y,
			game)].enabled = false;
}

void	move_player(int x, int y, t_game *game)
{
	int	new_location_x;
	int	new_location_y;

	game->player_place_x = game->img->instances->x / game->tile_size;
	game->player_place_y = game->img->instances->y / game->tile_size;
	new_location_x = game->player_place_x + x;
	new_location_y = game->player_place_y + y;
	if (game->map[new_location_y][new_location_x] == 'E')
	{
		if (game->collected == game->assets.babies_to_collect)
			mlx_close_window(game->mlx);
		else
			set_points(game, new_location_x, new_location_y);
	}
	if (game->map[new_location_y][new_location_x] == '0')
		set_points(game, new_location_x, new_location_y);
	if (game->map[new_location_y][new_location_x] == 'C')
		handle_collectable(game, new_location_x, new_location_y);
	if (game->map[new_location_y][new_location_x] == 'P')
		set_points(game, new_location_x, new_location_y);
}

void	close_button(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_close_window(game->mlx);
}

void	game_counters(char buffer, t_game *game)
{
	if ((buffer != 'C') && (buffer != 'P') && (buffer != '1') && (buffer != '0')
		&& (buffer != '\n') && (buffer != 'E'))
		print_error_and_exit("Map Error: has unsupported letters.\n", game);
	if (buffer == 'C')
		game->assets.babies_to_collect += 1;
	if (buffer == 'P')
		game->assets.player_counter += 1;
	if (buffer == 'E')
		game->assets.exit_counter += 1;
}
