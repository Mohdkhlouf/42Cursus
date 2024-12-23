/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:56:57 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/12/23 17:46:30 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "string.h"
char **create_map_arr(char **map, int *columns,int *rows)
{
	int i;
	
	i = 0;
	map = malloc(*rows * sizeof(char));
	if (!map)
		return (NULL);
	while (i < *rows)
	{
		map[i] = malloc(*columns * sizeof (char));
		if(!map[i])
		{
			while(i >= 0)
			{
				free(map[i]);
				i--;
			}
			free(map);
			return (NULL);
		}	
		i++;
	}
return (map);
}

int open_file()
{
	int fd;
	
	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
        perror("Error opening file");
	return (fd);
}

void update_game_collectables(const char *buffer, s_game *game, ssize_t read_bytes) {
    ssize_t i;

	i = 0;
	while (i < read_bytes)
	{
        if (buffer[i] == 'C')
            game->babies_to_collect += 1;
		i++;
    }
}

void process_buffer(const char *buffer, int *columns, int *rows, int *first_col_size, ssize_t read_bytes)
{
    ssize_t i;

	i = 0;
	while  (i < read_bytes)
	{
        if (buffer[i] == '\n')
		{
            (*rows)++;
            if (*first_col_size == 0)
                *first_col_size = *columns;
			else if (*first_col_size != *columns)
                exit(1);
            *columns = 0;
        }
		else 
            (*columns)++;
		i++;
    }
}

void read_file(int fd, int *columns, int *rows, s_game *game) {
    ssize_t read_bytes;
    char *buffer;
    int first_col_size = 0;

    buffer = malloc(BUFFER_SIZE);
    if (!buffer)
        exit(1);
    while ((read_bytes = read(fd, buffer, BUFFER_SIZE)) > 0) {
        update_game_collectables(buffer, game, read_bytes);
        process_buffer(buffer, columns, rows, &first_col_size, read_bytes);
    }
    if (read_bytes == -1) {
        free(buffer);
        exit(1);
    }
    if (*rows != 0) 
        (*rows)++;
    free(buffer);
}
char **fill_in_2d_map(char **map, int *columns,int *rows)
{	
	int fd;
	char *row;
	int i;
	
	fd = open("map.ber", O_RDONLY);
	row = malloc(*columns * sizeof(char) +1 );
	if(!row)
		return (NULL);
	i = 0;
	while (i < *rows)
	{
		read(fd, row, *columns+1);
		row[*columns] = '\n';
		map[i] = strdup(row);
		i++;
	}
	close(fd);
	return (map);
}
char	**read_map(int *columns, int *rows, s_game *game)
{
	char	**map;
	int i;
	int fd;
	
	fd = open_file();
	read_file(fd, columns, rows, game);
	if(!columns || !rows)
		exit(1);
	close(fd);
	map = create_map_arr(map, columns, rows);
	map = fill_in_2d_map(map, columns, rows);
	return (map);
}

