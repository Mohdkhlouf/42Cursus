/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:41:20 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/11/27 18:39:31 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fix_line(char *line, char **remainder)
{
	int		i;
	char	*temp1;

	i = 0;
	if (!line)
		return(NULL	);
	i = strchr(line, '\n') - line;
	if (i < 0)
		i = ft_strlen(line);
	temp1 = ft_substr(line, 0, i + 1);
	if (!temp1)
	{
		free(line);
		return (NULL);
	}
	free(*remainder);
	*remainder = ft_substr(line, i + 1, (ft_strlen(line) - i));
	// *remainder = ft_strdup(line + i);
	if (!*remainder)
	{
		free(line);
		free(temp1);
		// free(remainder);
		return (NULL);
	}
	free(line);
	return (temp1);
}

char	*read_line(int fd, char *line, char *buff)
{
	ssize_t	read_letters;
	char	*temp;

	read_letters = 1;
	line[0] = '\0';
	while (read_letters > 0)
	{
		read_letters = read(fd, buff, BUFFER_SIZE);
		
		buff[read_letters] = '\0';
		if(!buff)
			return (NULL);
		temp = ft_strjoin(line, buff);
		if(!temp)
			return (NULL);
		free(line);
		line = temp;
		
		if (!line)
		{
			free(buff);
			return (NULL);
		}
		
		if (strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (line);
}
char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	line = malloc(BUFFER_SIZE);
	if (!line)
	{
		free(buff);
		return (NULL);
	}
	line = read_line(fd, line, buff);
	if (!line)
		return (NULL);
	else
	{
		if (remainder != NULL)
			line = ft_strjoin(remainder, line);
		line = ft_fix_line(line, &remainder);
	}
	return (line);
}
int	main(void)
{
	int fd;
	char *line;
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		return (1);
	}
	
	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}