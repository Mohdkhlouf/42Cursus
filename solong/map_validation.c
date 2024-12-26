/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 10:40:43 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/12/26 16:15:21 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"



// void path_validation(char **map_arr, s_game *game)
// {
// 	puts("HI");
// }


void wall_surrounded_faild(int *not_wall)
{
	not_wall = 0;
	print_error_and_exit("Map is not surrounded by walls horizantally");
}

void wall_surrounded(char **map_arr, s_game *game)
{
	unsigned int i;
	unsigned int j;
	int not_wall;

	not_wall = 1;
	i = 0;
	j = 0;
	while (i < game->map_orginal.map_height)
	{
		j = 0;
		while (j < game->map_orginal.map_width)
		{
			if (map_arr[0][j] != '1' || map_arr[game->map_orginal.map_height
				- 1][j] != '1')
				wall_surrounded_faild(&not_wall);
			if (map_arr[i][0] != '1' || map_arr[i][game->map_orginal.map_width
				- 1] != '1')
				wall_surrounded_faild(&not_wall);
			j++;
		}
		i++;
	}
}

void	map_validation(char **map_arr, s_game *game)
{
	wall_surrounded(map_arr,game);
	// path_validation(map_arr,game);
}

void reading_validation(s_game *game)
{
	if (game->map_orginal.map_height < 3)
		print_error_and_exit("Map Error: has less than 3 Rows.\n");
	if (game->map_orginal.map_width < 3)
		print_error_and_exit("Map Error: has less than 3 Columns.\n");
	if (game->assets.babies_to_collect < 1)
		print_error_and_exit("Map Error: has no collectabes.\n");
	if (game->assets.player_counter != 1)
		print_error_and_exit("Map Error: has less or more than 1 Players.\n");
	if (game->assets.exit_counter != 1)
		print_error_and_exit("Map Error: has less or more 1 exits.\n");
}