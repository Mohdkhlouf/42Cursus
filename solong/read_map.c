/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:56:57 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/12/30 16:19:41 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

// allocate memory for the map
void	read_map_to_array(int fd, char *row, t_game *game)
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
			print_error_and_exit("creating 2d array faild");
		}
		row[game->map_orginal.map_width] = '\0';
		game->map[i] = ft_strdup(row);
		if (!game->map[i])
		{
			while (i > 0)
			{
				free(game->map[i - 1]);
				i--;
			}
			free(game->map);
			close(fd);
			free(row);
			print_error_and_exit("creating 2d array faild");
		}
		if (bytes_read == 0)
		{
			free(row);
			close(fd);
			break;
		}
		i++;
	}
}

// will copy the content of the file fo the 2d array.
void	fill_in_2d_map(t_game *game, char *file_name)
{
	int		fd;
	char	*row;

	fd = open_file(file_name);
	row = malloc(game->map_orginal.map_width * sizeof(char) + 1);
	if (!row)
	{
		close(fd);
		print_error_and_exit("creating 2d array faild");;
	}
	read_map_to_array(fd, row, game);
	free(row);
	close(fd);
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

void read_map(t_game *game, char *file_name)
{
	int		fd;

	fd = open_file(file_name);
	read_file(fd, game);
	close(fd);
	create_map_arr(game);
	fill_in_2d_map(game, file_name);
	map_validation(game);
}
