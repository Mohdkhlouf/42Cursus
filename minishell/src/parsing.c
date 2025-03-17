/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:02:18 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/17 15:59:55 by mkhlouf          ###   ########.fr       */
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
		if (data->cleaned_line[i] == ' ' || (i == ft_strlen(data->cleaned_line)
				- 1))
			counter++;
		i++;
	}
	return (counter);
}

void	line_split(t_data *data)
{
	size_t	i;
	int		j;
	size_t	start;
	bool	skip;

	i = 0;
	j = 0;
	start = 0;
	skip = false;
	data->cline_parts = how_many_parts(data);
	if (data->cline_parts != 0)
	{
		data->tokens = malloc(sizeof(t_token) * data->cline_parts);
		if (!data->tokens)
		{
			printf("Error allocating memory for tokens\n");
			exit(EXIT_FAILURE);
		}
	}
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
	while (i < ft_strlen(data->cleaned_line))
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
				j++;
				start = i +1;
			}
		}
		else if ((data->cleaned_line[i] == ' ' || data->cleaned_line[i + 1] == '\0') && !skip)
        {
            if (i > start)
            {
                data->tokens[j].data = ft_substr(data->cleaned_line, start, i - start);
                j++;
            }
            start = i + 1; // Move start to the next non-space character
        }
        i++;
	}
	if (i > start)
    {
        data->tokens[j].data = ft_substr(data->cleaned_line, start, i - start);
    }
}

