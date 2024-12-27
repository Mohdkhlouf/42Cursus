/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:56:57 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/12/27 19:57:04 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

// allocate memory for the map
char	**read_map_to_array(int fd, char **map, char *row, t_game *game)
{
	unsigned int	i;
	int				bytes_read;

	i = 0;
	bytes_read = 1;
	while (i < game->map_orginal.map_height && bytes_read > 0)
	{
		bytes_read = read(fd, row, game->map_orginal.map_width + 1);
		if (bytes_read < 0)
		{
			free(row);
			close(fd);
			return (NULL);
		}
		row[game->map_orginal.map_width] = '\0';
		map[i] = ft_strdup(row);
		if (!map[i])
		{
			free(row);
			close(fd);
			return (NULL);
		}
		i++;
	}
	return (map);
}

// will copy the content of the file fo the 2d array.
char	**fill_in_2d_map(char **map, t_game *game, char *file_name)
{
	int		fd;
	char	*row;

	fd = open_file(file_name);
	row = malloc(game->map_orginal.map_width + 1);
	if (!row)
	{
		close(fd);
		print_error_and_exit("error in mallocating row");
	}
	map = read_map_to_array(fd, map, row, game);
	free(row);
	close(fd);
	return (map);
}

void	handle_new_line(unsigned int *first_row_size, t_game *game, char buffer)
{
	if (buffer == '\n')
	{
		(game->map_orginal.map_height)++;
		if (*first_row_size == 0)
			*first_row_size = game->map_orginal.map_width;
		else if (*first_row_size != game->map_orginal.map_width)
			print_error_and_exit("Map is not rectangle shape");
		game->map_orginal.map_width = 0;
	}
	else
		game->map_orginal.map_width++;
}

// read the map file and count the rows and cols. and collectabels
void	read_file(int fd, t_game *game)
{
	ssize_t			read_bytes;
	char			*buffer;
	unsigned int	first_row_size;

	first_row_size = 0;
	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		exit(1);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		game_counters(*buffer, game);
		handle_new_line(&first_row_size, game, *buffer);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (read_bytes == -1)
		{
			free(buffer);
			exit(1);
		}
	if (game->map_orginal.map_height != 0)
		(game->map_orginal.map_height)++;
	reading_validation(game);
	free(buffer);
}

char	**read_map(t_game *game, char *file_name)
{
	char	**map;
	char	**map_arr;
	int		fd;

	map = NULL;
	map_arr = NULL;
	fd = open_file(file_name);
	read_file(fd, game);
	close(fd);
	map = create_map_arr(map, game);
	map_arr = fill_in_2d_map(map, game, file_name);
	map = NULL;
	map_validation(map_arr, game);
	game->map = map_arr;
	return (NULL);
}
