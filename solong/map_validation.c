/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 10:40:43 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/02 13:44:23 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "string.h"

void	wall_surrounded_faild(int *not_wall, t_game *game)
{
	*not_wall = 0;
	print_error_and_exit("Map is not surrounded by walls", game);
}

void	wall_surrounded(t_game *game)
{
	unsigned int	i;
	unsigned int	j;
	int				not_wall;

	not_wall = 1;
	i = 0;
	j = 0;
	while (i < game->map_orginal.map_height)
	{
		j = 0;
		while (j < game->map_orginal.map_width)
		{
			if (game->map[0][j] != '1' || game->map[game->map_orginal.map_height
				- 1][j] != '1')
				wall_surrounded_faild(&not_wall, game);
			if (game->map[i][0] != '1'
				|| game->map[i][game->map_orginal.map_width - 1] != '1')
				wall_surrounded_faild(&not_wall, game);
			j++;
		}
		i++;
	}
}

void	reading_validation(t_game *game)
{
	if (game->map_orginal.map_height == 0 || game->map_orginal.map_height == 0)
		print_error_and_exit("Map is not Valid", game);
	if (game->map_orginal.map_height < 3)
		print_error_and_exit("less than 3 Rows. or empty line in the end\n",
			game);
	if (game->map_orginal.map_width < 5)
		print_error_and_exit("less than 5 Columns. or empty line in the end\n",
			game);
	if (game->assets.babies_to_collect < 1)
		print_error_and_exit("has no collectabes.\n", game);
	if (game->assets.player_counter != 1)
		print_error_and_exit("has less or more than 1 Players.\n", game);
	if (game->assets.exit_counter != 1)
		print_error_and_exit("has less or more 1 exits.\n", game);
}

void	map_validation(t_game *game)
{
	wall_surrounded(game);
	path_validation(game);
}
