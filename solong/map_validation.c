/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 10:40:43 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/12/25 15:58:15 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	map_validation(char **map_arr, s_game *game)
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
			{
				not_wall = 0;
				print_error_and_exit("Map is not surrounded by walls horizantally");
			}
			if (map_arr[i][0] != '1' || map_arr[i][game->map_orginal.map_width
				- 1] != '1')
			{
				not_wall = 0;
				print_error_and_exit("Map is not surrounded by walls vertically");
			}
			j++;
		}
		// printf("%s", map_arr[i]);
		i++;
	}
	return (not_wall);
}