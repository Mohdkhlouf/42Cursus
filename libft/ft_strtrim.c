/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:09:07 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/11/11 20:06:26 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}

static int	left_count(char const *s1, char const *set)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (check(s1[i], set) == 1)
	{
		i++;
		counter++;
	}
	return (counter);
}

static int	right_count(char const *s1, char const *set)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	i = ft_strlen(s1);
	while (check(s1[i - 1], set) == 1)
	{
		counter++;
		i--;
	}
	return (counter);
}

char	*ft_strtrim(char const *s1, char const *set)
{	
	char	*newstr;
	int		start;
	int		end;
	size_t	i;

	start = 0;
	i = 0;
	end = 0;
	if (!*s1)
		return (ft_strdup(""));
	start = left_count(s1, set);
	end = right_count(s1, set);
	if (start - end < 0)
		return (ft_strdup(""));
	else
		{
			newstr = malloc(ft_strlen(s1) - start - end + 1);
			if (!newstr)
				return (NULL);
			
			while (i < (ft_strlen(s1) - start - end))
			{
				newstr[i] = s1[i + start];
				i++;
			}
		}
	newstr[i] = '\0';
	return (newstr);
}
int main(void)
{
	char * result = ft_strtrim(".....", ".");
	printf("%s", result);
	return (0);
}