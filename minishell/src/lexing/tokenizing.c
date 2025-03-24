/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:02:18 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/03/24 17:03:43 by mkhlouf          ###   ########.fr       */
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

	if (data->tokens[i].data[0] == '\'')
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

void	search_for_file_seperator(t_data *data, int i, int len, int *j)
{
	while (*j < len)
	{
		if (data->tokens[i].data[*j] == '/' || data->tokens[i].data[*j] == '\''
			|| data->tokens[i].data[*j] == '\"')
		{
			data->file_seperator_found = true;
			break ;
		}
		(*j)++;
	}
}

void	path_set_and_join(t_data *data, int i, char *temp, char *path)
{
	if (path == NULL)
		exit(EXIT_FAILURE);
	else
	{
		if (data->file_seperator_found)
			data->tokens[i].data = ft_strjoin(path, temp);
		else
			data->tokens[i].data = path;
		data->tokens[i].type = TOK_ENV_VAR;
	}
}

void	var_handler2(t_data *data, int i)
{
	char	*path;
	char	*var;
	char	*temp2;
	char	*temp;
	int		len;
	int		var_found;
	int		j;
	// continue here to expand the variable within double quotes.
	j = 0;
	temp = NULL;
	var = NULL;
	path = NULL;
	var_found = 0;
	len = ft_strlen(data->tokens[i].data);
	search_for_file_seperator(data, i, len, &j);
	if (data->file_seperator_found)
	{
		var = ft_substr(data->tokens[i].data, 0, j);
		temp = ft_substr(data->tokens[i].data, j, len);
	}
	else
		var = data->tokens[i].data;
	var_found = strchr(var, '$') - var;
	j = var_found;
	while (j < len)
	{
		if (var[j] == ' ')
			break ;
		j++;
	}
	// var = ft_substr(var, 0, var_found);
	temp2 = ft_substr(var, var_found, j);
	temp = ft_substr(var, j, len);
	printf("var %s\n", var);
	printf("tmp2 %s\n", temp2);
	printf("tmp %s\n", temp);
	
	// ft_memcpy(temp2, temp2 + 1, ft_strlen(temp2) - 1);
	path = getenv(temp2);
	path_set_and_join(data, i, temp, path);
}

void	var_handler(t_data *data, int i)
{
	char	*path;
	char	*var;
	char	*temp;
	int		len;
	int		j;

	j = 0;
	temp = NULL;
	var = NULL;
	path = NULL;
	len = ft_strlen(data->tokens[i].data);
	search_for_file_seperator(data, i, len, &j);
	if (data->file_seperator_found)
	{
		var = ft_substr(data->tokens[i].data, 0, j);
		temp = ft_substr(data->tokens[i].data, j, len);
	}
	else
		var = data->tokens[i].data;
	ft_memcpy(var, var + 1, ft_strlen(var) - 1);
	path = getenv(var);
	path_set_and_join(data, i, temp, path);
}

void	tokenizing(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->tokens_conter)
	{
		printf("token %s\n", data->tokens[i].data);
		if (ft_strchr(data->tokens[i].data, '$')
			&& data->tokens[i].data[0] != '\''
			&& data->tokens[i].data[0] != '\"')
			var_handler(data, i);
		if (ft_strchr(data->tokens[i].data, '\'')
				|| ft_strchr(data->tokens[i].data, '\"'))
		{
			quote_fixing(data, i);
		}
		if ((data->tokens[i].type == TOK_DOUBLE_QUOTE)
			&& ft_strchr(data->tokens[i].data, '$'))
			var_handler2(data, i);
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
