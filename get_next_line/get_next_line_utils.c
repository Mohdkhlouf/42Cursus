/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:41:24 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/11/26 15:36:06 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	i;

	slen = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*joined_str;
	unsigned int	joined_str_len;
	unsigned int	i;
	unsigned int	j;

	joined_str_len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	joined_str = malloc((joined_str_len + 1) * sizeof(char));
	if (!joined_str)
		return (NULL);
	while (s1[i])
		joined_str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		joined_str[i++] = s2[j++];
	joined_str[i] = '\0';
	return (joined_str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}
char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[count])
		count++;
	ptr = (char *)malloc(count + 1);
	if (!ptr)
		return (NULL);
	while (i < count)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}