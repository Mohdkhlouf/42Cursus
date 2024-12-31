/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:01:10 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/12/31 19:24:12 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

bool	flood_fill_check_collectables(char **maze, unsigned int x,
		unsigned int y, t_game *game)
{
	if (game->collected == game->assets.babies_to_collect)
		return (true);
	if (maze[x][y] == 'C')
		game->collected += 1;
	if (maze[x][y] == '1' || maze[x][y] == 'V')
		return (false);
	maze[x][y] = 'V';
	if (x > 0 && maze[x - 1][y] != '1')
		if (flood_fill_check_collectables(maze, x - 1, y, game))
			return (true);
	if (y + 1 < game->map_orginal.map_width && maze[x][y + 1] != '1')
		if (flood_fill_check_collectables(maze, x, y + 1, game))
			return (true);
	if (y > 0 && maze[x][y - 1] != '1')
		if (flood_fill_check_collectables(maze, x, y - 1, game))
			return (true);
	if (x + 1 < game->map_orginal.map_height && maze[x + 1][y] != '1')
		if (flood_fill_check_collectables(maze, x + 1, y, game))
			return (true);
	return (false);
}

bool	flood_fill_check(char **maze, unsigned int x, unsigned int y,
		t_game *game)
{
	if (maze[x][y] == 'E')
		return (true);
	if (maze[x][y] == '1' || maze[x][y] == 'V')
		return (false);
	maze[x][y] = 'V';
	if (x > 0 && maze[x - 1][y] != '1')
		if (flood_fill_check(maze, x - 1, y, game))
			return (true);
	if (y + 1 < game->map_orginal.map_width && maze[x][y + 1] != '1')
		if (flood_fill_check(maze, x, y + 1, game))
			return (true);
	if (y > 0 && maze[x][y - 1] != '1')
		if (flood_fill_check(maze, x, y - 1, game))
			return (true);
	if (x + 1 < game->map_orginal.map_height && maze[x + 1][y] != '1')
		if (flood_fill_check(maze, x + 1, y, game))
			return (true);
	return (false);
}

void	find_player_points(t_game *game)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < game->map_orginal.map_height)
	{
		j = 0;
		while (j < game->map_orginal.map_width)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_point.x = i;
				game->player_point.y = j;
			}
			j++;
		}
		i++;
	}
}

void	path_validation(t_game *game)
{
	char	**maze;
	bool	is_solvable;
	bool	is_collectable;

	maze = malloc(game->map_orginal.map_height * sizeof(char *));
	if (!maze)
		print_error_and_exit("creating 2d array faild", game);
	find_player_points(game);
	create_maze_arr(maze, game);
	maze = fill_in_maze(maze, game);
	is_solvable = flood_fill_check(maze, game->player_point.x,
			game->player_point.y, game);
	maze = fill_in_maze(maze, game);
	is_collectable = flood_fill_check_collectables(maze, game->player_point.x,
			game->player_point.y, game);
	free_2d_arr(maze, game);
	game->collected = 0;
	if (!(is_solvable && is_collectable))
		print_error_and_exit("Map s not solvable", game);
}
