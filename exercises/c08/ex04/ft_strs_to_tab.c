/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mklouf@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:55:36 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/08/21 15:37:18 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_str_len(char *str)
{
	int	j;

	j = 0;
	while (*str != '\0')
	{
		j++;
		str++;
	}
	return (j);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*str2;

	i = 0;
	str2 = malloc(sizeof (char) * ft_str_len (src) + 1);
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

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*str_arr;

	str_arr = malloc(sizeof (struct s_stock_str) * ac + 1);
	i = 0;
	while (i < ac)
	{
		str_arr[i].size = ft_str_len(av[i]);
		str_arr[i].str = av[i];
		str_arr[i].copy = ft_strdup(av[i]);
		i++;
	}
	str_arr[i].str = 0;
	return (str_arr);
}
/*
int main(void)
{
	struct s_stock_str *t_stock_str;
	
	int size = 3;
	char *strso[3] ={"mohammad","Ahmad","Ali"};
	t_stock_str = ft_strs_to_tab(size, strso);
	return (0);
}
*/
