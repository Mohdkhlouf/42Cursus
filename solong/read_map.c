/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:56:57 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/12/13 17:12:11 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
char **create_map_arr(int *columns,int *rows)
{
	char **map;
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

char	*read_map(int fd, int *columns, int *rows)
{
	ssize_t		read_bytes;
	char	*buffer;
	char	**map;
	int		first_col_size;

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
	map = create_map_arr( columns, rows);
	return (0);
}
