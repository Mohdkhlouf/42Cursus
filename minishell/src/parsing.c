/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:02:18 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/17 13:27:12 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	how_many_parts(t_data *data)
{
	int		counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (i < ft_strlen(data->cleaned_line))
	{
		if (data->cleaned_line[i] == ' ' || (data->cleaned_line[i] != ' '
				&& data->cleaned_line[i + 1] == '\0'))
			counter++;
		i++;
	}
	return (counter);
}

void	line_split(t_data *data)
{
	size_t	i;
	int		j;
	int		start;
	bool	skip;

	i = 0;
	j = 0;
	start = 0;
	skip = false;
	data->cline_parts = how_many_parts(data);
	if (data->cline_parts != 0)
		data->tokens = malloc(data->cline_parts * 2);
	else
	{
		printf("Error\n");
		// free
		exit(EXIT_FAILURE);
	}
	if (data->cline_parts == 1)
	{
		data->tokens[0].data = data->cleaned_line;
		return ;
	}
	while (data->cleaned_line[i])
	{
		if (data->cleaned_line[i] == '\'' || data->cleaned_line[i] == '\"')
		{
			if (skip == false)
			{
				start = i;
				skip = true;
			}
			else
				skip = false;
			
			if (skip == false)
			{
				data->tokens[j].data = ft_substr(data->cleaned_line, start, i
						- start + 1);
				printf("token #%s#\n", data->tokens[j].data);
				printf("j #%d#\n", j);
				j++;
			}
		}
		if ((data->cleaned_line[i] == ' ' || data->cleaned_line[i
				+ 1] == '\0') && !skip)
		{
			data->tokens[j].data = ft_substr(data->cleaned_line, start, i
					- start);
			start = i + 1;
			printf("token #%s#\n", data->tokens[j].data);
			printf("j #%d#\n", j);

			j++;
		}
		i++;
	}
}
