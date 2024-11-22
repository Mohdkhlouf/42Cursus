/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:41:20 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/11/22 16:53:56 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char * str_filling(char str2[], char str[])
{	static int i = 0;
	int j;

	j = 0;
	while (str[j] != '\0' || str[j] == EOF)
	{
		if(str[j] == '\0')
		{
			str2[i] = '\0';
		}
		str2[i] = str[j];
		i++;
		j++;
	}
	return (str2);
}


char * print_line(char str[])
{
	char *str2;
	
	str2 = malloc(strlen(str)+1);
	if(!str2)
		return (NULL);
	str_filling(str2, str);
	printf("%s\n",str2);
	return(str2);
}

char	*get_next_line(int fd)
{
	size_t	buffer_size = 20;
	char	str[buffer_size];

	while (read(fd, str, buffer_size))
	{
		print_line(str);
		break;
	}
	return (0);
}
int	main(void)
{
	int fd;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		return (1);
	}
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	close(fd);
	return (0);
}