/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:16:40 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/11/06 19:38:34 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
		return (0);
}
/*
int	main(void)
{
	int i;
	int flag;
	
	i = 0;
	flag = 1;
	char s[]= "aa1aa";
	
	while(s[i]){
		printf("%c", s[i]);
		if (ft_isalpha(s[i]) != 1)
			{flag = 0;
			break;}
		i++;
	}
	printf("\n%d", flag);
	return (0);
}
*/