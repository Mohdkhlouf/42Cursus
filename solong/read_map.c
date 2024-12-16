/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:56:57 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/12/16 17:41:46 by mkhlouf          ###   ########.fr       */
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

char	**read_map(int *columns, int *rows)
{
	ssize_t		read_bytes;
	char	*buffer;
	char	**map;
	int		first_col_size;
	int i;
	int j;
	int fd;

	fd = 0;
	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
	{
        perror("Error opening file");
    }
	i = 0;
	j = 0;
	read_bytes = 1;
	first_col_size = 0;
	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			break;
		if (read_bytes == 0)
		{
			if(*rows !=0)
			{
				*rows += 1;
				break ;
			}
			else
				break ;
		}
		if (*buffer == '\n')
		{
			*rows += 1;
			if (first_col_size == 0)
				first_col_size = *columns;
			else if(first_col_size != *columns)
			{
				perror("Map is not rectangle");
				exit(1);
			}
			*columns = 0;
		}
		else
			*columns += 1;
	}
	if(!columns || !rows)
		exit(1);
	close(fd);
	
	map = create_map_arr(map, columns, rows);
	char *row;
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

