/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:29:16 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/12/31 19:31:21 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	initialize_struct_variable(t_game *game)
{
	game->map = NULL;
	game->map_orginal.map_height = 0;
	game->map_orginal.map_width = 0;
	game->player_direction = 1;
	game->collected = 0;
	game->assets.babies_to_collect = 0;
	game->assets.player_counter = 0;
	game->assets.exit_counter = 0;
	game->player_point.x = 0;
	game->player_point.y = 0;
	game->exit_point.x = 0;
	game->exit_point.y = 0;
	game->tile_size = TILE_SIZE;
}

void	check_filen_name(char *file_name)
{
	if (!(ft_strstr(file_name, ".ber")))
		print_error_and_exit("the Map file extintion is not corret.", NULL);
}

void	handle_keys(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
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

int	main(int argc, char *argv[])
{
	t_game	game;
	char	*file_name;

	if (argc > 2)
		print_error_and_exit("you have to enter only one file", NULL);
	file_name = argv[1];
	check_filen_name(file_name);
	initialize_struct_variable(&game);
	read_map(&game, file_name);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game.mlx = mlx_init(game.map_orginal.map_width * game.tile_size,
			game.map_orginal.map_height * game.tile_size, "MLX42", true);
	if (!game.mlx)
	{
		free_2d_map(&game);
		exit(EXIT_FAILURE);
	}
	create_assets(&game);
	draw_map(&game);
	mlx_key_hook(game.mlx, handle_keys, &game);
	mlx_close_hook(game.mlx, close_button, &game);
	mlx_loop(game.mlx);
	free_2d_map(&game);
	delete_textures_exit(&game);
	return (0);
}
