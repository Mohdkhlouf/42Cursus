/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 10:41:10 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/01 14:21:18 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

// to open the file
int	open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		print_error_and_exit("error in reading file", NULL);
	return (fd);
}

void	free_2d_map(t_game *game)
{
	unsigned int	i;

	i = 0;
	if (game->map)
	{
		while (i < game->map_orginal.map_height)
		{
			free(game->map[i]);
			game->map[i] = NULL;
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
}

void	free_2d_arr(char **arr2d, t_game *game)
{
	unsigned int	i;

	i = 0;
	while (i < game->map_orginal.map_height)
	{
		free(arr2d[i]);
		i++;
	}
	free(arr2d);
}

void	create_maze_arr(char **maze, t_game *game)
{
	unsigned int	i;

	i = 0;
	while (i < game->map_orginal.map_height * sizeof(char))
	{
		maze[i] = malloc(game->map_orginal.map_width * sizeof(char));
		if (!maze[i])
		{
			while (i > 0)
			{
				free(maze[i - 1]);
				i--;
			}
			free(maze);
			print_error_and_exit("creating 2d array faild", game);
		}
		i++;
	}
}

char	**fill_in_maze(char **maze, t_game *game)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < game->map_orginal.map_height)
	{
		j = 0;
		while (j < game->map_orginal.map_width)
		{
			maze[i][j] = game->map[i][j];
			j++;
		}
		i++;
	}
	return (maze);
}
