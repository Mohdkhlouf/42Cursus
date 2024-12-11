/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:41:20 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/12/04 15:17:20 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fix_line(char *line)
{
	ssize_t	i;
	char	*temp;

	i = 0;
	while ((line[i] != '\n') && (line[i] != '\0'))
		i++;
	if ((line[i] == 0) || (line[i + 1] == 0))
		return (NULL);
	temp = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!temp)
	{
		line[0] = 0;
		return (NULL);
	}
	if (*temp == 0)
	{
		free(temp);
		temp = NULL;
	}
	line[i + 1] = 0;
	return (temp);
}

char	*ft_read_line(int fd, char *buff, char *remainder, ssize_t read_letters)
{
	while (read_letters > 0)
	{
		read_letters = read(fd, buff, BUFFER_SIZE);
		if (read_letters == -1)
			return (free(remainder), NULL);
		else if (read_letters == 0)
			break ;
		buff[read_letters] = 0;
		if (!remainder)
			remainder = ft_strdup("");
		if (!remainder)
			break ;
		remainder = ft_strjoin(remainder, buff);
		if (!remainder)
			break ;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buff;
	char		*line;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(remainder);
		free(buff);
		remainder = NULL;
		buff = NULL;
		return (NULL);
	}
	line = ft_read_line(fd, buff, remainder, 1);
	free(buff);
	buff = NULL;
	if (!line)
		return (NULL);
	remainder = ft_fix_line(line);
	if (line[0] == 0)
		return (free(line), NULL);
	return (line);
}
