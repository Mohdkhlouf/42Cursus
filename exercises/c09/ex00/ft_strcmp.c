/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mklouf@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:33:38 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/08/08 12:55:03 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
//#include <stdio.h>

int	ft_strcmp(char *s1, char *s2);

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && ((s1[i] != '\0') || (s2[i] != '\0')))
		i++;
	return (s1[i] - s2[i]);
}
/*
int main(void)
{
	int i;
	i=0;
	
	char s1[]="AA";
	char s2[]="AAAA";
	int result = ft_strcmp(s1, s2);
	printf("%d",result);
	return (0);
	}*/
