/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mklouf@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 09:54:50 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/08/15 15:03:40 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s2;
	*s2 = *s1;
	*s1 = temp;
}

void	ptstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i <= argc - 1)
	{
		while (i + j <= argc -1)
		{
			if (ft_strcmp(argv[i], argv[i + j]) > 0)
				ft_swap(&argv[i], &argv[i + j]);
			j++;
		}
		j = 1;
		i++;
	}
	j = 1;
	while (j <= argc -1)
	{
		ptstr(argv[j]);
		j++;
	}
	return (0);
}
