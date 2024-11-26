/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:41:20 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/11/26 17:36:09 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fix_line(char *line, char **remainder)
{
	int		i;
	char	*temp1;

	i = 0;
	i = strchr(line, '\n') - line;
	temp1 = ft_substr(line, 0, i + 1);
	free(*remainder);
	*remainder = malloc(1);
	if (!*remainder)
		return (NULL);
	*remainder = ft_substr(line, i + 1, (ft_strlen(line) - i));
	free(line);
	line = temp1;
	return (line);
}

char *read_line(int fd)
{	
	
	char		*buff;
	int			read_letters;
	char 		*line;
	
	read_letters = 1;
	buff = malloc(BUFFER_SIZE + 1);
	line = malloc(BUFFER_SIZE + 1);
	
	while (read_letters > 0)
	{
		read_letters = read(fd, buff, BUFFER_SIZE);
		line = ft_strjoin(line, buff);
		if (strchr(buff, '\n'))
			break ;
	}
	return (line);
}
char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    	return (NULL);
	line = read_line(fd);
	printf("Line is :##%s\n",line);
	
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
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}