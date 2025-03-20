/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:02:18 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/20 13:35:00 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexing.h"

void double_quote_fixing(t_data *data, int i)
{
	int j;
	int c;
	char *temp;
	int len;

	j = 0;
	c = 0;
	len = ft_strlen(data->tokens[i].data);
	temp = malloc(sizeof(char) * len + 1);
	while(j < len)
	{
		if(data->tokens[i].data[j] == '\"')
			j++;
		else
		{
			temp[c] = data->tokens[i].data[j];
			c++;
			j++;
		}
			
	}
	free(data->tokens[i].data);
	data->tokens[i].data = ft_strdup(temp);
	free(temp);
}

void single_quote_fixing(t_data *data, int i)
{
	int j;
	int c;
	char *temp;
	int len;

	j = 0;
	c = 0;
	len = ft_strlen(data->tokens[i].data);
	temp = malloc(sizeof(char) * len + 1);
	while(j < len)
	{
		if(data->tokens[i].data[j] == '\'')
			j++;
		else
		{
			temp[c] = data->tokens[i].data[j];
			c++;
			j++;
		}
			
	}
	free(data->tokens[i].data);
	data->tokens[i].data = ft_strdup(temp);
	free(temp);
}

void tokenizing(t_data *data)
{
	int i;

	i = 0;
	while (data->tokens[i].data)
	{
		if(strchr(data->tokens[i].data, '\''))
			single_quote_fixing(data, i);
		else if(strchr(data->tokens[i].data, '\"'))
			double_quote_fixing(data, i);
		i++;
	}
	i = 0;
	while (i < data->tokens_conter)
	{
		printf("Token:#%s# Type:%u\n", data->tokens[i].data , data->tokens[i].type);
		i++;
	}
}
