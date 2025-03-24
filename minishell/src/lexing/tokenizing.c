/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:02:18 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/24 13:44:27 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexing.h"

void	assign_quotes(t_data *data, int len, int i, char *temp)
{
	int	c;
	int	j;

	c = 0;
	j = 0;
	
	while (j < len)
	{
		if (data->tokens[i].data[j] == '\'' && data->quote_type == 0)
			data->quote_type = '\'';
		if (data->tokens[i].data[j] == '\"' && data->quote_type == 0)
			data->quote_type = '\"';
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
	data->quote_type = 0;
	temp[c] = '\0';
}

void	quote_fixing(t_data *data, int i)
{
	char	*temp;
	int		len;
	if ( data->tokens[i].data[0] == '\'')
		data->tokens[i].type = TOK_SINGLE_QUOTE;
	else if (data->tokens[i].data[0] == '\"')
		data->tokens[i].type = TOK_DOUBLE_QUOTE;
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
	char *temp;
	int len;
	int j;
	
	j = 0;
	temp = NULL;
	var = NULL;
	path = NULL;
	len = ft_strlen(data->tokens[i].data);
	while (j < len)
	{
		if(data->tokens[i].data[j] == '/' || data->tokens[i].data[j] == '\'' || data->tokens[i].data[j] == '\"')
		{
			data->file_seperator_found = true;
			break;
		}
		j++;
	}
	
	if (data->file_seperator_found)
	{
		var = ft_substr(data->tokens[i].data, 0 , j);
		temp = ft_substr(data->tokens[i].data, j, len);
	}
	else
		var = data->tokens[i].data;
	ft_memcpy(var, var +1, ft_strlen(var) - 1);
	path = getenv(var);

	if (path == NULL)
		exit(EXIT_FAILURE);
	else
	{
		if (data->file_seperator_found)
			data->tokens[i].data = ft_strjoin(path,temp);
		else
			data->tokens[i].data = path;
		data->tokens[i].type = TOK_ENV_VAR;
	}
}

void	tokenizing(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->tokens_conter)
	{
		printf("token %s\n", data->tokens[i].data);
		if (ft_strchr(data->tokens[i].data, '$'))
			var_handler(data, i);
		if (ft_strchr(data->tokens[i].data, '\'')
				|| ft_strchr(data->tokens[i].data, '\"'))
		{
			quote_fixing(data, i);
		}
	
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
