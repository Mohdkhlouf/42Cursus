/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mklouf@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:02:30 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/08/15 18:19:24 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
//#include <stdio.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*str2;

	i = 0;
	str2 = malloc(sizeof (char) * ft_strlen (src) + 1);
	if (!(str2))
		return (NULL);
	while (src[i] != '\0')
	{
		str2[i] = src[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}
/*
int	main(void)
{
	char	*str = "Mohammad";

	printf(":%s:", ft_strdup(str));
	return (0);
}
*/
