/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:29:16 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/12/26 16:26:57 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	change_player_direction(s_game *game)
{
	game->player_place_x = game->img->instances->x / TILE_SIZE;
	game->player_place_y = game->img->instances->y / TILE_SIZE;
	mlx_delete_image(game->mlx, game->img);
	mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (game->player_direction == 1)
	{
		game->img = mlx_texture_to_image(game->mlx,
				game->textures.player_to_left_texture);
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
	mlx_image_to_window(game->mlx, game->img, game->player_place_x * TILE_SIZE,
		game->player_place_y * TILE_SIZE);
}

void	handle_collectable(s_game *game, int new_location_x, int new_location_y)
{
	game->collected += 1;
	game->map[new_location_y][new_location_x] = 'P';
	set_points(game, new_location_x, new_location_y);
	// game->map[game->player_place_y][game->player_place_x] = '0';
	game->baby->instances[two2one(new_location_x, new_location_y,
			game)].enabled = false;
}

void	delete_textures_exit(s_game *game)
{
	mlx_delete_texture(game->textures.player_to_left_texture);
	mlx_delete_texture(game->textures.player_to_right_texture);
	exit(0);
}

void	print_2d_arr(s_game *game)
{
	unsigned int	i;

	i = 0;
	while (i < game->map_orginal.map_height)
	{
		printf("%s\n", game->map[i]);
		i++;
	}
}
void	move_player(int x, int y, s_game *game)
{
	int	new_location_x;
	int	new_location_y;

	game->player_place_x = game->img->instances->x / TILE_SIZE;
	game->player_place_y = game->img->instances->y / TILE_SIZE;
	new_location_x = game->player_place_x + x;
	new_location_y = game->player_place_y + y;
	if (game->map[new_location_y][new_location_x] == 'E')
	{
		if (game->collected == game->assets.babies_to_collect)
			delete_textures_exit(game);
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
void	handle_keys(mlx_key_data_t keydata, void *param)
{
	s_game	*game;

	game = (s_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		printf("ESC\n");
		free(game->map);
		exit(0);
	}
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		&& keydata.action == MLX_PRESS)
		move_player(0, -1, game);
	if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		&& keydata.action == MLX_PRESS)
		move_player(0, +1, game);
	if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		&& keydata.action == MLX_PRESS)
	{
		if (game->player_direction == -1)
			change_player_direction(game);
		move_player(+1, 0, game);
	}
	if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		&& keydata.action == MLX_PRESS)
	{
		if (game->player_direction == 1)
			change_player_direction(game);
		move_player(-1, 0, game);
	}
}

void	initialize_struct_variable(s_game *game)
{
	game->map = NULL;
	game->map_orginal.map_height = 0;
	game->map_orginal.map_width = 0;
	game->player_direction = 1;
	game->collected = 0;
	game->assets.babies_to_collect = 0;
	game->assets.player_counter = 0;
	game->assets.exit_counter = 0;
}
int32_t	main(int argc, char *argv[])
{
	s_game	game;
	char	*file_name;

	if (argc > 2)
		print_error_and_exit("you have to enter only one file");
	file_name = argv[1];
	check_filen_name(file_name);
	initialize_struct_variable(&game);
	read_map(&game, file_name);
	if (!game.map_orginal.map_height || !game.map_orginal.map_width)
		print_error_and_exit("No height and width for map");
	game.mlx = mlx_init(game.map_orginal.map_width * TILE_SIZE,
			game.map_orginal.map_height * TILE_SIZE, "MLX42", true);
	if (!game.mlx)
	{
		exit(EXIT_FAILURE);
	}
	create_assets(&game);
	draw_map(&game);
	mlx_key_hook(game.mlx, handle_keys, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (0);
}
