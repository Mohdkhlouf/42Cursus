/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:02:18 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/20 16:29:14 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexing.h"

void	assign_quotes(t_data *data, int len, int i, char *temp)
{
	int	c;
	int	j;

	c = 0;
	j = 0;
	if (data->tokens[i].data[0] == '\'' && data->tokens[i].data[len
		- 1] == '\'')
		data->quote_type = '\'';
	if (data->tokens[i].data[j] == '\"' && data->tokens[i].data[len
		- 1] == '\"')
		data->quote_type = '\"';
	while (j < len)
	{
		if (data->tokens[i].data[j] == data->quote_type
			|| (data->tokens[i].data[j] == '\'' && data->quote_type == 0)
				|| (data->tokens[i].data[j] == '\"' && data->quote_type == 0))
			j++;
		else
		{
			temp[c] = data->tokens[i].data[j];
			c++;
			j++;
		}
	}
	temp[c] = '\0';
}

void	quote_fixing(t_data *data, int i)
{
	char	*temp;
	int		len;

	len = ft_strlen(data->tokens[i].data);
	temp = malloc(sizeof(char) * len + 1);
	if (temp == NULL)
		exit(EXIT_FAILURE);
	assign_quotes(data, len, i, temp);
	free(data->tokens[i].data);
	data->tokens[i].data = ft_strdup(temp);
	free(temp);
}

void var_handler(t_data *data, int i)
{
	char *path;
	char *var;
	int len;

	len = ft_strlen(data->tokens[i].data);
	var = NULL;
	var = data->tokens[i].data;
	var = ft_memcpy(var, var +1, len -1);
	printf("var is:%s\n", var);

	path = getenv(var);
	if (path == NULL)
		exit(EXIT_FAILURE);
	else
		data->tokens[i].data = path;
}

void	tokenizing(t_data *data)
{
	int	i;

	i = 0;
	while (data->tokens[i].data)
	{
		if (ft_strchr(data->tokens[i].data, '\'')
				|| ft_strchr(data->tokens[i].data, '\"'))
		{
			quote_fixing(data, i);
		}
		if (ft_strchr(data->tokens[i].data, '$'))
			var_handler(data, i);
		i++;
	}	
	i = 0;
	while (i < data->tokens_conter)
	{
		printf("Token:#%s# Type:%u\n", data->tokens[i].data,
			data->tokens[i].type);
		i++;
	}
}
