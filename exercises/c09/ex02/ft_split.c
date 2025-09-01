/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mklouf@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:27:09 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/08/22 14:21:15 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_char_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (char_separator(str[i + 1], charset) == 1
			&& char_separator(str[i], charset) == 0)
			words++;
		i++;
	}
	return (words);
}

void	ft_write_word(char *dest, char *from, char *charset)
{
	int	i;

	i = 0;
	while (char_separator(from[i], charset) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

void	ft_write_split(char **split, char *str, char *charset)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (char_separator(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (char_separator(str[i + j], charset) == 0)
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			ft_write_word(split[word], str + i, charset);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		words_count;

	word_count = ft_count_words(str, charset);
	split = (char **)malloc(sizeof (char *) * (words_count + 1));
	split[words_count] = 0;
	ft_write_split(split, str, charset);
	return (split);
}
