/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mklouf@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:45:48 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/08/19 20:14:41 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
//#include <stdio.h>

int	str_len(int size, char **str)
{
	int	i;
	int	j;
	int	counter;

	counter = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			j++;
			counter++;
		}
		i++;
	}
	return (counter);
}

int	sep_len(char *sep)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
		i++;
	return (i);
}

char	*str_concat(int size, char **strs, char *sep, char *con_str)
{
	int	i;
	int	j;
	int	c;
	int	counter;

	i = 0;
	counter = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			con_str[counter++] = strs[i][j++];
		if (i < size - 1)
		{
			c = 0;
			while (sep[c] != '\0')
				con_str[counter++] = sep[c++];
		}
		i++;
	}
	con_str[counter] = '\0';
	return (con_str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	int		s_len;
	char	*con_str;

	if (size == 0)
	{
		con_str = malloc(1);
		if (con_str)
			con_str[0] = '\0';
		return (con_str);
	}
	len = str_len(size, strs);
	s_len = sep_len(sep);
	con_str = malloc(sizeof(char) * (len + (size - 1) * s_len + 1));
	if (!con_str)
		return (NULL);
	con_str = str_concat(size, strs, sep, con_str);
	return (con_str);
}
/*
int	main(void)
{
	int		size = 3;
	char	sep[] = "XXooXX";
	char	*strs[] = {"mohammaad", "ahmad", "Ali"};
	char	*result = ft_strjoin(size, strs, sep);
	printf("%s\n", result);
	free(result);
	return (0);
}
*/
