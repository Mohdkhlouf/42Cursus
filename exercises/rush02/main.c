/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mklouf@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:00:24 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/08/18 15:41:35 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct	s_number
{
	int		id;
	char	word[15];
};
char	*ft_strncpy(char *dest, char *src, unsigned int n);

int		ft_atoi(char *str);

void	str_store(char *str, struct s_number *test, int index)
{
	int		i;
	int		j;
	char	str2[20];
	char	str3[20];

	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != ':')
		str2[j++] = str[i++];
	str2[j] = '\0';
	if (str[i] == ':' || str[i] == ' ')
		i++;
	while (str[i] == ' ')
		i++;
	j = 0;
	while (str[i] != '\0' && str[i] != '\n')
		str3[j++] = str[i++];
	str3[j] = '\0';
	test[index].id = ft_atoi(str2);
	ft_strncpy(test[index].word, str3, sizeof(test[index].word) - 1);
	test[index].word[sizeof(test[index].word) - 1] = '\0';
}

int	main(void)
{
	char			str[50];
	struct s_number	test[30];
	int				count;
	FILE			*indect;

	count = 0;
	indect = fopen("dics/numbers.dict", "r");
	if (indect == NULL)
	{
		fprintf(stderr, "\nError opening file\n");
		exit(1);
	}
	while (fgets(str, sizeof(str), indect) != NULL && count < 30)
	{
		str_store(str, test, count);
		count++;
	}
	fclose(indect);
	return (0);
}
